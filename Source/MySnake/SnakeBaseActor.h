// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeBaseActor.generated.h"

class ASnakeElementBaseActor;

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

	UPROPERTY(EditDefaultsOnly)
	float stepIn;

	UPROPERTY(EditDefaultsOnly)
	float padding;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddSnakeElements(int count = 1);

	void MoveSnake();

};
