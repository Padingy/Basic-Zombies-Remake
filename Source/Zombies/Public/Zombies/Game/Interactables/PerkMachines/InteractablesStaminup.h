// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/InteractablesBase.h"
#include "InteractablesStaminup.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AInteractablesStaminup : public AInteractablesBase
{
	GENERATED_BODY()

public:
	AInteractablesStaminup();

	virtual void OnInteract(class AZombiesCharacter* interactingPlayer) override;

protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditAnywhere, Category = Config)
	float staminaMultiplier;
};
