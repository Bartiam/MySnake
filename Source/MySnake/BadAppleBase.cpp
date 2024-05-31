// Fill out your copyright notice in the Description page of Project Settings.


#include "BadAppleBase.h"
#include "SnakeBaseActor.h"

void ABadAppleBase::Interact(AActor* interactor, bool bIsHead)
{
	if (IsValid(interactor))
	{
		auto snake = Cast<ASnakeBaseActor>(interactor);
		if (IsValid(snake))
		{
			snake->ReducesTheSpeedSnake();
			Destroy();
		}
	}
}
