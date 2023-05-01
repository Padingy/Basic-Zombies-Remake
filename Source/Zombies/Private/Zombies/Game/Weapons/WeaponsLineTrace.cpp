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
	UE_LOG(LogTemp, Warning, TEXT("WeaponsLineTrace OnFire"));

	if (currentAmmo > 0)
	{
		TArray<FHitResult>hitResults = PerformLineTrace(2000.0f);

		if (hitResults.Num() != 0)
		{
			for (FHitResult hit : hitResults)
			{
				if (AZombieBase* zombie = Cast<AZombieBase>(hit.GetActor()))
				{
					FString hitBone = hit.BoneName.ToString();

					zombie->Hit(weaponOwner, hitBone);

					UE_LOG(LogTemp, Warning, TEXT("Shot Hit on Channel: %s"), *zombie->GetName());

					UE_LOG(LogTemp, Warning, TEXT("Bone Hit: %s"), *hitBone);
				}
			}
		}
		weaponOwner->IncreasePoints(1);

		currentAmmo--;
	}
	UE_LOG(LogTemp, Warning, TEXT("WeaponsLineTrace OnFire %d"), currentAmmo);
	UE_LOG(LogTemp, Warning, TEXT("WeaponsLineTrace OnFire %d"), currentReserveAmmo);

}

TArray<FHitResult> AWeaponsLineTrace::PerformLineTrace(float distance)
{
	AActor* owner = GetOwner();
	UCameraComponent* cameraComponent = weaponOwner->FindComponentByClass<UCameraComponent>();

	//FVector start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector start = cameraComponent->GetComponentLocation();
	//FVector rot = GetFirstPersonCameraComponent()->GetComponentRotation().Vector();
	FVector rot = cameraComponent->GetComponentRotation().Vector();
	FVector end = start + rot * distance;

	FCollisionQueryParams collisionQuery;
	FCollisionResponseParams collisionResponse;
	collisionQuery.AddIgnoredActor(this);

	DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 2.0f, 0.0f, 1.0f);

	TArray<FHitResult>hitResults;

	GetWorld()->LineTraceMultiByChannel(hitResults, start, end, ECollisionChannel::ECC_GameTraceChannel2, collisionQuery, collisionResponse);

	return hitResults;
}
