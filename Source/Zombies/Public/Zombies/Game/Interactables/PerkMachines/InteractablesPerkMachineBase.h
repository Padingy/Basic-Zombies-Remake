// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/InteractablesBase.h" 
#include "Zombies/Public/Components/PerkBase.h"
#include "InteractablesPerkMachineBase.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AInteractablesPerkMachineBase : public AInteractablesBase
{
	GENERATED_BODY()

public:
	AInteractablesPerkMachineBase();

	virtual void OnInteract(class AZombiesCharacter* interactingPlayer) override;

protected:

	UPROPERTY(EditAnywhere, Category = Config)
	TSubclassOf<class APerkBase> perkType;
	
};
