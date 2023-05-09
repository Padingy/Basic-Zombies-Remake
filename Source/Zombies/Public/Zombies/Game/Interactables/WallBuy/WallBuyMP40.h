// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/WallBuy/InteractablesWallBuyBase.h"
#include "WallBuyMP40.generated.h"

UCLASS()
class ZOMBIES_API AWallBuyMP40 : public AInteractablesWallBuyBase
{
	GENERATED_BODY()

public:

	AWallBuyMP40();

protected:

	virtual void BeginPlay() override;


public:

	
};
