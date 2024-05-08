// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Perk_SpeedCola.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

APerk_SpeedCola::APerk_SpeedCola()
{
	name = TEXT("SpeedCola");
	reloadSpeedMultiplier = 1.5f;

	static ConstructorHelpers::FObjectFinder<UTexture2D> perkIconTextOBJ(TEXT("Texture2D'/Game/Assets/PerkIcons/Speed_Cola_HUD_Icon.Speed_Cola_HUD_Icon'"));

	if (perkIconTextOBJ.Object != NULL)
	{
		perkIcon = perkIconTextOBJ.Object;
	}
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
