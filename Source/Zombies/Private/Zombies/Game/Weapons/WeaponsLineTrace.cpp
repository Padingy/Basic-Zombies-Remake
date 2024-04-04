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

	DrawDebugLine(GetWorld(), startLoc, Endloc, FColor::Red, false, 2.0f, 0.0f, 1.0f);

	TArray<FHitResult>hitResults;

	GetWorld()->LineTraceMultiByChannel(hitResults, startLoc, Endloc, ECollisionChannel::ECC_GameTraceChannel2, collisionQuery, collisionResponse);

	return hitResults;
}

void AWeaponsLineTrace::DealWithHits(TArray<FHitResult>& hitResults, FVector& shootDir)
{
	if (hitResults.Num() != 0)
	{
		for (FHitResult hit : hitResults)
		{
			if (AZombieBase* zombie = Cast<AZombieBase>(hit.GetActor()))
			{
				FString hitBone = hit.BoneName.ToString();

				DealDamage(weaponData.damage, hit, shootDir);
				zombie->Hit(weaponOwner, hitBone);

				UE_LOG(LogTemp, Warning, TEXT("Bone Hit: %s"), *hitBone);
			}
		}
	}
}

void AWeaponsLineTrace::DealDamage(float damage, FHitResult& hitActor, FVector& shootDir)
{
	FPointDamageEvent damageEvent;
	damageEvent.Damage = weaponData.damage;
	damageEvent.ShotDirection = shootDir;

	hitActor.GetActor()->TakeDamage(damage, damageEvent, weaponOwner->Controller, this);
}
