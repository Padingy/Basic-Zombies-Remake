// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Weapons/WeaponsLineTraceFullAuto.h"

AWeaponsLineTraceFullAuto::AWeaponsLineTraceFullAuto()
{
	bCanFire = true;
}

void AWeaponsLineTraceFullAuto::Fire()
{
	if ((weaponState == EWeaponState::Idle || weaponState == EWeaponState::Firing) && !stopFiringTimerHandle.IsValid())
	{
		weaponState = EWeaponState::Firing;
		Super::Fire();
		if (!cooldownTimerHandle.IsValid())
		{
			StartCooldown(weaponData.fireRate);
		}
	}
}

void AWeaponsLineTraceFullAuto::EndFire()
{
	EndCooldown();
}

void AWeaponsLineTraceFullAuto::StartCooldown(float time)
{
	GetWorld()->GetTimerManager().SetTimer(cooldownTimerHandle, this, &AWeaponsLineTraceFullAuto::Fire, time, true);
}

void AWeaponsLineTraceFullAuto::EndCooldown()
{
	if (!stopFiringTimerHandle.IsValid())
	{
		float timeRemaining = GetWorld()->GetTimerManager().GetTimerRemaining(cooldownTimerHandle);
		GetWorld()->GetTimerManager().ClearTimer(cooldownTimerHandle);

		GetWorld()->GetTimerManager().SetTimer(stopFiringTimerHandle, [this]()
		{
			weaponState = EWeaponState::Idle;
			bCanFire = true;

			//Clear the timer handle when the timer has fired to make sure that it can not fired off multiple times because of multiple button presses
			GetWorld()->GetTimerManager().ClearTimer(stopFiringTimerHandle);
		}, timeRemaining, false);
	}
}
