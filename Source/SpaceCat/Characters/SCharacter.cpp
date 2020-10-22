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
	bIsPicking = false;
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
	if (CurrentPickedActor != nullptr && CurrentPickedActor->Implements<USInteractable>() && !bIsPicking)
	{
		GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Green, FString::Printf(TEXT("Take something")));
	}
}

void ASCharacter::Ship()
{
	if (CurrentInteractableActor != nullptr && CurrentInteractableActor->Implements<USInteractable>())
	{
		if (CurrentInteractableActor->IsA(ASShip::StaticClass()))
		{
			if (!bIsMount)
			{

				DoInteraction(CurrentInteractableActor);
				bIsMount = true;
				GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
			}
			else
			{
				StopInteraction(CurrentInteractableActor);
				bIsMount = false;
				GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
				GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);
			}
		}
		else
		{
			DoInteraction(CurrentInteractableActor);
		}
	}
}

void ASCharacter::DoInteraction(AActor *InteractableActor)
{
	ISInteractable::Execute_StartIntaraction(InteractableActor, this);
	ISInteractable::Execute_SetActivatorActor(InteractableActor, this);
}

void ASCharacter::StopInteraction(class AActor *InteractableActor)
{
	ISInteractable::Execute_StopIntaraction(InteractableActor);
}