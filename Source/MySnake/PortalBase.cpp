// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalBase.h"
#include "AppleBase.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "SnakeBaseActor.h"
#include "BadAppleBase.h"

// Sets default values
APortalBase::APortalBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	portalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PortalMesh"));
}

// Called when the game starts or when spawned
void APortalBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APortalBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortalBase::Interact(AActor* interactor, bool bIsHead)
{
	if (IsValid(interactor))
	{
		auto snake = Cast<ASnakeBaseActor>(interactor);
		if (IsValid(snake))
		{
			if (snake->scores <= 150)
			{
				float temp = FMath::FRandRange(0.0f, 1.f);
				if (temp > 0.8f)
					SpawnApple(snake);
			}
			snake->Teleport();
		}
	}
}

void APortalBase::SpawnApple(AActor* snake)
{
	float temp = FMath::FRandRange(0.0f, 1.f);
	if (temp > 0.5f)
	{
		apple = GetWorld()->SpawnActor<AAppleBase>(appleClass, FTransform());
		apple->CreateFoodInTheWorld(snake);
	}
	else
	{
		badApple = GetWorld()->SpawnActor<ABadAppleBase>(badAppleClass, FTransform());
		badApple->CreateFoodInTheWorld(snake);
	}
}

