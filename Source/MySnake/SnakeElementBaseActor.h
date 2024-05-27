// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "SnakeElementBaseActor.generated.h"

class UStaticMeshComponent;
class ASnakeBaseActor;

UCLASS()
class MYSNAKE_API ASnakeElementBaseActor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnakeElementBaseActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* meshComponent;

	UPROPERTY()
	ASnakeBaseActor* snakeOwner;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
	void setFirstElementType();
	void setFirstElementType_Implementation();

	virtual void Interact(AActor* interactor, bool bIsHead) override;

	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* other, UPrimitiveComponent* otherComp,
		int32 otherBodyIndex,bool bFromSweep, const FHitResult &sweepResult);

	void ToggleCollision();
};
