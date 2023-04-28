// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/InteractablesBase.h"
#include "WallBuyM14.generated.h"

UCLASS()
class ZOMBIES_API AWallBuyM14 : public AInteractablesBase
{
	GENERATED_BODY()

public:

	AWallBuyM14();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Weapon Settings")
		TSubclassOf<class AWeaponsBase> weaponType;
		
public:
	
};
