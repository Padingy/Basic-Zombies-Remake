// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombies/Game/ZombieSpawnPoint.h"

AZombieSpawnPoint::AZombieSpawnPoint()
{
	resetTime = 3.0f;
	isUsed = false;
	spawnZone = 0;
}

bool AZombieSpawnPoint::GetIsUsed()
{
	return isUsed;
}

void AZombieSpawnPoint::SetIsUsed(bool value)
{
	isUsed = value;
}

void AZombieSpawnPoint::StartCooldown()
{
	isUsed = true;

	GetWorld()->GetTimerManager().SetTimer(spawnPointTimerHandle, [this]()
	{
		isUsed = false;
	}, resetTime, false);
}

void AZombieSpawnPoint::EndCooldown()
{
	isUsed = false;
}

int32 AZombieSpawnPoint::GetZone()
{
	return spawnZone;
}

void AZombieSpawnPoint::SetZone(int32 newZone)
{
	spawnZone = newZone;
}
