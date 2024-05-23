// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeBaseActor.h"
#include "SnakeElementBaseActor.h"

// Sets default values
ASnakeBaseActor::ASnakeBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	padding = 60.f;
}

// Called when the game starts or when spawned
void ASnakeBaseActor::BeginPlay()
{
	Super::BeginPlay();
	AddSnakeElements(4);
}

// Called every frame
void ASnakeBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASnakeBaseActor::AddSnakeElements(int count)
{
	for (int i = 0; i < count; ++i)
	{
		FVector newLocation(snakeElements.Num() * padding, 0, 0);
		FTransform newTransform(newLocation);
		auto snakeElem = GetWorld()->SpawnActor<ASnakeElementBaseActor>(snakeElementClass, newTransform);
		snakeElements.Add(snakeElem);
	}
}

