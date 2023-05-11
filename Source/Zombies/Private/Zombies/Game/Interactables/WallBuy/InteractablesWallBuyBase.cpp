// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/WallBuy/InteractablesWallBuyBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

AInteractablesWallBuyBase::AInteractablesWallBuyBase()
{

}


//TODO: Refactor this to put the For loop into its own class.
void AInteractablesWallBuyBase::OnInteract(AZombiesCharacter* interactingPlayer)
{
	if (interactingPlayer->GetWeaponArray().Num() < interactingPlayer->GetMaxWeapons())
	{
		if (CheckIfPlayerOwnsWeapon(interactingPlayer->GetWeaponArray()))
		{
			
		}
		else
		{
			if (interactingPlayer->GetPoints() >= cost)
			{
				FActorSpawnParameters spawnParams;
				spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				AWeaponsBase* newWeapon = GetWorld()->SpawnActor<AWeaponsBase>(weaponType, spawnParams);

				interactingPlayer->AddWeapon(newWeapon);
				interactingPlayer->SetCurrentWeapon(newWeapon);

				interactingPlayer->DecreasePoints(cost);
			}

		}
	}
	else if (interactingPlayer->GetWeaponArray().Num() >= interactingPlayer->GetMaxWeapons())
	{
		if (CheckIfPlayerOwnsWeapon(interactingPlayer->GetWeaponArray()))
		{

		}
		else
		{
			if (interactingPlayer->GetPoints() >= cost)
			{
				FActorSpawnParameters spawnParams;
				spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				AWeaponsBase* newWeapon = GetWorld()->SpawnActor<AWeaponsBase>(weaponType, spawnParams);

				AWeaponsBase* lastWeapon = interactingPlayer->GetCurrentWeapon();

				interactingPlayer->AddWeapon(newWeapon);
				interactingPlayer->SetCurrentWeapon(newWeapon);
				interactingPlayer->RemoveWeapon(lastWeapon);

				interactingPlayer->DecreasePoints(cost);
			}

		}
	}
}

FString AInteractablesWallBuyBase::GetUIMessage(AZombiesCharacter* interactingPlayer)
{
	bool playerOwnsWeapon;
	for (AWeaponsBase* weapon : interactingPlayer->GetWeaponArray())
	{
		if (weapon->GetClass() == weaponType)
		{
			playerOwnsWeapon = true;
			break;
		}
		else
		{
			playerOwnsWeapon = false;
		}
	}

	if (playerOwnsWeapon)
	{
		return UIMessage = "Hold F to buy Ammo [ " + FString::FromInt(ammoCost) + " ]";
	}
	else
	{
		return UIMessage = "Hold F to buy " + name + " for [Cost " + FString::FromInt(cost) + "]";
	}
}

AWeaponsBase* AInteractablesWallBuyBase::CheckIfPlayerOwnsWeapon(TArray<AWeaponsBase*> weaponArray)
{
	for (AWeaponsBase* weapon : weaponArray)
	{
		if (weapon->GetClass() == weaponType)
		{
			return weapon;
		}
	}

	return nullptr;
}
