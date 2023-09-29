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

	UPROPERTY(EditAnywhere, Category = "Spawning Settings")
		float resetTime;

	UPROPERTY(EditAnywhere, Category = "Spawning Settings")
		int32 spawnZone;

	bool isUsed;

public:
	bool GetIsUsed();
	void SetIsUsed(bool value);
	void TempSetIsUsed(bool value);
	int32 GetZone();
	void SetZone(int32 newZone);
};
