// Fill out your copyright notice in the Description page of Project Settings.

#include "SShip.h"
#include "SpaceCat/Interfaces/SControllable.h"

// Sets default values
ASShip::ASShip()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASShip::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASShip::Grab()
{
}

void ASShip::Ship() 
{
	if(ActivatoreActor && ActivatoreActor->Implements<USControllable>())
		Cast<ISControllable>(ActivatoreActor)->Ship();
}

void ASShip::SetActivatorActor_Implementation(class AActor *Activator)
{
	ActivatoreActor = Activator;
}

class AActor *ASShip::GetActivatorActor_Implementation()
{
	return ActivatoreActor;
}

void ASShip::StartIntaraction_Implementation(class AActor *CurrentActor)
{
}

void ASShip::StopIntaraction_Implementation()
{
}

void ASShip::Activate_Implementation(class AActor *Activator)
{
}

void ASShip::Deactivate_Implementation(class AActor *Activator)
{
}