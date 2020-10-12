// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerController.h"
#include "Components/InputComponent.h"
#include "SpaceCat/Characters/SCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"

ASPlayerController::ASPlayerController()
{
    bCanSpawn = true;
}

void ASPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (bCanSpawn && CharacterClass)
    {
        TArray<AActor *> Targets;
        UGameplayStatics::GetAllActorsOfClass(this, ATargetPoint::StaticClass(), Targets);

        if (Targets.Num() > 0)
        {
            for (int32 i = 0; i < Targets.Num(); i++)
            {
                FTransform SpawnTransform = Targets[i]->GetActorTransform();
                AActor *CharacterSpawned = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, CharacterClass, SpawnTransform, ESpawnActorCollisionHandlingMethod ::AdjustIfPossibleButAlwaysSpawn);
               AActor *ControllerSpawned = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, ASPlayerController::StaticClass(), SpawnTransform);

                CharacterSpawned->FinishSpawning(SpawnTransform);
                Characters.Add(Cast<ASCharacter>(CharacterSpawned));

                ASPlayerController *PC = Cast<ASPlayerController>(ControllerSpawned);
                PC->bCanSpawn = false;
                PC->Possess(Cast<APawn>(CharacterSpawned));
                Controllers.Add(PC);

                ControllerSpawned->FinishSpawning(SpawnTransform);
            }
        }
    }
}

void ASPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAxis("Forward", this, &ASPlayerController::MoveForward);
    InputComponent->BindAxis("Horizontal", this, &ASPlayerController::MoveHorizontal);
    InputComponent->BindAction("Grab", EInputEvent::IE_Pressed, this, &ASPlayerController::Grab);
}

void ASPlayerController::MoveForward(float Value)
{
    if (Characters.Num() > 0)
    {
        for (int32 i = 0; i < Characters.Num(); i++)
            Characters[i]->MoveForward(Value);
    }
}

void ASPlayerController::MoveHorizontal(float Value)
{
    if (Characters.Num() > 0)
    {
        for (int32 i = 0; i < Characters.Num(); i++)
            Characters[i]->MoveHorizontal(Value);
    }
}

void ASPlayerController::Grab()
{
    if (Characters.Num() > 0)
    {
        for (int32 i = 0; i < Characters.Num(); i++)
            Characters[i]->Grab();
    }
}
