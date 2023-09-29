// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/InteractablesBase.h"
#include "InteractablesBarrierBase.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AInteractablesBarrierBase : public AInteractablesBase
{
	GENERATED_BODY()
	
public:
	AInteractablesBarrierBase();

	virtual void OnInteract(class AZombiesCharacter* interactingPlayer) override;

	void HandleAnimNotify();

	void ChangeOpacityValue(float changeValue);

	int32 GetZone1();
	int32 GetZone2();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Spawning Settings")
		int32 spawnZone1;

	UPROPERTY(EditAnywhere, Category = "Spawning Settings")
		int32 spawnZone2;

	UPROPERTY(EditAnywhere)
		UAnimationAsset* openAnimation;
};
