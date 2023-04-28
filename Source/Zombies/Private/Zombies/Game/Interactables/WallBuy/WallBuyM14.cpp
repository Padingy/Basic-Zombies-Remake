// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/WallBuy/WallBuyM14.h"

AWallBuyM14::AWallBuyM14()
{
	name = "M14";
	cost = 500;
	UIMessage = UIMessage + name + " for [Cost " + FString::FromInt(cost) + "]";
}

void AWallBuyM14::BeginPlay()
{

}
