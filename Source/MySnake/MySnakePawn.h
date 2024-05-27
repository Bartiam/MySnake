// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MySnakePawn.generated.h"

class UCameraComponent;
class ASnakeBaseActor;

UCLASS()
class MYSNAKE_API AMySnakePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMySnakePawn();

	UPROPERTY(BlueprintReadOnly)
	UCameraComponent* mainCamera;

	UPROPERTY(BlueprintReadWrite)
	ASnakeBaseActor* snakeActor;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASnakeBaseActor> snakeActorClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Creates a "snake" object and spawns it into the game world
	void CreateSnakeActor();

	// Responsible for the vertical control of the snake
	UFUNCTION()
	void HandlePlayerVerticalInput(float value);

	// Responsible for the horizontal control of the snake
	UFUNCTION()
	void HandlePlayerHorizontallInput(float value);
};
