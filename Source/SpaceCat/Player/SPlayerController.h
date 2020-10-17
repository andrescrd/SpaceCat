// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SPACECAT_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASPlayerController();

protected:
	virtual void SetupInputComponent() override;
	void MoveForward(float Value);
	void MoveHorizontal(float Value);
	void Grab();

public:
	virtual void BeginPlay() override;
};
