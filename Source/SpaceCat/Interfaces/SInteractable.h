// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SInteractable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPACECAT_API ISInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetActivatorActor(class AActor *Activator);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	class AActor *GetActivatorActor();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Activate(class AActor *Activator);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Deactivate(class AActor *Activator);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartIntaraction(class AActor *CurrentActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StopIntaraction();
};
