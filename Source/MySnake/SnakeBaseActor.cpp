// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeBaseActor.h"
#include "SnakeElementBaseActor.h"

// Sets default values
ASnakeBaseActor::ASnakeBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	padding = 60.f;
	lastMovement = EMovement::DOWN;
	stepIn = 0.5f;
}

// Called when the game starts or when spawned
void ASnakeBaseActor::BeginPlay()
{
	Super::BeginPlay();
	AddSnakeElements(5);
	SetActorTickInterval(stepIn);
}

// Called every frame
void ASnakeBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveSnake();
}

void ASnakeBaseActor::AddSnakeElements(int count)
{
	for (int i = 0; i < count; ++i)
	{
		FVector newLocation(snakeElements.Num() * padding, 0, 0);
		FTransform newTransform(newLocation);
		ASnakeElementBaseActor* newSnakeElem = GetWorld()->SpawnActor<ASnakeElementBaseActor>(snakeElementClass, newTransform);
		int32 elemIndex = snakeElements.Add(newSnakeElem);
		if (elemIndex == 0)
		{
			newSnakeElem->setFirstElementType();
		}
	}
}

void ASnakeBaseActor::MoveSnake()
{
	FVector movementVector(ForceInitToZero);
	float currentSpeed = padding;

	switch (lastMovement)
	{
	case EMovement::UP:
		movementVector.X += currentSpeed;
		break;
	case EMovement::DOWN:
		movementVector.X -= currentSpeed;
		break;
	case EMovement::LEFT:
		movementVector.Y += currentSpeed;
		break;
	case EMovement::RIGHT:
		movementVector.Y -= currentSpeed;
		break;
	}

	for (int i = snakeElements.Num() - 1; i > 0; --i)
	{
		auto currentELem = snakeElements[i];
		auto prevElem = snakeElements[i - 1];
		currentELem->SetActorLocation(prevElem->GetActorLocation());
	}

	snakeElements[0]->AddActorWorldOffset(movementVector);
}

