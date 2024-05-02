// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Perk_QuickRevive.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

APerk_QuickRevive::APerk_QuickRevive()
{
}

void APerk_QuickRevive::UpdatePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetRevivalTime(5.0f);
	}
}

void APerk_QuickRevive::RemovePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetRevivalTime(0.0f);
	}
}
