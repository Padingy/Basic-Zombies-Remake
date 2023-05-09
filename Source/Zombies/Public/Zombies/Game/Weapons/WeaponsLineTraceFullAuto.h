// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Weapons/WeaponsLineTrace.h"
#include "WeaponsLineTraceFullAuto.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AWeaponsLineTraceFullAuto : public AWeaponsLineTrace
{
	GENERATED_BODY()
	
public:
	AWeaponsLineTraceFullAuto();

	virtual void Fire() override;
	virtual void EndFire() override;

protected:

	virtual void StartCooldown(float time) override;
	virtual void EndCooldown() override;

	FTimerHandle stopFiringTimerHandle;
};
