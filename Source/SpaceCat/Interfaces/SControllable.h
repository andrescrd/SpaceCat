// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SControllable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class USControllable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPACECAT_API ISControllable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void MoveForward(float Value);
	virtual void MoveHorizontal(float Value);
	virtual void Grab();
	virtual void Ship();
};
