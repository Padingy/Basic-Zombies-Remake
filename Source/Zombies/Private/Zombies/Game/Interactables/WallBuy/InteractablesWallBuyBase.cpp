// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/WallBuy/InteractablesWallBuyBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Engine/GameInstance.h"

AInteractablesWallBuyBase::AInteractablesWallBuyBase()
{
	staticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallBuyStaticMesh"));
	staticMeshComp->SetOnlyOwnerSee(false);
	staticMeshComp->bCastDynamicShadow = false;
	staticMeshComp->CastShadow = false;
	RootComponent = staticMeshComp;

	skeletalMeshComp->SetupAttachment(RootComponent);
	skeletalMeshComp->SetRelativeLocation(FVector(-22.0f, -6.0f, -5.0f));
	skeletalMeshComp->SetHiddenInGame(true);

	boxCollider->SetupAttachment(RootComponent);
	boxCollider->SetRelativeScale3D(FVector(2.0f, 1.0f, 1.25f));
	boxCollider->SetRelativeLocation(FVector(-7.0f, 21.0f, 0.0f));

	animSpeed = 25.0f;
}


//TODO: Refactor this to put the For loop into its own class.
void AInteractablesWallBuyBase::OnInteract(AZombiesCharacter* interactingPlayer)
{
	Super::OnInteract(interactingPlayer);
	//Weapon mesh coming out of the wall over time when bought animation handling
	if (skeletalMeshComp->GetRelativeLocation() != animEndLocation)
	{
		skeletalMeshComp->SetHiddenInGame(false);
		GetWorld()->GetTimerManager().SetTimer(animTimerHandle, [this] {
			UGameInstance* gameInstance = GetGameInstance();

			skeletalMeshComp->SetRelativeLocation(FMath::VInterpTo(skeletalMeshComp->GetRelativeLocation(), animEndLocation, gameInstance->GetWorld()->GetDeltaSeconds(), animSpeed));

			if (skeletalMeshComp->GetRelativeLocation() == animEndLocation)
			{
				GetWorld()->GetTimerManager().ClearTimer(animTimerHandle);
			}
		}, 0.05, true);
	}

	//Logic for if player doesnt have all weapon slots available filled 
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
	//Logic for if player does have all available weapon slots filled
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

	animStartLocation = skeletalMeshComp->GetRelativeLocation();
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
