// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "ZombiesCustomGameState.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AZombiesCustomGameState : public AGameState
{
	GENERATED_BODY()

public:
	AZombiesCustomGameState();

public:

	UPROPERTY()
		int32 mobsKilledInRound;


	void IncrementMobsKilled(int32 increaseValue);
	void SetMobsKilled(int32 newValue);

};
