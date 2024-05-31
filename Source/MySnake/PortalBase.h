// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "PortalBase.generated.h"

class AAppleBase;
class UStaticMeshComponent;
class ABadAppleBase;

UCLASS()
class MYSNAKE_API APortalBase : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortalBase();

	UPROPERTY(BlueprintReadWrite)
	AAppleBase* apple;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AAppleBase> appleClass;

	UPROPERTY(BlueprintReadWrite)
	ABadAppleBase* badApple;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABadAppleBase> badAppleClass;

	UPROPERTY(EditDefaultsOnly ,BlueprintReadWrite)
	UStaticMeshComponent* portalMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Inherited function from the interface for collision handling
	virtual void Interact(AActor* interactor, bool bIsHead) override;

	void SpawnApple(AActor* snake);
};
