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
	totalMobsInRound = currentRound * 8;
	mobsLeftToSpawn = totalMobsInRound; //(currentRound * 0.15) * 24 < Formula for normal COD zombies Zombies per round after round 10
	numOfMobsSpawned = 0;
	mobsRemainingToKill = totalMobsInRound;
	maxMobsSpawned = 5;
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

	/*if (PlayerSpawnPoints.Num() > 0)
	{
		int32 randPlayerSpawnPoint = FMath::RandRange(0, PlayerSpawnPoints.Num() - 1);

		APlayerSpawnPoint* spawnPoint = PlayerSpawnPoints[randPlayerSpawnPoint];

		if (!spawnPoint->GetIsUsed())
		{
			FVector SpawnLocation = spawnPoint->GetActorLocation();
			if (APawn* pawn = GetWorld()->SpawnActor<APawn>(playerClass, SpawnLocation, FRotator::ZeroRotator))
			{

				NewPlayer->Possess(pawn);
				spawnPoint->SetIsUsed(true);
			}
		}
	}*/

	/*APlayerSpawnPoint* randPlayerSpawnPoint = PlayerSpawnPoints[FMath::RandRange(0, PlayerSpawnPoints.Num() - 1)];
	if (!randPlayerSpawnPoint->GetIsUsed())
	{
		FVector SpawnLocation = randPlayerSpawnPoint->GetActorLocation();
		if (APawn* pawn = GetWorld()->SpawnActor<APawn>(playerClass, SpawnLocation, FRotator::ZeroRotator))
		{

			NewPlayer->Possess(pawn);
			randPlayerSpawnPoint->SetIsUsed(true);
		}
	}*/


	for (APlayerSpawnPoint* spawnPoint : PlayerSpawnPoints)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Spawn Points")); 
		if (!spawnPoint->GetIsUsed())
		{
			FVector SpawnLocation = spawnPoint->GetActorLocation();
			if (APawn* pawn = GetWorld()->SpawnActor<APawn>(playerClass, SpawnLocation, FRotator::ZeroRotator))
			{

				NewPlayer->Possess(pawn);
				spawnPoint->SetIsUsed(true);
			}
		}
	}

	TArray<AActor*> tempZombieSpawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AZombieSpawnPoint::StaticClass(), tempZombieSpawns);
	for (AActor* actor : tempZombieSpawns)
	{
		UE_LOG(LogTemp, Warning, TEXT("Zombie Spawn Points")); 
		if (AZombieSpawnPoint* spawnPoint = Cast<AZombieSpawnPoint>(actor))
		{
			ZombieSpawnPoints.Add(spawnPoint);
			if (spawnPoint->GetZone() == 0)
			{
				activeZombieSpawnPoints.Add(spawnPoint);
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

	activeZombieSpawnPoints[0]->StartCooldown();
	activeZombieSpawnPoints[1]->StartCooldown();
	GetWorld()->GetTimerManager().SetTimer(spawningMobsTimerHandle, [this]()
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
						mobsLeftToSpawn--;
						numOfMobsSpawned++;

						//randSpawnPoint->StartCooldown(); //Got to find a way to have this cooldown without it crashing
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

	}, 1.0f, true);

}

void AZombiesCustomGameMode::StartNewRound(int32 newRound)
{
	UE_LOG(LogTemp, Warning, TEXT("Start new round"));
	int32 newRoundTemp = newRound;
	FTimerHandle changingRoundTimer;

	GetWorld()->GetTimerManager().SetTimer(changingRoundTimer, [this, newRound]()
	{
		currentRound = newRound;
		totalMobsInRound = currentRound * 8;
		mobsRemainingToKill = totalMobsInRound;
		mobsLeftToSpawn = totalMobsInRound;

		StartSpawningMobs();
	}, changingRoundTime, false);

	UE_LOG(LogTemp, Warning, TEXT("CurrentRound: %d"), currentRound);
	
	numOfMobsSpawned = 0;
}

void AZombiesCustomGameMode::EndRound()
{
	UE_LOG(LogTemp, Warning, TEXT("Temp"));
}

void AZombiesCustomGameMode::UpdateSpawnPoints(AInteractablesBarrierBase* zoneActivator)
{
	if (zoneActivator)
	{
		for (AZombieSpawnPoint* spawnPoint : ZombieSpawnPoints)
		{
			if (spawnPoint->GetZone() == zoneActivator->GetSpawnZone1() || spawnPoint->GetZone() == zoneActivator->GetSpawnZone2())
			{
				activeZombieSpawnPoints.AddUnique(spawnPoint);
			}
		}
	}
}

void AZombiesCustomGameMode::CheckRoundStatus() //Check if MobsKilled == TotalMobsInRound to satart a new round
{
	UE_LOG(LogTemp, Warning, TEXT("Mobs remaining to kill: %d"), mobsRemainingToKill);
	if (mobsRemainingToKill <= 0)
	{
		StartNewRound(currentRound + 1);
	}

	//if (mobsLeftToSpawn >= 0)
	//{

	//}
	//else //No Mobs left to spawn in  current round
	//{
	//	if (mobsRemainingToKill <= 0)
	//	{
	//		StartNewRound(currentRound + 1);
	//	}
	//}
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
