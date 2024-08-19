// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Perk_StaminUp.h"

#include "Zombies/Public/Player/ZombiesCharacter.h"

APerk_StaminUp::APerk_StaminUp()
{
	name = TEXT("StaminUp");
	staminaMultiplier = 2.0f;

	static ConstructorHelpers::FObjectFinder<UTexture2D> perkIconTextOBJ(TEXT("Texture2D'/Game/Assets/PerkIcons/Stamin-Up_HUD_icon.Stamin-Up_HUD_icon'"));

	if (perkIconTextOBJ.Object != NULL)
	{
		perkIcon = perkIconTextOBJ.Object;
	}
}

void APerk_StaminUp::UpdatePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetMoveSpeedMultiplier(1.07f);
		zombiesCharacter->SetMaxStamina(zombiesCharacter->GetMaxStamina() * staminaMultiplier);
		zombiesCharacter->IncreaseStamina(zombiesCharacter->GetMaxStamina());
	}
}

void APerk_StaminUp::RemovePerk(AActor* owner)
{
	AZombiesCharacter* zombiesCharacter = Cast<AZombiesCharacter>(owner);
	if (zombiesCharacter)
	{
		zombiesCharacter->SetMoveSpeedMultiplier(1.00f);
		zombiesCharacter->SetMaxStamina(zombiesCharacter->GetMaxStamina() / staminaMultiplier);
		zombiesCharacter->IncreaseStamina(zombiesCharacter->GetMaxStamina());
	}
}
