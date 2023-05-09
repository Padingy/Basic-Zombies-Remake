// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/WallBuy/InteractablesWallBuyBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

AInteractablesWallBuyBase::AInteractablesWallBuyBase()
{

}

void AInteractablesWallBuyBase::OnInteract(AZombiesCharacter* interactingPlayer)
{
	if (interactingPlayer->GetWeaponArray().Num() < interactingPlayer->GetMaxWeapons())
	{
		for (AWeaponsBase* weapon : interactingPlayer->GetWeaponArray())
		{
			if (weapon->GetClass() == weaponType)
			{
				UE_LOG(LogTemp, Warning, TEXT("WeaponArray Contains Weapon"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("WeaponArray Does Not Contain Weapon"));
			}

		}

	}
}
