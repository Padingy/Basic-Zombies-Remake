// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/WallBuy/InteractablesWallBuyBase.h"
#include "WallBuyM14.generated.h"

UCLASS()
class ZOMBIES_API AWallBuyM14 : public AInteractablesWallBuyBase
{
	GENERATED_BODY()

public:

	AWallBuyM14();

protected:

	virtual void BeginPlay() override;

	
		
public:
	
};
