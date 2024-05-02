// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Perk_DoubleTap.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

class AWeaponsBase;

APerk_DoubleTap::APerk_DoubleTap()
{
	name = TEXT("DoubleTap");
}

void APerk_DoubleTap::UpdatePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetRayPerShotMultiplier(zombiesCharacter->GetRayPerShotMultiplier() * 2);
		zombiesCharacter->SetFireRateMultiplier(0.66f);
	}
}

void APerk_DoubleTap::RemovePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetRayPerShotMultiplier(zombiesCharacter->GetRayPerShotMultiplier() / 2);
		zombiesCharacter->SetFireRateMultiplier(1.0f);
	}
}
