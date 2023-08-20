// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CustomZombiesGameMode.generated.h"

UCLASS()
class ZOMBIES_API ACustomZombiesGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACustomZombiesGameMode();

	void StartRound(int32 newRound);
	void EndRound();

	void CheckRoundStatus();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	void SetPlayerSpawns();

	UPROPERTY(EditAnywhere, Category = "Player Settings")
		TSubclassOf<class AZombiesCharacter> playerClass;

	UPROPERTY(EditAnywhere, Category = "Zombie Settings")
		TSubclassOf<class AZombieBase> zombieClass;

	TArray<class APlayerSpawnPoint*> PlayerSpawnPoints;
	TArray<class AZombieSpawnPoint*> ZombieSpawnPoints;
	bool playerSpawnsSet;

	int32 currentRound;
	int32 totalMobsInRound;
	uint32_t mobsLeftToSpawn;
	int32 numOfMobsSpawned;
};
