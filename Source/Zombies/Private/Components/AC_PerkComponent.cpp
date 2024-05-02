// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AC_PerkComponent.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

// Sets default values for this component's properties
UAC_PerkComponent::UAC_PerkComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAC_PerkComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAC_PerkComponent::AddPerk(APerkBase* perk)
{
	if (!currentPerks.Contains(perk))
	{
		currentPerks.AddUnique(perk);
		perk->UpdatePerk(GetOwner());
	}
}

void UAC_PerkComponent::RemovePerk(APerkBase* perk)
{
	currentPerks.Remove(perk);
	perk->RemovePerk(GetOwner());
}

APerkBase* UAC_PerkComponent::QueryPerk(FName perkName)
{
	for (APerkBase* perk : currentPerks)
	{
		if (perk->GetName() == perkName)
		{
			return perk;
		}
	}
	return nullptr;
}

TArray<APerkBase*> UAC_PerkComponent::GetCurrentPerks()
{
	return currentPerks;
}

void UAC_PerkComponent::RemoveAllPerks()
{
	for (APerkBase* perk : currentPerks)
	{
		perk->RemovePerk(GetOwner());
	}
	currentPerks.Empty();
}




