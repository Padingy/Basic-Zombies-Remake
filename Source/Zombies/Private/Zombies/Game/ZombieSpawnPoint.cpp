// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombies/Game/ZombieSpawnPoint.h"

AZombieSpawnPoint::AZombieSpawnPoint()
{
	resetTime = 3.0f;
	isUsed = false;
}

bool AZombieSpawnPoint::GetIsUsed()
{
	return isUsed;
}

void AZombieSpawnPoint::SetIsUsed(bool value)
{
	isUsed = value;
}

void AZombieSpawnPoint::TempSetIsUsed(bool value)
{
	isUsed = value;

	FTimerHandle spawnPointTimerHandle;

	GetWorld()->GetTimerManager().SetTimer(spawnPointTimerHandle, [this, value]()
	{
		if (value == true)
		{
			isUsed = false;
		}
		else
		{
			isUsed = true;
		}

	}, resetTime, false);
}
