// Fill out your copyright notice in the Description page of Project Settings.

#include "SCharacter.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine.h"

// Sets default values
ASCharacter::ASCharacter()
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

	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// void ASCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
// {
// 	Super::SetupPlayerInputComponent(PlayerInputComponent);
// }

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
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, FString::Printf(TEXT("Grab")));
}