// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeBaseActor.h"
#include "SnakeElementBaseActor.h"
#include "Interactable.h"

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
	AddSnakeElement(4);
	SetActorTickInterval(stepIn);
}

// Called every frame
void ASnakeBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveSnake();
}

void ASnakeBaseActor::AddSnakeElement(int count)
{
	for (int i = 0; i < count; ++i)
	{
		FVector newLocation(snakeElements.Num() * padding, 0, 0);
		FTransform newTransform(newLocation);
		ASnakeElementBaseActor* newSnakeElem = GetWorld()->SpawnActor<ASnakeElementBaseActor>(snakeElementClass, newTransform);
		newSnakeElem->snakeOwner = this;
		int32 elemIndex = snakeElements.Add(newSnakeElem);
		if (elemIndex == 0)
		{
			newSnakeElem->setFirstElementType();
			newSnakeElem->setFirstElementType_Implementation();
		}
	}
}

void ASnakeBaseActor::MoveSnake()
{
	FVector movementVector(ForceInitToZero);

	switch (lastMovement)
	{
	case EMovement::UP:
		movementVector.X += padding;
		break;
	case EMovement::DOWN:
		movementVector.X -= padding;
		break;
	case EMovement::LEFT:
		movementVector.Y += padding;
		break;
	case EMovement::RIGHT:
		movementVector.Y -= padding;
		break;
	}

	snakeElements[0]->ToggleCollision();

	for (int i = snakeElements.Num() - 1; i > 0; --i)
	{
		auto currentELem = snakeElements[i];
		auto prevElem = snakeElements[i - 1];
		currentELem->SetActorLocation(prevElem->GetActorLocation());
	}

	snakeElements[0]->AddActorWorldOffset(movementVector);
	snakeElements[0]->ToggleCollision();
}

void ASnakeBaseActor::SnakeElementOverlap(ASnakeElementBaseActor* overlappedComp, AActor* other)
{
	if (IsValid(overlappedComp))
	{
		int32 indexElem;
		snakeElements.Find(overlappedComp, indexElem);
		bool bIsHead = indexElem == 0;
		IInteractable* interactableInterface = Cast<IInteractable>(other);
		if (interactableInterface)
		{
			interactableInterface->Interact(this, bIsHead);
		}
	}
}
