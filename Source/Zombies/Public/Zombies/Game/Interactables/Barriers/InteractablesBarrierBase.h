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

protected:
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere)
		UAnimationAsset* openAnimation;
};
