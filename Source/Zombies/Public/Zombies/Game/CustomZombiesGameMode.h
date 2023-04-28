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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	void SetPlayerSpawns();
	void SetZombieSpawns();

	UPROPERTY(EditAnywhere, Category = "Player Settings")
		TSubclassOf<class AZombiesCharacter> playerClass;

	UPROPERTY(EditAnywhere, Category = "Zombie Settings")
		TSubclassOf<class AZombieBase> zombieClass;

	TArray<class APlayerSpawnPoint*> PlayerSpawnPoints;
	TArray<class AZombieSpawnPoint*> ZombieSpawnPoints;
	bool playerSpawnsSet;

};
