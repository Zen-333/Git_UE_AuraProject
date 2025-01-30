// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AuraFireBolt.h"
#include "AuraGameplayTags.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	int32 DDamage = GetDamageByDamageType(Level, FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetMananCost(Level));
	const float Cooldown = GetCooldown(Level);

	if (Level == 1)
	{
		return FString::Printf(TEXT("<Title>FIRE BOLT</>\n\n"

			"<Small>Level: </><Level> % d</>\n"
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			"<Default>Launches a bolt of fire, "
			"exploding on impact and dealing: </><Damage>%d </>"
			"<Default>fire damage with a chance to burn</>\n\n"),

			Level,
			ManaCost,
			Cooldown,
			DDamage 
			);

	}

	return FString::Printf(TEXT("<Title>FIRE BOLT</>\n\n"

		"<Small>Level: </><Level> % d</>\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

		"<Default>Launches %d bolts of fire, "
		"exploding on impact and dealing: </><Damage>%d </>"
		"<Default>fire damage with a chance to burn</>\n\n"),

		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		DDamage
	);
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	int32 DDamage = GetDamageByDamageType(Level, FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetMananCost(Level));
	const float Cooldown = GetCooldown(Level);

	return FString::Printf(TEXT("<Title>NEXT LEVEL: </>\n\n"

		"<Small>Level: </><Level> % d</>\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

		"<Default>Launches %d bolts of fire, "
		"exploding on impact and dealing: </><Damage>%d </>"
		"<Default>fire damage with a chance to burn</>\n\n"),

		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		DDamage
	);
}