// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Perk_Juggernog.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

APerk_Juggernog::APerk_Juggernog()
{
	name = TEXT("Juggernog");
	static ConstructorHelpers::FObjectFinder<UTexture2D> perkIconTextOBJ(TEXT("Texture2D'/Game/Assets/PerkIcons/Juggernog_HUD_icon.Juggernog_HUD_icon'"));

	if (perkIconTextOBJ.Object != NULL)
	{
		perkIcon = perkIconTextOBJ.Object;
	}
}

void APerk_Juggernog::UpdatePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetMaxHealth(250.0f);
		zombiesCharacter->RegenHealth();
	}
}

void APerk_Juggernog::RemovePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetMaxHealth(100.0f);
	}
}
