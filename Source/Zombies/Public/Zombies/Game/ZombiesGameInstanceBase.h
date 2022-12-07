// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ZombiesGameInstanceBase.generated.h"

USTRUCT(BlueprintType)
struct FMapInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString MapURL;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString MapName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString MapDescription;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UTexture2D* MapImage;
};

UCLASS()
class ZOMBIES_API UZombiesGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UZombiesGameInstanceBase();

protected:
	UFUNCTION(BlueprintCallable)
		void GoToMap(FString MapURL);
};
