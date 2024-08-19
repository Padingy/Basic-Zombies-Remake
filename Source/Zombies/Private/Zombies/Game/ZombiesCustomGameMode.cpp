// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombies/Game/ZombiesCustomGameMode.h"
#include "Zombies/Public/Zombies/Game/ZombiesCustomGameState.h"
#include "Zombies/Public/Zombies/Game/PlayerSpawnPoint.h"
#include "Zombies/Public/Zombies/Game/ZombieSpawnPoint.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Zombies/Public/Zombie/ZombieBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AZombiesCustomGameMode::AZombiesCustomGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/BlueprintClasses/Player/BP_ZombiesCharacter.BP_ZombiesCharacter_C"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	playerSpawnsSet = false;

	currentRound = 1;
	totalMobsInRound = 6;
	mobsLeftToSpawn = totalMobsInRound;
	numOfMobsSpawned = 0;
	mobsRemainingToKill = totalMobsInRound;
	healthOfZombies = 150;
	maxMobsSpawned = 6; //24 at Round 10
	mobsSpawnedPerIteration = 3;
	
	changingRoundTime = 3.0f;
}

void AZombiesCustomGameMode::BeginPlay()
{
	Super::BeginPlay();

}

void AZombiesCustomGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (playerSpawnsSet == false)
		SetPlayerSpawns();

	if (PlayerSpawnPoints.Num() != 0)
	{
		APlayerSpawnPoint* randPlayerSpawnPoint = PlayerSpawnPoints[FMath::RandRange(0, PlayerSpawnPoints.Num() - 1)];

		FVector SpawnLocation = randPlayerSpawnPoint->GetActorLocation();
		if (APawn* pawn = GetWorld()->SpawnActor<APawn>(playerClass, SpawnLocation, FRotator::ZeroRotator))
		{
			NewPlayer->Possess(pawn);
			randPlayerSpawnPoint->SetIsUsed(true);
		}
	}

	TArray<AActor*> tempZombieSpawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AZombieSpawnPoint::StaticClass(), tempZombieSpawns);
	for (AActor* actor : tempZombieSpawns)
	{
		if (AZombieSpawnPoint* spawnPoint = Cast<AZombieSpawnPoint>(actor))
		{
			if (spawnPoint->GetZone() == 0)
			{
				activeZombieSpawnPoints.Add(spawnPoint);
			}
			else
			{
				inactiveZombieSpawnPoints.Add(spawnPoint);
			}
		}
	}
	StartSpawningMobs();
}

void AZombiesCustomGameMode::SetPlayerSpawns()
{
	TArray<AActor*> tempPlayerSpawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerSpawnPoint::StaticClass(), tempPlayerSpawns);
	for (AActor* actor : tempPlayerSpawns)
	{
		if (APlayerSpawnPoint* spawnPoint = Cast<APlayerSpawnPoint>(actor))
		{
			PlayerSpawnPoints.Add(spawnPoint);
		}
	}
	playerSpawnsSet = true;
}

void AZombiesCustomGameMode::StartSpawningMobs()
{ 
	GetWorld()->GetTimerManager().SetTimer(spawningMobsTimerHandle, this, &AZombiesCustomGameMode::SpawningMobsTimer, 1.0f, true);
}

void AZombiesCustomGameMode::SpawningMobsTimer()
{
	if (mobsLeftToSpawn > 0 && numOfMobsSpawned < maxMobsSpawned)
	{
		int32 mobsToSpawn = FMath::Min(FMath::Min(maxMobsSpawned - numOfMobsSpawned, mobsSpawnedPerIteration), mobsLeftToSpawn);

		for (int i = 0; i < mobsToSpawn; i++)
		{
			AZombieSpawnPoint* randSpawnPoint = activeZombieSpawnPoints[FMath::RandRange(0, activeZombieSpawnPoints.Num() - 1)];

			if (randSpawnPoint && !randSpawnPoint->GetIsUsed())
			{
				FVector spawnLocation = randSpawnPoint->GetActorLocation();
				if (AZombieBase* zombie = GetWorld()->SpawnActor<AZombieBase>(zombieClass, spawnLocation, FRotator::ZeroRotator))
				{
					zombie->SetHealth(healthOfZombies);
					mobsLeftToSpawn--;
					numOfMobsSpawned++;

					randSpawnPoint->StartCooldown();
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (mobsLeftToSpawn <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(spawningMobsTimerHandle);
	}
}

void AZombiesCustomGameMode::StartNewRound(int32 newRound)
{
	int32 newRoundTemp = newRound;
	FTimerHandle changingRoundTimer;

	GetWorld()->GetTimerManager().SetTimer(changingRoundTimer, [this, newRound]()
	{
		currentRound = newRound;
		if (newRound <= 5)
		{
			totalMobsInRound += 5;
			healthOfZombies += 100;
			maxMobsSpawned += 2;
		}
		else if (newRound <= 10)
		{
			totalMobsInRound += 3;
			healthOfZombies += 100;
			maxMobsSpawned += 2;
		}
		else
		{
			totalMobsInRound = (currentRound * 0.15) * 24;
			healthOfZombies *= 1.1;
		}
		
		mobsRemainingToKill = totalMobsInRound;
		mobsLeftToSpawn = totalMobsInRound;

		StartSpawningMobs();
	}, changingRoundTime, false);

	numOfMobsSpawned = 0;
}

void AZombiesCustomGameMode::UpdateSpawnPoints(AInteractablesBarrierBase* zoneActivator)
{
	if (zoneActivator)
	{
		for (AZombieSpawnPoint* spawnPoint : inactiveZombieSpawnPoints)
		{
			if (spawnPoint->GetZone() == zoneActivator->GetSpawnZone1() || spawnPoint->GetZone() == zoneActivator->GetSpawnZone2())
			{
				activeZombieSpawnPoints.AddUnique(spawnPoint);
			}
		}
	}
}

void AZombiesCustomGameMode::CheckRoundStatus()
{
	if (mobsRemainingToKill <= 0)
	{
		StartNewRound(currentRound + 1);
	}
}

void AZombiesCustomGameMode::DecreaseRemainingMobs()
{
	mobsRemainingToKill -= 1;
	numOfMobsSpawned -= 1;
}

int32 AZombiesCustomGameMode::GetCurrentRound()
{
	return currentRound;
}
