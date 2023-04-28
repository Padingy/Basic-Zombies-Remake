// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/InteractablesBase.h"
#include "WallBuyMP40.generated.h"

UCLASS()
class ZOMBIES_API AWallBuyMP40 : public AInteractablesBase
{
	GENERATED_BODY()

public:

	AWallBuyMP40();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Weapon Settings")
		TSubclassOf<class AWeaponsBase> weaponType;

public:

	
};
