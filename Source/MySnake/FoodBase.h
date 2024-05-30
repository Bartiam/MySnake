// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "FoodBase.generated.h"

class UStaticMeshComponent;

UCLASS()
class MYSNAKE_API AFoodBase : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodBase();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* meshComponent;

	UPROPERTY(EditDefaultsOnly)
	float minPositionX;
	UPROPERTY(EditDefaultsOnly)
	float minPositionY;
	UPROPERTY(EditDefaultsOnly)
	float maxPositionX;
	UPROPERTY(EditDefaultsOnly)
	float maxPositionY;

	UPROPERTY()
	TArray<FVector> sectors;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Inherited function from the interface for collision handling
	virtual void Interact(AActor* interactor, bool bIsHead) override;

	// Creating food in random coordinates of the world
	void CreateFoodInTheWorld(int count = 1);

	void setCountSectors();
};
