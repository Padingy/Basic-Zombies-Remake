// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/InteractablesBase.h"
#include "InteractablesWallBuyBase.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AInteractablesWallBuyBase : public AInteractablesBase
{
	GENERATED_BODY()
	
public:
	AInteractablesWallBuyBase();

	UPROPERTY(EditAnywhere, Category = "Weapon Settings")
		TSubclassOf<class AWeaponsBase> weaponType;

	UPROPERTY(EditAnywhere, Category = "Interact Settings")
		int32 ammoCost;

	virtual void OnInteract(AZombiesCharacter* interactingPlayer) override;

	virtual FString GetUIMessage(AZombiesCharacter* interactingPlayer) override;

protected:
	AWeaponsBase* CheckIfPlayerOwnsWeapon(TArray<AWeaponsBase*> weaponArray);
};
