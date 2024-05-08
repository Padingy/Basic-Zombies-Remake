// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Zombies/Public/Player/CustomCharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Zombies/Public/Zombies/Game/Interactables/InteractablesBase.h"
#include "Zombies/Public/Zombies/Game/Weapons/WeaponsBase.h"
#include "Zombies/Public/Components/AC_PerkComponent.h"
#include "Zombies/Public/Zombie/ZombieBase.h"

AZombiesCharacter::AZombiesCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCustomCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	points = 500;
	interactable = nullptr;
	interactDistance = 100.0f;

	bWantsToSprint = false;

	staminaDecrement = 5.0f;
	staminaRefreshRate = 0.25f;
	staminaCooldown = 2.0f;
	currentStaminaCooldown = 0.0f;

	healthRegenRate = 1.0f;
	healthRegenCooldown = 3.0f;
	currentHealthCooldown = 0.0f;

	moveSpeedMultiplier = 1.0f;
	rayPerShotMultiplier = 1;
	fireRateMultiplier = 1.0f;

	revivalTime = 0.0f;
}

void AZombiesCharacter::BeginPlay()
{
	Super::BeginPlay();

	cameraHeightStanding = FirstPersonCameraComponent->GetRelativeLocation().Z;
	cameraHeightCrouching = FirstPersonCameraComponent->GetRelativeLocation().Z;
	cameraHeightCurrent = cameraHeightStanding;
	cameraHeightTarget = cameraHeightCrouching;

	playerData.stamina = playerData.maxStamina;

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AZombiesCharacter::FindInteractableObjects, 0.2f, true);
	
	OnPointsChanged.Broadcast(points);

	SpawnStartingWeapons();
}

void AZombiesCharacter::Tick(float DeltaTime)
{
	if (cameraHeightCurrent != cameraHeightTarget)
	{
		cameraHeightCurrent = FMath::FInterpTo(cameraHeightCurrent, cameraHeightTarget, DeltaTime, 10.0f);

		FirstPersonCameraComponent->SetRelativeLocation(FVector(FirstPersonCameraComponent->GetRelativeLocation().X, FirstPersonCameraComponent->GetRelativeLocation().Y, cameraHeightCurrent));
	}
}

//Action bound to input for press input to fire current weapon
void AZombiesCharacter::OnFire()
{
	if (currentWeapon)
	{
		currentWeapon->Fire();
	}
}

//Action bound to input for press input to end fire of current weapon
void AZombiesCharacter::OnEndFire()
{
	if (currentWeapon)
	{
		currentWeapon->EndFire();
	}
}

void AZombiesCharacter::RegenHealth()
{
	GetWorld()->GetTimerManager().SetTimer(healthRegenTimerHandle, this, &AZombiesCharacter::RegenHealthTimerFunction, 0.05f, true);
}

void AZombiesCharacter::RegenHealthTimerFunction()
{
	currentHealthCooldown += 0.05f;
	FString debugMessage = FString::Printf(TEXT("Health: %s"), *FString::SanitizeFloat(playerData.health));

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, debugMessage);
	if (currentHealthCooldown >= healthRegenCooldown)
	{
		if (playerData.health < playerData.maxHealth)
		{
			playerData.health += healthRegenRate;
			playerData.health = FMath::Clamp(playerData.health, 0.0f, playerData.maxHealth);
		}
		else
		{
			GetWorld()->GetTimerManager().ClearTimer(healthRegenTimerHandle);
		}
	}
}

void AZombiesCharacter::OnCrouchStart()
{
	Crouch();
}

void AZombiesCharacter::OnCrouchEnd()
{
	UnCrouch();
}

void AZombiesCharacter::OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	Super::OnStartCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);

	cameraHeightCurrent = cameraHeightStanding + ScaledHalfHeightAdjust;

	cameraHeightTarget = cameraHeightCrouching;
}

void AZombiesCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	Super::OnEndCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);

	cameraHeightCurrent = cameraHeightCrouching - ScaledHalfHeightAdjust;

	cameraHeightTarget = cameraHeightStanding;
}

void AZombiesCharacter::OnSprintStart()
{
	if (playerData.stamina > 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(sprintRefreshTimerHandle);

		bWantsToSprint = true;

		GetWorld()->GetTimerManager().SetTimer(sprintTimerHandle, this, &AZombiesCharacter::UpdateStamina, 0.05f, true);
	}
}

void AZombiesCharacter::OnSprintEnd()
{
	bWantsToSprint = false;
	GetWorld()->GetTimerManager().ClearTimer(sprintTimerHandle);

	if (playerData.stamina > 0.0f)
	{
		currentStaminaCooldown = staminaCooldown / 2;
	}
	else
	{
		currentStaminaCooldown = 0.0f;
	}

	GetWorld()->GetTimerManager().SetTimer(sprintRefreshTimerHandle, this, &AZombiesCharacter::RefreshStamina, 0.05f, true);
}

void AZombiesCharacter::UpdateStamina()
{
	if (playerData.stamina > 0)
	{
		DecreaseStamina(staminaDecrement);

		FString staminaAsString = FString::SanitizeFloat(playerData.stamina);

		FString debugMessage = FString::Printf(TEXT("Stamina: %s"), *FString::SanitizeFloat(playerData.stamina));

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, debugMessage);
	}
	else
	{
		currentStaminaCooldown = 0.0f;
		bWantsToSprint = false;
		GetWorld()->GetTimerManager().ClearTimer(sprintTimerHandle);
		GetWorld()->GetTimerManager().SetTimer(sprintRefreshTimerHandle, this, &AZombiesCharacter::RefreshStamina, 0.05f, true);
	}
}

void AZombiesCharacter::RefreshStamina()
{
	currentStaminaCooldown += 0.05f;
	
	if (currentStaminaCooldown >= staminaCooldown)
	{
		if (playerData.stamina < playerData.maxStamina)
		{
			IncreaseStamina(staminaRefreshRate);
		}
		else
		{
			currentStaminaCooldown = 0.0f;
			GetWorld()->GetTimerManager().ClearTimer(sprintRefreshTimerHandle);
		}
	}
}

void AZombiesCharacter::IncreaseStamina(float value)
{
	playerData.stamina += value;
	playerData.stamina = FMath::Clamp(playerData.stamina, 0.0f, playerData.maxStamina);
}

void AZombiesCharacter::DecreaseStamina(float value)
{
	playerData.stamina -= value;
	playerData.stamina = FMath::Clamp(playerData.stamina, 0.0f, playerData.maxStamina);
}

void AZombiesCharacter::SetMaxStamina(float newMaxStam)
{
	playerData.maxStamina = newMaxStam;
}

float AZombiesCharacter::GetMaxStamina()
{
	return playerData.maxStamina;
}

//Action bound to input for press input to reload current weapon
void AZombiesCharacter::Reload()
{
	currentWeapon->Reload();
}

//Line Trace function to find interactables and send their information through delegates
void AZombiesCharacter::FindInteractableObjects()
{
	FVector start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector rot = GetFirstPersonCameraComponent()->GetComponentRotation().Vector();

	start = start + rot * 50.0f;
	FVector end = start + rot * interactDistance;

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
		OnInteractMessageChanged.Broadcast(interactable->GetUIMessage(this));
	} 
	else if (interactable && tempHit == nullptr)
	{
		interactable = nullptr;
		OnInteractMessageChanged.Broadcast(FString());
	}
}

void AZombiesCharacter::OnInteract()
{
	if (interactable)
	{
		interactable->OnInteract(this);
	}
}

