// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "ZombieSpawnPoint.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AZombieSpawnPoint : public ATargetPoint
{
	GENERATED_BODY()
	
public:
	AZombieSpawnPoint();

protected:
	bool isUsed;

public:
	bool GetIsUsed();
	void SetIsUsed(bool value);
};
