// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Zombies/Game/ZombiesGameInstanceBase.h"

#include "Engine/World.h"

UZombiesGameInstanceBase::UZombiesGameInstanceBase()
{

}

void UZombiesGameInstanceBase::GoToMap(FString MapURL)
{
	GetWorld()->ServerTravel(MapURL);
}
