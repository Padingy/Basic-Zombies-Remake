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
	totalMobsInRound = currentRound;
	mobsLeftToSpawn = totalMobsInRound; //(currentRound * 0.15) * 24 < Formula for normal COD zombies Zombies per round after round 10
	numOfMobsSpawned = 0;
	mobsRemainingToKill = totalMobsInRound;

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

	for (APlayerSpawnPoint* spawnPoint : PlayerSpawnPoints)
	{
		/*UE_LOG(LogTemp, Warning, TEXT("Player Spawn Points"))*/
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
		if (AZombieSpawnPoint* spawnPoint = Cast<AZombieSpawnPoint>(actor))
		{
			ZombieSpawnPoints.Add(spawnPoint);
		}
	}

	StartSpawningMobs();
	//for (AZombieSpawnPoint* spawnPoint : ZombieSpawnPoints)
	//{
	//	if (!spawnPoint->GetIsUsed()) //This needs to be removed when I add a timer for the Zombies to be spawned from with a Zombie limiter in the world
	//	{
	//		FVector spawnLocation = spawnPoint->GetActorLocation();
	//		if (AZombieBase* zombie = GetWorld()->SpawnActor<AZombieBase>(zombieClass, spawnLocation, FRotator::ZeroRotator))
	//		{
	//			spawnPoint->SetIsUsed(true);
	//		}
	//	}
	//}
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
	while (mobsLeftToSpawn > 0)
	{
		for (AZombieSpawnPoint* spawnPoint : ZombieSpawnPoints)
		{
			if (mobsLeftToSpawn > 0)
			{
				if (!spawnPoint->GetIsUsed()) //This needs to be removed when I add a timer for the Zombies to be spawned from with a Zombie limiter in the world
				{
					FVector spawnLocation = spawnPoint->GetActorLocation();
					if (AZombieBase* zombie = GetWorld()->SpawnActor<AZombieBase>(zombieClass, spawnLocation, FRotator::ZeroRotator))
					{
						spawnPoint->SetIsUsed(false);
						mobsLeftToSpawn--;
						numOfMobsSpawned++;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
}

void AZombiesCustomGameMode::StartNewRound(int32 newRound)
{
	UE_LOG(LogTemp, Warning, TEXT("Start new round"));
	int32 newRoundTemp = newRound;
	FTimerHandle changingRoundTimer;

	GetWorld()->GetTimerManager().SetTimer(changingRoundTimer, [this, newRound]()
	{
		currentRound = newRound;
		totalMobsInRound = currentRound + 1;
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

void AZombiesCustomGameMode::DecreaseRemainingMobs(int32 decrementValue)
{
	mobsRemainingToKill -= decrementValue;
}

int32 AZombiesCustomGameMode::GetCurrentRound()
{
	return currentRound;
}
