// Fill out your copyright notice in the Description page of Project Settings.

#include "SCharacter.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
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
	GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Green, FString::Printf(TEXT("Take something")));
}

void ASCharacter::Ship()
{
	if (CurrentInteractableActor != nullptr && CurrentInteractableActor->Implements<USInteractable>())
	{
		if (!bIsMount)
		{
			ISInteractable::Execute_StartIntaraction(CurrentInteractableActor, this);
			bIsMount = true;
			// SetActorEnableCollision(false);
		}
		else
		{
			ISInteractable::Execute_StopIntaraction(CurrentInteractableActor);
			bIsMount = false;
			// SetActorEnableCollision(true);
		}
	}
}