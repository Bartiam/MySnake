// Fill out your copyright notice in the Description page of Project Settings.


#include "AppleFoodBase.h"
#include "SnakeBaseActor.h"

// Sets default values
AAppleFoodBase::AAppleFoodBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAppleFoodBase::BeginPlay()
{
	Super::BeginPlay();
	CreateFoodInTheWorld();
}

// Called every frame
void AAppleFoodBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Inherited function from the interface for collision handling
void AAppleFoodBase::Interact(AActor* interactor, bool bIsHead)
{
	if (IsValid(interactor))
	{
		auto snake = Cast<ASnakeBaseActor>(interactor);
		if (IsValid(snake))
		{
			snake->AddSnakeElement();
			Destroy();
			CreateFoodInTheWorld();
		}
	}
}

void AAppleFoodBase::CreateFoodInTheWorld(int count)
{

}

