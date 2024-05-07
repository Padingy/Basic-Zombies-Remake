// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PerkBase.h"
#include "Perk_SpeedCola.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API APerk_SpeedCola : public APerkBase
{
	GENERATED_BODY()

public:
	APerk_SpeedCola();

	virtual void UpdatePerk(AActor* owner) override;

	virtual void RemovePerk(AActor* owner) override;


protected:
	float reloadSpeedMultiplier;
};
