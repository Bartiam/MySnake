// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodBase.h"
#include "SnakeBaseActor.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"

// Sets default values
AFoodBase::AFoodBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	meshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	meshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
}

// Called when the game starts or when spawned
void AFoodBase::BeginPlay()
{
	Super::BeginPlay();
	setCountSectors();
}

// Called every frame
void AFoodBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Inherited function from the interface for collision handling
void AFoodBase::Interact(AActor* interactor, bool bIsHead)
{
	if (IsValid(interactor))
	{
		auto snake = Cast<ASnakeBaseActor>(interactor);
		if (IsValid(snake))
		{
			snake->AddSnakeElement();
			CreateFoodInTheWorld();
		}
	}
}

// Creating food in random coordinates of the world
void AFoodBase::CreateFoodInTheWorld(int count)
{
	for (int i = 0; i < count; ++i)
	{
		int temp = FMath::FRandRange(0, sectors.Num() - 1);
		SetActorLocation(sectors[temp]);
	}
}

void AFoodBase::setCountSectors()
{
	int indexSectorElement = 0;

	for (float i = minPositionX; i < maxPositionX; i += 60.f)
	{
		for (float j = minPositionY; j < maxPositionY; j += 60.f)
		{
			sectors.Add(FVector(i, j, 40.f));
			indexSectorElement++;
		}
	}
}

