// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Weapons/WeaponsBase.h"
#include "WeaponsLineTrace.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AWeaponsLineTrace : public AWeaponsBase
{
	GENERATED_BODY()

public:
	AWeaponsLineTrace();
	
	virtual void Fire() override;

	TArray<FHitResult> PerformLineTrace(float distance);
};
