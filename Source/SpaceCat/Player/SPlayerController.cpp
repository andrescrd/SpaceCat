// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerController.h"
#include "Components/InputComponent.h"
#include "SpaceCat/Characters/SCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "SpaceCat/Interfaces/SControllable.h"

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
    InputComponent->BindAction("Ship", EInputEvent::IE_Pressed, this, &ASPlayerController::Ship);
}

void ASPlayerController::MoveForward(float Value)
{

    if (GetCharacter()->Implements<USControllable>())
        Cast<ISControllable>(GetCharacter())->MoveForward(Value);
}

void ASPlayerController::MoveHorizontal(float Value)
{
    if (GetCharacter()->Implements<USControllable>())
        Cast<ISControllable>(GetCharacter())->MoveHorizontal(Value);
}

void ASPlayerController::Grab()
{
    if (GetCharacter()->Implements<USControllable>())
        Cast<ISControllable>(GetCharacter())->Grab();
}

void ASPlayerController::Ship()
{
    if (GetCharacter()->Implements<USControllable>())
        Cast<ISControllable>(GetCharacter())->Ship();
}
