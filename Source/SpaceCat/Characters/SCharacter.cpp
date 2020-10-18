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

void ASCharacter::MoveForward(float Value)
{
	FVector Forward = GetActorForwardVector();
	AddMovementInput(Forward, Value, false);
}

void ASCharacter::MoveHorizontal(float Value)
{
	FVector Right = GetActorRightVector();
	AddMovementInput(Right, Value, false);
}

void ASCharacter::Grab()
{
	GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Green, FString::Printf(TEXT("Take something")));
}

void ASCharacter::Ship()
{
	if (CurrentInteractableActor != nullptr && CurrentInteractableActor->Implements<USInteractable>())
	{
		bIsMount = true;
		SetActorEnableCollision(false);
		ISInteractable::Execute_StartIntaraction(CurrentInteractableActor, this);
	}
	else
	{
		bIsMount = false;
		SetActorEnableCollision(true);
	}
}

void ASCharacter::NotifyActorBeginOverlap(AActor *OtherActor)
{
	if (OtherActor && OtherActor->Implements<USInteractable>() && !bIsMount)
		CurrentInteractableActor = OtherActor;
}

void ASCharacter::NotifyActorEndOverlap(AActor *OtherActor)
{
	if (CurrentInteractableActor && CurrentInteractableActor->Implements<USInteractable>() && !bIsMount)
		CurrentInteractableActor = nullptr;
}

void ASCharacter::StartIntaraction_Implementation(class AActor *CurrentActor)
{
}

void ASCharacter::StopIntaraction_Implementation()
{
}
