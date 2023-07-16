// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Weapons/WeaponsLineTraceSemi.h"

AWeaponsLineTraceSemi::AWeaponsLineTraceSemi()
{

}

void AWeaponsLineTraceSemi::Fire()
{
	if (weaponState == EWeaponState::Idle)
	{
		SetWantsToFire(true);

		Super::Fire();
		StartFiringCooldown(weaponData.fireRate);
	}
}

void AWeaponsLineTraceSemi::StartFiringCooldown(float time)
{
	GetWorld()->GetTimerManager().SetTimer(cooldownTimerHandle, this, &AWeaponsLineTraceSemi::EndFiringCooldown, time, false);
}

void AWeaponsLineTraceSemi::EndFiringCooldown()
{
	SetWantsToFire(false);
}
