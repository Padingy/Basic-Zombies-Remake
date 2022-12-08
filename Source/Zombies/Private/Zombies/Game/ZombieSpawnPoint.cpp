// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombies/Game/ZombieSpawnPoint.h"

AZombieSpawnPoint::AZombieSpawnPoint()
{
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
