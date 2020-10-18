// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceCat/Interfaces/SControllable.h"
#include "SCharacter.generated.h"

UCLASS()
class SPACECAT_API ASCharacter : public ACharacter, public ISControllable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent *CameraComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent *SpringComp;

	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void MoveForward(float Value) override;
	virtual void MoveHorizontal(float Value) override;
	virtual void Grab() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsMount;
};
