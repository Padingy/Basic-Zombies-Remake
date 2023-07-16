// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/InteractablesBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

// Sets default values
AInteractablesBase::AInteractablesBase()
{
	skeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("InteractableSkeletalMeshComp"));
	RootComponent = skeletalMeshComp;

	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractableBoxCollider"));
	boxCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	boxCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
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
	return UIMessage;
}

// Called when the game starts or when spawned
void AInteractablesBase::BeginPlay()
{
	Super::BeginPlay();

	UIMessage = UIMessage + name + " for [ Cost " + FString::FromInt(cost) + " ]";
}


