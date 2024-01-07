// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombies/Game/ZombiesCustomGameState.h"

AZombiesCustomGameState::AZombiesCustomGameState()
{
	mobsKilledInRound = 0;
}

void AZombiesCustomGameState::IncrementMobsKilled(int32 increaseValue)
{
	mobsKilledInRound += increaseValue;
}

void AZombiesCustomGameState::SetMobsKilled(int32 newValue)
{
	mobsKilledInRound = newValue;
}

