// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeBaseActor.generated.h"

class ASnakeElementBaseActor;
class AAppleBase;

UENUM()
enum class EMovement
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

UCLASS()
class MYSNAKE_API ASnakeBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnakeBaseActor();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASnakeElementBaseActor> snakeElementClass;

	UPROPERTY()
	TArray<ASnakeElementBaseActor*> snakeElements;

	UPROPERTY()
	EMovement lastMovement;

	UPROPERTY()
	float stepIn;

	UPROPERTY(EditDefaultsOnly)
	float padding;

	bool isSnakeCanMove;

	UPROPERTY(BlueprintReadWrite)
	int32 scores = 0;

	const int8 startCountSnakeElements = 4;


	// Variables for determining food spawn sectors
	UPROPERTY(EditDefaultsOnly)
	float minPositionX;
	UPROPERTY(EditDefaultsOnly)
	float minPositionY;
	UPROPERTY(EditDefaultsOnly)
	float maxPositionX;
	UPROPERTY(EditDefaultsOnly)
	float maxPositionY;

	float posZ = 40.f;

	UPROPERTY()
	TArray<FVector> sectors;
	// Variables for determining food spawn sectors

	AAppleBase* apple;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Adds a snake element to the array
	void AddSnakeElement(int count = 1);

	// Determines the movement of the snake
	void MoveSnake();

	// Checks for an element collision
	void SnakeElementOverlap(ASnakeElementBaseActor* overlappedComp, AActor* other);

	// The snake-destroying function
	void DestroyFullSnakeElements();

	// Sets the sectors of food appearance
	void setCountSectors();

	// Checks the number of points
	bool CheckNumberOfPoints();

	void IncreasesTheSpeedSnake();

	void ReducesTheSpeedSnake();

	void Teleport();
};
