// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MySnakeGameModeBase.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class MYSNAKE_API AMySnakeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UUserWidget> playerHUDClass;

	UPROPERTY()
	UUserWidget* scoreWidget;

public:
	// Creates a widget for displaying the number of points on the screen
	void CreatesWidgetForDisplaying();
};
