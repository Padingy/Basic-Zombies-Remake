// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombies/Game/PlayerSpawnPoint.h"

APlayerSpawnPoint::APlayerSpawnPoint()
{
	isUsed = false;
}

bool APlayerSpawnPoint::GetIsUsed()
{
	return isUsed;
}

void APlayerSpawnPoint::SetIsUsed(bool value)
{
	isUsed = value;
}

void APlayerSpawnPoint::StartCooldown()
{
	isUsed = true;

	GetWorld()->GetTimerManager().SetTimer(spawnTimerHandle, [this]()
	{
		isUsed = false;
	}, 3.0f, false);
}
