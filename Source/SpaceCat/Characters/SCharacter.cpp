// Fill out your copyright notice in the Description page of Project Settings.

#include "SCharacter.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SpaceCat/Characters/SShip.h"
#include "Engine.h"

// Sets default values
ASCharacter::ASCharacter()
{
	bIsMount = false;
	PrimaryActorTick.bCanEverTick = true;
}

void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASCharacter::Grab()
{
	if (CurrentInteractableActor != nullptr && CurrentInteractableActor->Implements<USInteractable>() && !CurrentInteractableActor->IsA(ASShip::StaticClass()) && !bIsMount)
	{
		GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Green, FString::Printf(TEXT("Take something")));
	}
}

void ASCharacter::Ship()
{
	if (CurrentInteractableActor != nullptr && CurrentInteractableActor->Implements<USInteractable>() && CurrentInteractableActor->IsA(ASShip::StaticClass()))
	{
		if (!bIsMount)
		{
			ISInteractable::Execute_StartIntaraction(CurrentInteractableActor, this);
			ISInteractable::Execute_SetActivatorActor(CurrentInteractableActor, this);
			bIsMount = true;

			GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		}
		else
		{
			ISInteractable::Execute_StopIntaraction(CurrentInteractableActor);
			bIsMount = false;
			GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);
		}
	}
}