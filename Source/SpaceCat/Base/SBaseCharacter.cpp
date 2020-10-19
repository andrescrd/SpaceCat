// Fill out your copyright notice in the Description page of Project Settings.

#include "SBaseCharacter.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine.h"

ASBaseCharacter::ASBaseCharacter()
{
	SpringComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringComp"));
	SpringComp->SetupAttachment(RootComponent);
	SpringComp->bEnableCameraLag = true;
	SpringComp->bEnableCameraRotationLag = true;
	SpringComp->CameraLagSpeed = 3.f;
	SpringComp->CameraRotationLagSpeed = 3.f;
	SpringComp->bDoCollisionTest = false;
	SpringComp->TargetArmLength = 1000.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringComp, USpringArmComponent::SocketName);

	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Z);
	GetCharacterMovement()->DefaultLandMovementMode = EMovementMode::MOVE_Flying;
}

void ASBaseCharacter::MoveForward(float Value)
{
	FVector Forward = GetActorForwardVector();
	AddMovementInput(Forward, Value, false);
}

void ASBaseCharacter::MoveHorizontal(float Value)
{
	FVector Right = GetActorRightVector();
	AddMovementInput(Right, Value, false);
}

void ASBaseCharacter::Grab() 
{
	
}

void ASBaseCharacter::Ship() 
{
	
}

void ASBaseCharacter::NotifyActorBeginOverlap(AActor *OtherActor)
{
	if (OtherActor && OtherActor != this && OtherActor->Implements<USInteractable>())
	{
		CurrentInteractableActor = OtherActor;
		ISInteractable::Execute_Activate(OtherActor, this);
	}
}

void ASBaseCharacter::NotifyActorEndOverlap(AActor *OtherActor)
{
	if (OtherActor && OtherActor != this && OtherActor ==  CurrentInteractableActor)
	{
			ISInteractable::Execute_Deactivate(OtherActor, this);
			CurrentInteractableActor = nullptr;
	}
}