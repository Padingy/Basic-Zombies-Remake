// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/InteractablesBase.h"
#include "MyInteractablesBase_DamagePlayer.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AMyInteractablesBase_DamagePlayer : public AInteractablesBase
{
	GENERATED_BODY()

public:
	AMyInteractablesBase_DamagePlayer();

	virtual void OnInteract(class AZombiesCharacter* interactingPlayer) override;

protected:
	UPROPERTY(EditAnywhere, Category = Settings)
		float damageAmount;
};
