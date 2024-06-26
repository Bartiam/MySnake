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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Inherited function from the interface for collision handling
	virtual void Interact(AActor* interactor, bool bIsHead) override;

	// Creating food in random coordinates of the world
	void CreateFoodInTheWorld(AActor* interactor, int count = 1);
};
