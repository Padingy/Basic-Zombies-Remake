// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/InteractablesBase.h"

// Sets default values
AInteractablesBase::AInteractablesBase()
{
	UIMessage = "Hold F to buy ";
	name = "InteractableBase";
	cost = 500;
}

// Called when the game starts or when spawned
void AInteractablesBase::BeginPlay()
{
	Super::BeginPlay();
	
}


