// Fill out your copyright notice in the Description page of Project Settings.


#include "GroundBase.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "FoodBase.h"

// Sets default values
AGroundBase::AGroundBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ground"));
}

// Called when the game starts or when spawned
void AGroundBase::BeginPlay()
{
	Super::BeginPlay();
	CreateFoodInTheWorld(10);
}

// Called every frame
void AGroundBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGroundBase::CreateFoodInTheWorld(int count)
{
	for (int i = 0; i < count; ++i)
	{
		float randomLocationX = FMath::FRandRange(-270.f, 270.f);
		float randomLocationY = FMath::FRandRange(-570.f, 570.f);
		FVector location(randomLocationX, randomLocationY, 40);
		food = GetWorld()->SpawnActor<AFoodBase>(foodClass, FTransform(location));
	}
}

