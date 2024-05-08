// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Perk_QuickRevive.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

APerk_QuickRevive::APerk_QuickRevive()
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> perkIconTextOBJ(TEXT("Texture2D'/Game/Assets/PerkIcons/Quick_Revive_HUD_Icon.Quick_Revive_HUD_Icon'"));

	if (perkIconTextOBJ.Object != NULL)
	{
		perkIcon = perkIconTextOBJ.Object;
	}
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
