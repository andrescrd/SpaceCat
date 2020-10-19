// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceCat/Interfaces/SInteractable.h"
#include "SpaceCat/Base/SBaseCharacter.h"
#include "SShip.generated.h"

UCLASS()
class SPACECAT_API ASShip : public ASBaseCharacter, public ISInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Grab() override;
	virtual void Ship() override;

	virtual void StartIntaraction_Implementation(class AActor *CurrentActor) override;
	virtual void StopIntaraction_Implementation() override;
	virtual void Activate_Implementation(class AActor *Activator) override;
	virtual void Deactivate_Implementation(class AActor *Activator) override;
	virtual void SetActivatorActor_Implementation(class AActor *Activator) override;
	virtual class AActor *GetActivatorActor_Implementation() override;
};
