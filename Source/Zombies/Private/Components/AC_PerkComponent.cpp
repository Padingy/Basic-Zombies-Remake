// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AC_PerkComponent.h"

// Sets default values for this component's properties
UAC_PerkComponent::UAC_PerkComponent()
{
	
}


// Called when the game starts
void UAC_PerkComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

bool UAC_PerkComponent::AddPerk(APerkBase* perk)
{
	if (QueryPerk(perk->GetName()) == nullptr)
	{
		currentPerks.AddUnique(perk);
		perk->UpdatePerk(GetOwner());
		OnPerksChanged.Broadcast();
		return true;
	}
	return false;
}

void UAC_PerkComponent::RemovePerk(APerkBase* perk)
{
	currentPerks.Remove(perk);
	perk->RemovePerk(GetOwner());
	OnPerksChanged.Broadcast();
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
		if (perk)
		{
			perk->RemovePerk(GetOwner());
		}
	}
	currentPerks.Empty();
	OnPerksChanged.Broadcast();
}




