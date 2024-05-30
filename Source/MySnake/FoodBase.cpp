// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodBase.h"
#include "SnakeBaseActor.h"
#include "GroundBase.h"

// Sets default values
AFoodBase::AFoodBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFoodBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFoodBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Inherited function from the interface for collision handling

// Inherited function from the interface for collision handling
void AFoodBase::Interact(AActor* interactor, bool bIsHead)
{
	if (IsValid(interactor))
	{
		auto snake = Cast<ASnakeBaseActor>(interactor);
		if (IsValid(snake))
		{
			snake->AddSnakeElement();
			Destroy();
		}
	}
}


