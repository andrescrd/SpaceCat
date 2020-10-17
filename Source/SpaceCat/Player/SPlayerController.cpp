// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerController.h"
#include "Components/InputComponent.h"
#include "SpaceCat/Characters/SCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"

ASPlayerController::ASPlayerController()
{
}

void ASPlayerController::BeginPlay()
{
    Super::BeginPlay();
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
    Cast<ASCharacter>(GetCharacter())->MoveForward(Value);
}

void ASPlayerController::MoveHorizontal(float Value)
{
    Cast<ASCharacter>(GetCharacter())->MoveHorizontal(Value);
}

void ASPlayerController::Grab()
{
    Cast<ASCharacter>(GetCharacter())->Grab();
}
