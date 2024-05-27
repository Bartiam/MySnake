// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeElementBaseActor.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "SnakeBaseActor.h"

// Sets default values
ASnakeElementBaseActor::ASnakeElementBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	meshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	meshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
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

void ASnakeElementBaseActor::setFirstElementType_Implementation()
{
	meshComponent->OnComponentBeginOverlap.AddDynamic(this, &ASnakeElementBaseActor::HandleBeginOverlap);
}

void ASnakeElementBaseActor::Interact(AActor* interactor, bool bIsHead)
{
	auto snake = Cast<ASnakeBaseActor>(interactor);
	if (IsValid(snake))
	{
		auto size = snake->snakeElements.Num();
		for (int i = 0; i < size; ++i)
		{
			snake->snakeElements.RemoveAt(i);
		}
		snake->Destroy();
	}
}

void ASnakeElementBaseActor::HandleBeginOverlap(UPrimitiveComponent* OverlappedComp,
	AActor* other, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep,
	const FHitResult& sweepResult)
{
	if (IsValid(snakeOwner))
	{
		snakeOwner->SnakeElementOverlap(this, other);
	}
}

void ASnakeElementBaseActor::ToggleCollision()
{
	if (meshComponent->GetCollisionEnabled() == ECollisionEnabled::NoCollision)
		meshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	else if (meshComponent->GetCollisionEnabled() == ECollisionEnabled::QueryOnly)
		meshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

