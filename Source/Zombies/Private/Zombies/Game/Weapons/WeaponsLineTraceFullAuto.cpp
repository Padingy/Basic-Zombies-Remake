// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Weapons/WeaponsLineTraceFullAuto.h"

#include "Player/ZombiesCharacter.h"

AWeaponsLineTraceFullAuto::AWeaponsLineTraceFullAuto()
{

}

void AWeaponsLineTraceFullAuto::Fire()
{
	if (CanFire() && !stopFiringTimerHandle.IsValid())
	{
		SetWantsToFire(true);
		Super::Fire();

		if (!cooldownTimerHandle.IsValid())
		{
			StartFiringCooldown(weaponData.fireRate * weaponOwner->GetFireRateMultiplier());
		}
	}
}

void AWeaponsLineTraceFullAuto::EndFire()
{
	EndFiringCooldown();
}

void AWeaponsLineTraceFullAuto::StartFiringCooldown(float time)
{
	GetWorld()->GetTimerManager().SetTimer(cooldownTimerHandle, this, &AWeaponsLineTraceFullAuto::Fire, time, true);
}

void AWeaponsLineTraceFullAuto::EndFiringCooldown()
{
	if (!stopFiringTimerHandle.IsValid() && bWantsToReload != true)
	{
		float timeRemaining = GetWorld()->GetTimerManager().GetTimerRemaining(cooldownTimerHandle);
		GetWorld()->GetTimerManager().ClearTimer(cooldownTimerHandle);

		GetWorld()->GetTimerManager().SetTimer(stopFiringTimerHandle, [this]()
		{
			SetWantsToFire(false);

			GetWorld()->GetTimerManager().ClearTimer(stopFiringTimerHandle);
		}, timeRemaining, false);
	}
}
