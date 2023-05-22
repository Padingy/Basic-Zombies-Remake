// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/WallBuy/InteractablesWallBuyBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Engine/GameInstance.h"

AInteractablesWallBuyBase::AInteractablesWallBuyBase()
{
	weaponStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallBuyStaticMesh"));
	weaponStaticMesh->SetOnlyOwnerSee(false);
	weaponStaticMesh->bCastDynamicShadow = false;
	weaponStaticMesh->CastShadow = false;
	RootComponent = weaponStaticMesh;

	weaponSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WallBuyWeaponSkeletalMesh"));
	weaponSkeletalMesh->SetRelativeLocation(FVector(-22.0f, -6.0f, -5.0f));
	weaponSkeletalMesh->SetHiddenInGame(true);
	weaponSkeletalMesh->SetupAttachment(RootComponent);

	animSpeed = 25.0f;
}


//TODO: Refactor this to put the For loop into its own class.
void AInteractablesWallBuyBase::OnInteract(AZombiesCharacter* interactingPlayer)
{
	if (weaponSkeletalMesh->GetRelativeLocation() != animEndLocation)
	{
		weaponSkeletalMesh->SetHiddenInGame(false);
		GetWorld()->GetTimerManager().SetTimer(animTimerHandle, [this] {
			UGameInstance* gameInstance = GetGameInstance();

			weaponSkeletalMesh->SetRelativeLocation(FMath::VInterpTo(weaponSkeletalMesh->GetRelativeLocation(), animEndLocation, gameInstance->GetWorld()->GetDeltaSeconds(), animSpeed));

			if (weaponSkeletalMesh->GetRelativeLocation() == animEndLocation)
			{
				GetWorld()->GetTimerManager().ClearTimer(animTimerHandle);
			}
		}, 0.05, true);
	}

	if (interactingPlayer->GetWeaponArray().Num() < interactingPlayer->GetMaxWeapons())
	{
		if (AWeaponsBase* ownedWeapon = CheckIfPlayerOwnsWeapon(interactingPlayer->GetWeaponArray()))
		{
			ownedWeapon->AddAmmo(500, true);

			interactingPlayer->DecreasePoints(ammoCost);
		}
		else
		{
			if (interactingPlayer->GetPoints() >= cost)
			{
				FActorSpawnParameters spawnParams;
				spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				AWeaponsBase* newWeapon = GetWorld()->SpawnActor<AWeaponsBase>(weaponType, spawnParams);

				interactingPlayer->AddWeapon(newWeapon);
				interactingPlayer->SetCurrentWeapon(newWeapon);

				interactingPlayer->DecreasePoints(cost);
			}
		}
	}
	else if (interactingPlayer->GetWeaponArray().Num() >= interactingPlayer->GetMaxWeapons())
	{
		if (AWeaponsBase* ownedWeapon = CheckIfPlayerOwnsWeapon(interactingPlayer->GetWeaponArray()))
		{
			ownedWeapon->AddAmmo(500, true);

			interactingPlayer->DecreasePoints(ammoCost);
		}
		else
		{
			if (interactingPlayer->GetPoints() >= cost)
			{
				FActorSpawnParameters spawnParams;
				spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				AWeaponsBase* newWeapon = GetWorld()->SpawnActor<AWeaponsBase>(weaponType, spawnParams);

				AWeaponsBase* lastWeapon = interactingPlayer->GetCurrentWeapon();

				interactingPlayer->AddWeapon(newWeapon);
				interactingPlayer->SetCurrentWeapon(newWeapon);
				interactingPlayer->RemoveWeapon(lastWeapon);

				interactingPlayer->DecreasePoints(cost);
			}
		}
	}
}

FString AInteractablesWallBuyBase::GetUIMessage(AZombiesCharacter* interactingPlayer)
{
	bool playerOwnsWeapon = false;

	UE_LOG(LogTemp, Warning, TEXT("PlayerOwnsWeapon: %d"), playerOwnsWeapon);
	for (AWeaponsBase* weapon : interactingPlayer->GetWeaponArray())
	{
		if (weapon->GetClass() == weaponType)
		{
			UE_LOG(LogTemp, Warning, TEXT("Player Owns Weapon"));
			playerOwnsWeapon = true;
			break;
		}
		else
		{
			playerOwnsWeapon = false;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerOwnsWeapon after for loop: %d"), playerOwnsWeapon);

	if (playerOwnsWeapon)
	{
		return UIMessage = "Hold F to buy Ammo [ " + FString::FromInt(ammoCost) + " ]";
	}
	else
	{
		return UIMessage = "Hold F to buy " + name + " for [ Cost " + FString::FromInt(cost) + " ]";
	}
}

void AInteractablesWallBuyBase::BeginPlay()
{
	Super::BeginPlay();

	animStartLocation = weaponSkeletalMesh->GetRelativeLocation();
}

AWeaponsBase* AInteractablesWallBuyBase::CheckIfPlayerOwnsWeapon(TArray<AWeaponsBase*> weaponArray)
{
	for (AWeaponsBase* weapon : weaponArray)
	{
		if (weapon->GetClass() == weaponType)
		{
			return weapon;
		}
	}

	return nullptr;
}
