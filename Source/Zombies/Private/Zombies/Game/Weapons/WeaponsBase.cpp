// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombies/Game/Weapons/WeaponsBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Zombies/Public/Zombie/ZombieBase.h"

// Sets default values
AWeaponsBase::AWeaponsBase()
{

	weaponSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponsSkeletalMesh"));
	weaponSkeletalMesh->SetOnlyOwnerSee(false);
	weaponSkeletalMesh->bCastDynamicShadow = false;
	weaponSkeletalMesh->CastShadow = false;

	RootComponent = weaponSkeletalMesh;

	weaponState = EWeaponState::Idle;
}

void AWeaponsBase::Fire()
{
	
}

void AWeaponsBase::EndFire()
{
	UE_LOG(LogTemp, Warning, TEXT("WeaponBase EndFire"));
}

void AWeaponsBase::Reload()
{
	if (currentReserveAmmo > 0)
	{
		int32 missingAmmo = FMath::Min(weaponData.magazineSize - currentAmmo, (currentAmmo + currentReserveAmmo) - currentAmmo);

		currentAmmo += missingAmmo;

		currentReserveAmmo -= missingAmmo;
	}
	UE_LOG(LogTemp, Warning, TEXT("WeaponsLineTrace OnFire %d"), currentAmmo);
	UE_LOG(LogTemp, Warning, TEXT("WeaponsLineTrace OnFire %d"), currentReserveAmmo);
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

void AWeaponsBase::OnEquip()
{
	AttachWeaponToMesh();
}

void AWeaponsBase::OnUnequip()
{
	DetachWeaponFromMesh();
}

void AWeaponsBase::StartCooldown(float time)
{
}

void AWeaponsBase::EndCooldown()
{
}

// Called when the game starts or when spawned
void AWeaponsBase::BeginPlay()
{
	Super::BeginPlay();
	
	DetachWeaponFromMesh();
}

