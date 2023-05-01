// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Zombies/Public/Zombies/Game/Interactables/InteractablesBase.h"
#include "Zombies/Public/Zombies/Game/Weapons/WeaponsBase.h"
#include "Zombies/Public/Zombie/ZombieBase.h"

AZombiesCharacter::AZombiesCharacter()
{
	points = 500;
	interactable = nullptr;
}

void AZombiesCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AZombiesCharacter::FindInteractableObjects, 0.2f, true);
	
	SpawnStartingWeapons();

	UE_LOG(LogTemp, Warning, TEXT("ZombiesCharacter"));
}

void AZombiesCharacter::OnFire()
{
	if (currentWeapon)
	{
		currentWeapon->Fire();
	}
}

void AZombiesCharacter::Reload()
{
	currentWeapon->Reload();
}

void AZombiesCharacter::FindInteractableObjects()
{
	FVector start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector rot = GetFirstPersonCameraComponent()->GetComponentRotation().Vector();

	start = start + rot * 50.0f;
	FVector end = start + rot * 100.0f;

	FCollisionObjectQueryParams collisionQuery;
	FCollisionQueryParams collisionParams;
	collisionParams.AddIgnoredActor(this);

	FHitResult hitResult;

	GetWorld()->LineTraceSingleByObjectType(hitResult, start, end, collisionQuery, collisionParams);
	
	AInteractablesBase* tempHit = Cast<AInteractablesBase>(hitResult.GetActor());
	if (interactable == nullptr && tempHit)
	{ 
		interactable = tempHit;
		UE_LOG(LogTemp, Warning, TEXT("WallBuy Interact Message: %s"), *interactable->UIMessage);
		OnInteractMessageChanged.Broadcast(interactable->UIMessage);
	}
	else if (interactable && tempHit == nullptr)
	{
		interactable = nullptr;
		OnInteractMessageChanged.Broadcast(FString());
	}

	DrawDebugLine(GetWorld(), start, end, FColor::Yellow, false, 10.0f, 0.0f, 1.0f);
}

void AZombiesCharacter::SpawnStartingWeapons()
{
	int32 numOfStartingWeapons = startingWeaponClasses.Num();

	for (int32 i = 0; i < numOfStartingWeapons; i++)
	{
		FActorSpawnParameters spawnParams;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AWeaponsBase* newWeapon = GetWorld()->SpawnActor<AWeaponsBase>(startingWeaponClasses[i], spawnParams);
		AddWeapon(newWeapon);
	}

	EquipWeapon(weaponArray[0]);
	weaponIndex = 0;
}

void AZombiesCharacter::AddWeapon(AWeaponsBase* weapon)
{
	weapon->SetNewOwner(this);
	weaponArray.AddUnique(weapon);
}

void AZombiesCharacter::RemoveWeapon(AWeaponsBase* weapon)
{

}

void AZombiesCharacter::EquipWeapon(AWeaponsBase* weapon)
{
	SetCurrentWeapon(weapon);
}

void AZombiesCharacter::SetCurrentWeapon(AWeaponsBase* newWeapon)
{
	AWeaponsBase* lastWeapon = nullptr;

	if (newWeapon != currentWeapon)
	{
		lastWeapon = currentWeapon;
	}

	if (newWeapon)
	{
		if (lastWeapon)
		{
			lastWeapon->OnUnequip();
		}

		currentWeapon = newWeapon;
		weaponIndex = weaponArray.Find(currentWeapon);
		
		UE_LOG(LogTemp, Warning, TEXT("Current Weapon Index: %d"), weaponIndex);

		currentWeapon->SetNewOwner(this);
		currentWeapon->OnEquip();
	}
}

void AZombiesCharacter::IncreasePoints(int value)
{
	points += value;
	OnPointsChanged.Broadcast(points);
}

void AZombiesCharacter::DecreasePoints(int value)
{
	points -= value;
	OnPointsChanged.Broadcast(points);
}

int32 AZombiesCharacter::GetPoints()
{
	return points;
}

FName AZombiesCharacter::GetWeaponAttachPoint() const
{
	return weaponAttachPoint;
}

// Called to bind functionality to input
void AZombiesCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AZombiesCharacter::OnFire);

	PlayerInputComponent->BindAxis("MoveForward", this, &AZombiesCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AZombiesCharacter::MoveRight);

	PlayerInputComponent->BindAction("NextWeapon", IE_Pressed, this, &AZombiesCharacter::OnNextWeapon);
	PlayerInputComponent->BindAction("PrevWeapon", IE_Pressed, this, &AZombiesCharacter::OnPrevWeapon);

	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AZombiesCharacter::Reload);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AZombiesCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AZombiesCharacter::LookUpAtRate);
}

void AZombiesCharacter::OnNextWeapon()
{
	if (weaponArray.Num() > 1)
	{
		int32 nextWeaponIndex = (weaponIndex + 1) % weaponArray.Num();

		SetCurrentWeapon(weaponArray[nextWeaponIndex]);
	}
}

void AZombiesCharacter::OnPrevWeapon()
{
	if (weaponArray.Num() > 1)
	{
		float nextWeaponIndex = (weaponIndex + (weaponArray.Num() - 1)) % weaponArray.Num();
		UE_LOG(LogTemp, Warning, TEXT("nextWeaponIndex %f"), nextWeaponIndex);
		SetCurrentWeapon(weaponArray[nextWeaponIndex]);
	}
}
