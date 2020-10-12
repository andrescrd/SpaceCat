// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerController.h"
#include "Components/InputComponent.h"
#include "SpaceCat/Characters/SCharacter.h"

ASPlayerController::ASPlayerController()
{
    bCanSpawn = true;
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
    if(Characters.Num()>0){
        for (int32 i = 0; i < Characters.Num(); i++)
        {
            Characters[i]->MoveForwa
        }
        
    }
}

void ASPlayerController::MoveHorizontal(float Value) 
{
    
}

void ASPlayerController::Grab() 
{
    
}

void ASPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if(bCanSpawn)
    {

    }
}