//Function to spawn weapons set to start with
void AZombiesCharacter::SpawnStartingWeapons()
{
	int32 numOfStartingWeapons = FMath::Min(maxWeapons, startingWeaponClasses.Num());

	UE_LOG(LogTemp, Warning, TEXT("NumOfStartingWeapons: %d"), numOfStartingWeapons);

	if (startingWeaponClasses.Num() > 0)
	{
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
}

//Functions for Adding and Removing weapons to the owner
void AZombiesCharacter::AddWeapon(AWeaponsBase* weapon)
{
	weapon->SetNewOwner(this);
	weaponArray.AddUnique(weapon);

	UE_LOG(LogTemp, Warning, TEXT("WeaponArray.Num(): %d"), weaponArray.Num());
}

void AZombiesCharacter::RemoveWeapon(AWeaponsBase* weapon)
{
	weapon->Destroy();
	weaponArray.Remove(weapon);
}

//Function for Equiping weapon
void AZombiesCharacter::EquipWeapon(AWeaponsBase* weapon)
{
	SetCurrentWeapon(weapon);
}

//Function for Setting the current weapon for the owner
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

void AZombiesCharacter::SetRayPerShotMultiplier(int newMultiplier)
{
	rayPerShotMultiplier = newMultiplier;
}

int AZombiesCharacter::GetRayPerShotMultiplier()
{
	return rayPerShotMultiplier;
}

void AZombiesCharacter::SetFireRateMultiplier(float newMultiplier)
{
	fireRateMultiplier = newMultiplier;
}

float AZombiesCharacter::GetFireRateMultiplier()
{
	return fireRateMultiplier;
}

bool AZombiesCharacter::GetIsAiming()
{
	return bIsAiming;
}

float AZombiesCharacter::GetMoveSpeedMultipler()
{
	return moveSpeedMultiplier;
}

void AZombiesCharacter::SetMoveSpeedMultiplier(float moveSpeed)
{
	moveSpeedMultiplier = moveSpeed;
}

void AZombiesCharacter::StartAiming()
{
	bIsAiming = true;
	currentWeapon->spreadMultiplier = 0.0f;
}

void AZombiesCharacter::StopAiming()
{
	bIsAiming = false;
	currentWeapon->spreadMultiplier = 1.0f;
}

void AZombiesCharacter::IncreasePoints(int increaseValue)
{
	points += increaseValue;
	OnPointsChanged.Broadcast(points);
}

void AZombiesCharacter::DecreasePoints(int decreaseValue)
{
	points -= decreaseValue;
	OnPointsChanged.Broadcast(points);
}

void AZombiesCharacter::Heal()
{
}

float AZombiesCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float actualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (actualDamage > 0.0f && playerData.health > 0.0f)
	{
		playerData.health -= actualDamage;

		GetWorld()->GetTimerManager().ClearTimer(healthRegenTimerHandle);
		if (playerData.health <= 0.0f)
		{
			Die();
		}
		else
		{
			currentHealthCooldown = 0.0f;
			RegenHealth();
		}
	}
	return actualDamage;
}

void AZombiesCharacter::damagePlayer(float damage)
{
	if (damage > 0.0f)
	{
		playerData.health -= damage;

		if (playerData.health <= 0.0f)
		{
			Die();
		}
		else
		{
			//Deal with HUD stuff when HUD class is made in the future
		}
	}
}

void AZombiesCharacter::Die()
{
	if (GetMesh())
	{
		static FName CollisionProfileName(TEXT("Ragdoll"));
		GetMesh()->SetCollisionProfileName(CollisionProfileName);
	}
	SetActorEnableCollision(true);

	GetMesh()->SetSimulatePhysics(true);

	if (revivalTime == 0.0f)
	{
		DeathScreen();
	}
	else
	{
		ReviveScreen();
		GetWorld()->GetTimerManager().SetTimer(reviveTimerHandle, this, &AZombiesCharacter::Revive, revivalTime, false);
	}

	Mesh1P->SetHiddenInGame(true);
	currentWeapon->SetActorHiddenInGame(true);

	if (UAC_PerkComponent* perkComponent = Cast<UAC_PerkComponent>(this->GetComponentByClass(UAC_PerkComponent::StaticClass())))
	{
		UE_LOG(LogTemp, Warning, TEXT("CurrentPerks.num: %d"), perkComponent->GetCurrentPerks().Num());
		perkComponent->RemoveAllPerks();
	}
}

