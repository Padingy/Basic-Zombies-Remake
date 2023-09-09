// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ZombiesCustomGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AZombiesCustomGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	AZombiesCustomGameMode();

	void StartNewRound(int32 newRound);
	void EndRound();

	void CheckRoundStatus();
	void DecreaseRemainingMobs(int32 decrementValue);

	UFUNCTION()
		int32 GetCurrentRound();

	UPROPERTY(BlueprintReadWrite)
		int32 currentRound;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	void SetPlayerSpawns();

	void StartSpawningMobs();

	UPROPERTY(EditAnywhere, Category = "Player Settings")
		TSubclassOf<class AZombiesCharacter> playerClass;

	UPROPERTY(EditAnywhere, Category = "Zombie Settings")
		TSubclassOf<class AZombieBase> zombieClass;

	TArray<class APlayerSpawnPoint*> PlayerSpawnPoints;
	TArray<class AZombieSpawnPoint*> ZombieSpawnPoints;
	bool playerSpawnsSet;

	int32 totalMobsInRound;
	int32 mobsLeftToSpawn;
	int32 numOfMobsSpawned;
	int32 mobsRemainingToKill;

	FTimerHandle spawningMobsTimerHandle;

	UPROPERTY(EditAnywhere, Category = Timers)
		float changingRoundTime;
};
