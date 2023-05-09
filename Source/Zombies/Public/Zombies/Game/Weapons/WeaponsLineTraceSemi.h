// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Weapons/WeaponsLineTrace.h"
#include "WeaponsLineTraceSemi.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AWeaponsLineTraceSemi : public AWeaponsLineTrace
{
	GENERATED_BODY()
	
public:
	AWeaponsLineTraceSemi();

	virtual void Fire() override;

protected:

	virtual void StartCooldown(float time) override;
	virtual void EndCooldown() override;

};
