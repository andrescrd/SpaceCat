// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceCat/Interfaces/SControllable.h"
#include "SpaceCat/Interfaces/SInteractable.h"
#include "SpaceCat/Interfaces/SPickable.h"
#include "SBaseCharacter.generated.h"

UCLASS(Abstract)
class SPACECAT_API ASBaseCharacter : public ACharacter, public ISControllable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASBaseCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class AActor *CurrentInteractableActor;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class AActor *CurrentPickedActor;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class AActor *ActivatoreActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent *CameraComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent *SpringComp;

public:	
	virtual void NotifyActorBeginOverlap(AActor *OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor *OtherActor) override;

	virtual void MoveForward(float Value) override;
	virtual void MoveHorizontal(float Value) override;

	virtual void Grab() override;
	virtual void Ship() override;
};