void AZombiesCharacter::Revive()
{
	playerData.health = playerData.maxHealth;
	GetMesh()->SetSimulatePhysics(false);
	
	if (GetMesh())
	{
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		GetMesh()->SetCollisionProfileName(CollisionProfileName);
	}

	SetHUD();
	OnPointsChanged.Broadcast(points);
	
	Mesh1P->SetHiddenInGame(false);
	currentWeapon->SetActorHiddenInGame(false);
}

void AZombiesCharacter::SetRevivalTime(float newRevivalTime)
{
	revivalTime = newRevivalTime;
}

void AZombiesCharacter::SetHUD_Implementation()
{
}

void AZombiesCharacter::ReviveScreen_Implementation()
{
}

void AZombiesCharacter::DeathScreen_Implementation()
{
}

void AZombiesCharacter::IncreaseHealth(float increaseValue)
{
	playerData.health = FMath::Clamp(playerData.health += increaseValue, 0.0f, playerData.maxHealth);
}

void AZombiesCharacter::DecreaseHealth(float decreaseValue)
{
	playerData.health = FMath::Clamp(playerData.health -= decreaseValue, 0.0f, playerData.maxHealth);
}

void AZombiesCharacter::SetMaxHealth(float newMaxHealth)
{
	playerData.maxHealth = newMaxHealth;
}

void AZombiesCharacter::SetReloadSpeedModifier(float newReloadSpeed)
{
	playerData.reloadSpeedMultiplier = newReloadSpeed;
}

float AZombiesCharacter::GetMaxHealth()
{
	return playerData.maxHealth;
}

float AZombiesCharacter::GetHealth()
{
	return playerData.health;
}

float AZombiesCharacter::GetReloadSpeedMultiplier()
{
	return playerData.reloadSpeedMultiplier;
}

int32 AZombiesCharacter::GetPoints()
{
	return points;
}

bool AZombiesCharacter::GetIsSprinting()
{
	return bWantsToSprint && (GetVelocity().GetSafeNormal2D() | GetActorForwardVector()) > 0.1;
}

FName AZombiesCharacter::GetWeaponAttachPoint() const
{
	return weaponAttachPoint;
}

TArray<AWeaponsBase*> AZombiesCharacter::GetWeaponArray()
{
	return weaponArray;
}

AWeaponsBase* AZombiesCharacter::GetCurrentWeapon()
{
	return currentWeapon;
}

int32 AZombiesCharacter::GetMaxWeapons()
{
	return maxWeapons;
}

// Called to bind functionality to input
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

void AZombiesCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AZombiesCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AZombiesCharacter::MoveRight);


	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AZombiesCharacter::OnFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AZombiesCharacter::OnEndFire);

	PlayerInputComponent->BindAction("ADS", IE_Pressed, this, &AZombiesCharacter::StartAiming);
	PlayerInputComponent->BindAction("ADS", IE_Released, this, &AZombiesCharacter::StopAiming);


	PlayerInputComponent->BindAction("NextWeapon", IE_Pressed, this, &AZombiesCharacter::OnNextWeapon);
	PlayerInputComponent->BindAction("PrevWeapon", IE_Pressed, this, &AZombiesCharacter::OnPrevWeapon);

	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AZombiesCharacter::Reload);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AZombiesCharacter::OnInteract);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AZombiesCharacter::OnCrouchStart);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AZombiesCharacter::OnCrouchEnd);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AZombiesCharacter::OnSprintStart);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AZombiesCharacter::OnSprintEnd);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AZombiesCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AZombiesCharacter::LookUpAtRate);
}

