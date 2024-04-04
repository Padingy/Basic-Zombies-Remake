// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombies/Game/Weapons/WeaponsBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Zombies/Public/Zombie/ZombieBase.h"
#include "Engine/Engine.h"

// Sets default values
AWeaponsBase::AWeaponsBase()
{

	weaponSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponsSkeletalMesh"));
	weaponSkeletalMesh->SetOnlyOwnerSee(false);
	weaponSkeletalMesh->bCastDynamicShadow = false;
	weaponSkeletalMesh->CastShadow = false;

	RootComponent = weaponSkeletalMesh;

	bWantsToReload = false;
	bWantsToFire = false;

	weaponState = EWeaponState::Idle;

	spreadMultiplier = 1.0f;
}

void AWeaponsBase::Fire()
{

}

void AWeaponsBase::EndFire()
{
	
}

void AWeaponsBase::Reload()
{
	if (CanReload())
	{
		bWantsToReload = true;
		DetermineWeaponState();

		GetWorld()->GetTimerManager().ClearTimer(cooldownTimerHandle);

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString("Reloading Starting"));

		GetWorld()->GetTimerManager().SetTimer(reloadTimerHandle, [this]()
		{
			HandleReload();
			bWantsToReload = false;
			DetermineWeaponState();

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString("Reloading Finished"));
		}, weaponData.reloadSpeed / weaponOwner->GetReloadSpeedMultiplier(), false);
	}
}

bool AWeaponsBase::GetInfiniteAmmo() const
{
	return weaponData.bInfiniteAmmo;
}

float AWeaponsBase::GetDamage() const
{
	return weaponData.damage;
}

int32 AWeaponsBase::GetMagaezineSize() const
{
	return weaponData.magazineSize;
}

int32 AWeaponsBase::GetMagazineAmount() const
{
	return weaponData.magazineAmount;
}

float AWeaponsBase::GetFireRate() const
{
	return weaponData.fireRate;
}

void AWeaponsBase::SetCurrentAmmo(int32 newCurrentAmmo)
{
	currentAmmo = newCurrentAmmo;
}

void AWeaponsBase::SetCurrentReserveAmmo(int32 newCurrentReserveAmmo)
{
	currentReserveAmmo = newCurrentReserveAmmo;
}

void AWeaponsBase::SetNewOwner(AZombiesCharacter* newOwner)
{
	if (weaponOwner != newOwner)
	{
		weaponOwner = newOwner;
	}
}

class AZombiesCharacter* AWeaponsBase::GetWeaponOwner() const
{
	return weaponOwner;
}

TEnumAsByte<EWeaponType> AWeaponsBase::GetWeaponType()
{
	return weaponType;
}

int32 AWeaponsBase::GetCurrentAmmo()
{
	return currentAmmo;
}

int32 AWeaponsBase::GetReserveAmmo()
{
	return currentReserveAmmo;
}

void AWeaponsBase::AttachWeaponToMesh()
{
	if (weaponOwner)
	{
		FName attachPoint = weaponOwner->GetWeaponAttachPoint();
		
		USkeletalMeshComponent* ownerMesh = weaponOwner->GetMesh1P();
		weaponSkeletalMesh->AttachToComponent(ownerMesh, FAttachmentTransformRules::KeepRelativeTransform, attachPoint);

		weaponSkeletalMesh->SetHiddenInGame(false);
	}
}

void AWeaponsBase::DetachWeaponFromMesh()
{
	weaponSkeletalMesh->DetachFromComponent(FDetachmentTransformRules::KeepRelativeTransform);
	weaponSkeletalMesh->SetHiddenInGame(true);
}

USkeletalMeshComponent* AWeaponsBase::GetMesh()
{
	return weaponSkeletalMesh;
}

void AWeaponsBase::OnEquip()
{
	AttachWeaponToMesh();
}

void AWeaponsBase::OnUnequip()
{
	DetachWeaponFromMesh();
}

void AWeaponsBase::AddAmmo(int32 ammo, bool includeCurrentMagazine)
{
	if (includeCurrentMagazine)
	{
		int32 ammoToAddCurrent = FMath::Min(weaponData.magazineSize - currentAmmo, ammo);
		currentAmmo += ammoToAddCurrent;
		
		ammo -= ammoToAddCurrent;
		currentReserveAmmo += ammo;

		currentReserveAmmo = FMath::Clamp(currentReserveAmmo, 0, weaponData.magazineAmount * weaponData.magazineSize);
	}
	else
	{
		currentReserveAmmo += ammo;

		currentReserveAmmo = FMath::Clamp(currentReserveAmmo, 0, weaponData.magazineAmount * weaponData.magazineSize);
	}
}

void AWeaponsBase::StartFiringCooldown(float time)
{
}

void AWeaponsBase::EndFiringCooldown()
{
}

void AWeaponsBase::SetWeaponState(EWeaponState newState)
{
	weaponState = newState;
}

void AWeaponsBase::SetWantsToFire(bool newWantsToFire)
{
	bWantsToFire = newWantsToFire;
	DetermineWeaponState();
}

bool AWeaponsBase::CanFire()
{
	bool bStateCanFire = ((weaponState == EWeaponState::Idle) || (weaponState == EWeaponState::Firing));
	return ((bStateCanFire) && (bWantsToReload == false));
}

bool AWeaponsBase::CanReload()
{
	bool bHasAmmo = ((currentAmmo < weaponData.magazineSize) && (currentReserveAmmo > 0));
	bool bStateCanReload = ((weaponState == EWeaponState::Idle) || (weaponState == EWeaponState::Firing));
	return ((bHasAmmo == true) && (bStateCanReload == true));
}

void AWeaponsBase::HandleReload()
{
	int32 missingAmmo = FMath::Min(weaponData.magazineSize - currentAmmo, (currentAmmo + currentReserveAmmo) - currentAmmo);

	currentAmmo += missingAmmo;

	currentReserveAmmo -= missingAmmo;
}

void AWeaponsBase::DetermineWeaponState()
{
	EWeaponState newState = EWeaponState::Idle;

	if (bWantsToReload)
	{
		if (CanReload() == true)
		{
			newState = EWeaponState::Reloading;
		}
		else
		{
			newState = weaponState;
		}
	}
	else if ((bWantsToReload == false) && (bWantsToFire == true) && (CanFire() == true))
	{
		newState = EWeaponState::Firing;
	}

	weaponState = newState;
}

// Called when the game starts or when spawned
void AWeaponsBase::BeginPlay()
{
	Super::BeginPlay();
	
	DetachWeaponFromMesh();
}

