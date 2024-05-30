// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GroundBase.generated.h"

class UStaticMeshComponent;
class AFoodBase;

UCLASS()
class MYSNAKE_API AGroundBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGroundBase();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* meshComponent;

	UPROPERTY(BlueprintReadWrite)
	AFoodBase* food;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFoodBase> foodClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Creating food in random coordinates of the world
	void CreateFoodInTheWorld(int count = 1);
};
