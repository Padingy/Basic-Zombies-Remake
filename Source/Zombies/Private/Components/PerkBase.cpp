// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PerkBase.h"

APerkBase::APerkBase()
{
	name = TEXT("PerkBase");
}

void APerkBase::UpdatePerk(AActor* owner)
{
	
}

void APerkBase::RemovePerk(AActor* owner)
{
	
}

FName APerkBase::GetName() const
{
	return name;
}
