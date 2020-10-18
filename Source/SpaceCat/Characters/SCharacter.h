// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceCat/Interfaces/SControllable.h"
#include "SpaceCat/Interfaces/SInteractable.h"
#include "SCharacter.generated.h"

UCLASS()
class SPACECAT_API ASCharacter : public ACharacter, public ISControllable, public ISInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	class AActor *CurrentInteractableActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent *CameraComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent *SpringComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsMount;

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor *OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor *OtherActor) override;

	virtual void MoveForward(float Value) override;
	virtual void MoveHorizontal(float Value) override;
	virtual void Grab() override;
	virtual void Ship() override;

	virtual void StartIntaraction_Implementation(class AActor *CurrentActor) override;
	virtual void StopIntaraction_Implementation() override;

};
