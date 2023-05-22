// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/InteractablesBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

// Sets default values
AInteractablesBase::AInteractablesBase()
{
	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponBoxCollider"));
	boxCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	boxCollider->SetHiddenInGame(true);
	boxCollider->SetupAttachment(RootComponent);


	UIMessage = "Hold F to buy ";
	name = "InteractableBase";
	cost = 500;
}

void AInteractablesBase::OnInteract(AZombiesCharacter* interactingPlayer)
{
	
}

FString AInteractablesBase::GetUIMessage(AZombiesCharacter* interactingPlayer)
{
	return FString();
}

// Called when the game starts or when spawned
void AInteractablesBase::BeginPlay()
{
	Super::BeginPlay();

	UIMessage = UIMessage + name + " for [ Cost " + FString::FromInt(cost) + " ]";
}


