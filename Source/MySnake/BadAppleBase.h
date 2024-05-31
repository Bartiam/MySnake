// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FoodBase.h"
#include "BadAppleBase.generated.h"

/**
 * 
 */
UCLASS()
class MYSNAKE_API ABadAppleBase : public AFoodBase
{
	GENERATED_BODY()
	
public:
	// Inherited function from the interface for collision handling
	virtual void Interact(AActor* interactor, bool bIsHead) override;
};
