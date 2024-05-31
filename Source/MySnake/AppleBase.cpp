// Fill out your copyright notice in the Description page of Project Settings.


#include "AppleBase.h"
#include "SnakeBaseActor.h"

void AAppleBase::Interact(AActor* interactor, bool bIsHead)
{
	if (IsValid(interactor))
	{
		auto snake = Cast<ASnakeBaseActor>(interactor);
		if (IsValid(snake))
		{
			snake->IncreasesTheSpeedSnake();
			Destroy();
		}
	}
}
