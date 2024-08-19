// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/PerkMachines/InteractablesPerkMachineBase.h"
#include "Zombies/Public/Components/AC_PerkComponent.h"
#include "Player/ZombiesCharacter.h"

AInteractablesPerkMachineBase::AInteractablesPerkMachineBase()
{
	perkType = nullptr;
}

void AInteractablesPerkMachineBase::OnInteract(AZombiesCharacter* interactingPlayer)
{
	if (interactingPlayer->GetPoints() >= cost)
	{
		UAC_PerkComponent* perkComponent = Cast<UAC_PerkComponent>(interactingPlayer->GetComponentByClass(UAC_PerkComponent::StaticClass()));
		if (perkComponent)
		{
			if (perkType != nullptr)
			{
				APerkBase* perkTypePointer = NewObject<APerkBase>(GetTransientPackage(), perkType);
			
				if (perkComponent->AddPerk(perkTypePointer))
				{
					interactingPlayer->DecreasePoints(cost);
				}
			}
		}
	}
}
