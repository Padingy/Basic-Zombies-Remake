// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombies/Game/CustomZombiesGameMode.h"
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
	UE_LOG(LogTemp, Warning, TEXT("Zombie Spawn Points: %d"), ZombieSpawnPoints.Num());


	
	for (AZombieSpawnPoint* spawnPoint : ZombieSpawnPoints)
	{
		if (!spawnPoint->GetIsUsed()) //This needs to be removed when I add a timer for the Zombies to be spawned from with a Zombie limiter in the world
		{
			FVector spawnLocation = spawnPoint->GetActorLocation();
			if (AZombieBase* zombie = GetWorld()->SpawnActor<AZombieBase>(zombieClass, spawnLocation, FRotator::ZeroRotator))
			{
				spawnPoint->SetIsUsed(true);
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

void ACustomZombiesGameMode::SetZombieSpawns()
{
	
}
