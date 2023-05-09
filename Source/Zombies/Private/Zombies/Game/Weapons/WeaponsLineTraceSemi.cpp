// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Weapons/WeaponsLineTraceSemi.h"

AWeaponsLineTraceSemi::AWeaponsLineTraceSemi()
{
	bCanFire = true;
}

void AWeaponsLineTraceSemi::Fire()
{
	//if (bCanFire == true)
	if (weaponState == EWeaponState::Idle)
	{
		Super::Fire();
		StartCooldown(weaponData.fireRate);
	}
}

void AWeaponsLineTraceSemi::StartCooldown(float time)
{
	GetWorld()->GetTimerManager().SetTimer(cooldownTimerHandle, this, &AWeaponsLineTraceSemi::EndCooldown, time, false);
	weaponState = EWeaponState::Firing;
}

void AWeaponsLineTraceSemi::EndCooldown()
{
	weaponState = EWeaponState::Idle;
	UE_LOG(LogTemp, Warning, TEXT("CanFire == True"));
}
