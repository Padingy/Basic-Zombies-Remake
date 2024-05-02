// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Perk_SpeedCola.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

APerk_SpeedCola::APerk_SpeedCola()
{
	name = TEXT("SpeedCola");
	reloadSpeedMultiplier = 1.5f;
}

void APerk_SpeedCola::UpdatePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetReloadSpeedModifier(zombiesCharacter->GetReloadSpeedMultiplier() * reloadSpeedMultiplier);
	}
}

void APerk_SpeedCola::RemovePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetReloadSpeedModifier(zombiesCharacter->GetReloadSpeedMultiplier() / reloadSpeedMultiplier);
	}
}
