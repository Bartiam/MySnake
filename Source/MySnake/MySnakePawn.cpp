// Fill out your copyright notice in the Description page of Project Settings.


#include "MySnakePawn.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "SnakeBaseActor.h"
#include "Components/InputComponent.h"

// Sets default values
AMySnakePawn::AMySnakePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	RootComponent = mainCamera;
}

// Called when the game starts or when spawned
void AMySnakePawn::BeginPlay()
{
	Super::BeginPlay();
	mainCamera->SetWorldRotation(FRotator(-90, 0, 0));
	CreateSnakeActor();
}

// Called every frame
void AMySnakePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMySnakePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Vertical", this, &AMySnakePawn::HandlePlayerVerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &AMySnakePawn::HandlePlayerHorizontallInput);
}

// Creates a "snake" object and spawns it into the game world
void AMySnakePawn::CreateSnakeActor()
{
	snakeActor = GetWorld()->SpawnActor<ASnakeBaseActor>(snakeActorClass, FTransform());
}

// Responsible for the vertical control of the snake
void AMySnakePawn::HandlePlayerVerticalInput(float value)
{
	if (IsValid(snakeActor)) {
		if (value > 0 && snakeActor->lastMovement != EMovement::DOWN && snakeActor->isSnakeCanMove == true)
		{
			snakeActor->lastMovement = EMovement::UP;
			snakeActor->isSnakeCanMove = false;
		}

		else if (value < 0 && snakeActor->lastMovement != EMovement::UP && snakeActor->isSnakeCanMove == true)
		{
			snakeActor->lastMovement = EMovement::DOWN;
			snakeActor->isSnakeCanMove = false;
		}
	}
}

// Responsible for the horizontal control of the snake
void AMySnakePawn::HandlePlayerHorizontallInput(float value)
{
	if (IsValid(snakeActor)) {
		if (value > 0 && snakeActor->lastMovement != EMovement::LEFT && snakeActor->isSnakeCanMove == true)
		{
			snakeActor->lastMovement = EMovement::RIGHT;
			snakeActor->isSnakeCanMove = false;
		}

		else if (value < 0 && snakeActor->lastMovement != EMovement::RIGHT && snakeActor->isSnakeCanMove == true)
		{
			snakeActor->lastMovement = EMovement::LEFT;
			snakeActor->isSnakeCanMove = false;
		}
	}
}