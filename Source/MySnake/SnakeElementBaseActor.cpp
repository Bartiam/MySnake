// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeElementBaseActor.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"

// Sets default values
ASnakeElementBaseActor::ASnakeElementBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
}

// Called when the game starts or when spawned
void ASnakeElementBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASnakeElementBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

