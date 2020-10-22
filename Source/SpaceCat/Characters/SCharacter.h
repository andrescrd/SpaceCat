// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceCat/Interfaces/SControllable.h"
#include "SpaceCat/Interfaces/SInteractable.h"
#include "SpaceCat/Base/SBaseCharacter.h"
#include "SCharacter.generated.h"

UCLASS()
class SPACECAT_API ASCharacter : public ASBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsMount;
	bool bIsPicking;

	virtual void BeginPlay() override;

	void DoInteraction(class AActor *InteractableActor);
	void StopInteraction(class AActor *InteractableActor);

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Grab() override;
	virtual void Ship() override;
};
