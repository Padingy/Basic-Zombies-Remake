// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Weapons/WeaponsLineTrace.h"
#include "Zombies/Public/Zombie/ZombieBase.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

AWeaponsLineTrace::AWeaponsLineTrace()
{

}

void AWeaponsLineTrace::Fire()
{
	if (currentAmmo > 0)
	{
		Super::Fire();
		for (int i = 0; i < raysPerShot * weaponOwner->GetRayPerShotMultiplier(); i += 1)
		{
			UCameraComponent* cameraComponent = weaponOwner->FindComponentByClass<UCameraComponent>();

			FVector startLoc = cameraComponent->GetComponentLocation();

			float spreadX = FMath::FRandRange(-2.0f, 2.0f);
			float spreadY = FMath::FRandRange(-2.0f, 2.0f);
			float spreadZ = FMath::FRandRange(-2.0f, 2.0f);
			FRotator rot = (FRotator(spreadX, spreadY, spreadZ) * spreadMultiplier) + cameraComponent->GetComponentRotation();

			FVector endLoc = startLoc + (rot.Vector() * 2000.0f);
			FVector shootDir = endLoc - startLoc;

			TArray<FHitResult>hitResults = PerformLineTrace(startLoc, endLoc);

			DealWithHits(hitResults, shootDir);
		}

		if (!weaponData.bInfiniteAmmo)
		{
			currentAmmo--;
		}
	}
}

TArray<FHitResult> AWeaponsLineTrace::PerformLineTrace(FVector startLoc, FVector Endloc)
{
	FCollisionQueryParams collisionQuery;
	FCollisionResponseParams collisionResponse;
	collisionQuery.AddIgnoredActor(this);

	TArray<FHitResult>hitResults;

	GetWorld()->LineTraceMultiByChannel(hitResults, startLoc, Endloc, ECollisionChannel::ECC_GameTraceChannel2, collisionQuery, collisionResponse);

	return hitResults;
}

void AWeaponsLineTrace::DealWithHits(TArray<FHitResult>& hitResults, FVector& shootDir)
{
	if (hitResults.Num() != 0)
	{
		TArray<AActor*> tempHitActors;
		for (FHitResult hit : hitResults)
		{
			if (AZombieBase* zombie = Cast<AZombieBase>(hit.GetActor()))
			{
				if (!tempHitActors.Contains(zombie))
				{
					tempHitActors.AddUnique(zombie);
					FString hitBone = hit.BoneName.ToString();

					DealDamage(damageData.GetDamage(hit.BoneName), hit, shootDir);
					zombie->Hit(weaponOwner, hitBone);
				}
			}
		}
	}
}

void AWeaponsLineTrace::DealDamage(float damage, FHitResult& hitActor, FVector& shootDir)
{
	FPointDamageEvent damageEvent;
	damageEvent.Damage = damage;
	damageEvent.ShotDirection = shootDir;

	hitActor.GetActor()->TakeDamage(damage, damageEvent, weaponOwner->Controller, this);
}
