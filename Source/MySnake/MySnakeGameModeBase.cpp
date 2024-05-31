// Copyright Epic Games, Inc. All Rights Reserved.


#include "MySnakeGameModeBase.h"
#include "Blueprint/UserWidget.h"

void AMySnakeGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	CreatesWidgetForDisplaying();
}

// Creates a widget for displaying the number of points on the screen
void AMySnakeGameModeBase::CreatesWidgetForDisplaying()
{
	scoreWidget = CreateWidget<UUserWidget>(GetWorld(), playerHUDClass);
	if (scoreWidget != nullptr)
		scoreWidget->AddToViewport();
}
