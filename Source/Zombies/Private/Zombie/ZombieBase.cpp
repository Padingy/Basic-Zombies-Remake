// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombie/ZombieBase.h"
#include "Engine/Engine.h"
#include "TimerManager.h"

// Sets default values
AZombieBase::AZombieBase()
{
}


// Called when the game starts or when spawned
void AZombieBase::BeginPlay()
{
	Super::BeginPlay();
	
	maxHealth = 100.0f;
	health = 100.0f;
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

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, pointsMessage);


	//DecreaseHealth(50.0f);
}

void AZombieBase::HandleBoneHits(AZombiesCharacter* attacker, FString hitBone)
{
	//Head
	if (hitBone == "head")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(100);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	//Torso
	else if (hitBone == "spine_01")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(60);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "spine_02")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(60);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	//Left Arm
	else if (hitBone == "upperarm_l")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "lowerarm_l")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "hand_l")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	//Right Arm
	else if (hitBone == "upperarm_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "lowerarm_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "hand_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	//Pelvis
	else if (hitBone == "pelvis")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	//Left Leg
	else if (hitBone == "upperarm_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "lowerarm_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "hand_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	//Left Leg
	else if (hitBone == "thigh_l")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "calf_l")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "foot_l")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "ball_l")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	//Right Leg
	else if (hitBone == "thigh_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "calf_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "foot_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else if (hitBone == "ball_r")
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
		}
		else
		{
			attacker->IncreasePoints(10);
		}
	}
	else
	{
		if (DecreaseHealth(10.0f))
		{
			attacker->IncreasePoints(50);
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

float AZombieBase::GetHealth()
{
	return health;
}
