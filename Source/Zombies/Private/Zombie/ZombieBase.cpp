// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombie/ZombieBase.h"
#include "Zombies/Public/Zombies/Game/ZombiesCustomGameMode.h"
#include "Components/CapsuleComponent.h"
#include "TimerManager.h"

// Sets default values
AZombieBase::AZombieBase()
{
	maxHealth = 100.0f;
	health = 100.0f;
	damage = 50.0f;

	despawnTime = 5.0f;
}


// Called when the game starts or when spawned
void AZombieBase::BeginPlay()
{
	Super::BeginPlay();
}

void AZombieBase::DestroyActor()
{
	Destroy();
}

void AZombieBase::Hit(AZombiesCharacter* attacker, FString hitBone)
{
	HandleBoneHits(attacker, hitBone);

	UE_LOG(LogTemp, Warning, TEXT("Bone Hit: %d"), attacker->GetPoints());

	FString pointsMessage = "Points: " + FString::FromInt(attacker->GetPoints());
}

void AZombieBase::HandleBoneHits(AZombiesCharacter* attacker, FString hitBone)
{
	//Headshots
	if (hitBone.Contains("head") || hitBone.Contains("neck"))
	{
		if (health <= 0)
		{
			attacker->IncreasePoints(100);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	//Body Hits
	if (hitBone.Contains("spine") || hitBone.Contains("pelvis"))
	{
		if (health <= 0)
		{
			attacker->IncreasePoints(60);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	//Limb Hits
	if (hitBone.Contains("_l") || hitBone.Contains("_r"))
	{
		if (health <= 0)
		{
			attacker->IncreasePoints(60);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
}

bool AZombieBase::DecreaseHealth(float value)
{
	if (health - value <= 0)
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AZombieBase::DestroyActor, 0.1f, false);
		return true;
	}
	else
	{
		health -= value;
		return false;
	}

	return false;
}

void AZombieBase::SetHealth(float newHealth)
{
	maxHealth = newHealth;
	health = maxHealth;
}

float AZombieBase::GetHealth()
{
	return health;
}

float AZombieBase::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float actualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	UE_LOG(LogTemp, Warning, TEXT("ActualDamage: %f"), actualDamage);

	if (actualDamage > 0.0f)
	{
		health -= actualDamage;

		if (health <= 0.0f)
		{
			Die();
		}
		else
		{
			//Deal with HUD stuff when HUD class is made in the future
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Zombie Health: %f"), health);
	return actualDamage;
}

void AZombieBase::Die()
{
	AZombiesCustomGameMode* gameMode = Cast<AZombiesCustomGameMode>(GetWorld()->GetAuthGameMode());
	if (gameMode)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameMode is fine"));
		gameMode->DecreaseRemainingMobs();
		gameMode->CheckRoundStatus();
	}

	if (GetMesh())
	{
		static FName CollisionProfileName(TEXT("Ragdoll"));
		GetMesh()->SetCollisionProfileName(CollisionProfileName);
	}
	SetActorEnableCollision(true);

	GetCapsuleComponent()->DestroyComponent();

	GetMesh()->SetSimulatePhysics(true);


	FTimerHandle despawnTimer;
	GetWorld()->GetTimerManager().SetTimer(despawnTimer, [this]
	{
		this->Destroy();
	}, despawnTime, false);
}
