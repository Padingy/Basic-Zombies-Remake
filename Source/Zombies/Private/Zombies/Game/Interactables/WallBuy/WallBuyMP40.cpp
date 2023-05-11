// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/WallBuy/WallBuyMP40.h"

AWallBuyMP40::AWallBuyMP40()
{
	name = "MP40";
	cost = 500;
	UIMessage = UIMessage + name + " for [Cost " + FString::FromInt(cost) + "]";
}

void AWallBuyMP40::BeginPlay()
{

}
