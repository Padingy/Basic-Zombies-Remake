// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombies/Game/CustomZombiesGameMode.h"
#include "Zombies/Public/Zombies/Game/ZombiesCustomGameState.h"
#include "Zombies/Public/Zombies/Game/PlayerSpawnPoint.h"
#include "Zombies/Public/Zombies/Game/ZombieSpawnPoint.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Zombies/Public/Zombie/ZombieBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

ACustomZombiesGameMode::ACustomZombiesGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/BlueprintClasses/Player/BP_ZombiesCharacter.BP_ZombiesCharacter_C"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	playerSpawnsSet = false;

	currentRound = 1;
	totalMobsInRound = currentRound * 8;
	mobsLeftToSpawn = currentRound * 8; //(currentRound * 0.15) * 24 < Formula for normal COD zombies Zombies per round after round 10
	numOfMobsSpawned = 0;
}

void ACustomZombiesGameMode::BeginPlay()
{
	Super::BeginPlay();

	
}

void ACustomZombiesGameMode::PostLogin(APlayerController* NewPlayer)
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

	for (AZombieSpawnPoint* spawnPoint : ZombieSpawnPoints)
	{
		if (!spawnPoint->GetIsUsed()) //This needs to be removed when I add a timer for the Zombies to be spawned from with a Zombie limiter in the world
		{
			FVector spawnLocation = spawnPoint->GetActorLocation();
			if (AZombieBase* zombie = GetWorld()->SpawnActor<AZombieBase>(zombieClass, spawnLocation, FRotator::ZeroRotator))
			{
				spawnPoint->SetIsUsed(true);
				UE_LOG(LogTemp, Warning, TEXT("PostLogin spawn zombie stuff"));
			}
		}
	}
}

void ACustomZombiesGameMode::SetPlayerSpawns()
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

void ACustomZombiesGameMode::StartRound(int32 newRound)
{
	currentRound = newRound;
	totalMobsInRound = currentRound * 8;
	mobsLeftToSpawn = totalMobsInRound;
	numOfMobsSpawned = 0;

	UE_LOG(LogTemp, Warning, TEXT("Current Round: %d"), currentRound);
}

void ACustomZombiesGameMode::EndRound()
{
	UE_LOG(LogTemp, Warning, TEXT("Temp"));
}

void ACustomZombiesGameMode::CheckRoundStatus() //Check if MobsKilled == TotalMobsInRound to start a new round
{
	AZombiesCustomGameState* const gameState = Cast<AZombiesCustomGameState>(GameState);
	
	if (mobsLeftToSpawn >= 0)
	{

	}
	else //No Mobs left to spawn in  current round
	{
		if (gameState->mobsKilledInRound >= totalMobsInRound)
		{
			StartRound(currentRound + 1);
		}
	}
}
