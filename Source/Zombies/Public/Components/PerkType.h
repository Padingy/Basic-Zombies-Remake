#pragma once

#include "PerkType.generated.h"

UENUM(blueprintType)
enum class EPerkType : uint8
{
	StaminUp UMETA(DisplayName = "StaminUp"),
	Juggernog UMETA(DisplayName = "Juggernog")
};