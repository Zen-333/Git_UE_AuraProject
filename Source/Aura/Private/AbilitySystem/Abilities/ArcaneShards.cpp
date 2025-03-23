// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetMananCost(Level));
	const float Cooldown = GetCooldown(Level);

	if (Level == 1)
	{
		return FString::Printf(TEXT("<Title>ARCANE SHARDS</>\n\n"

			"<Small>Level: </><Level> % d</>\n"
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			"<Default>Summon a Shard of arcane energy, "
			"causing radial arcane damage of: </><Damage>%d </>"
			"<Default>at the shard origin.</>\n\n"),

			Level,
			ManaCost,
			Cooldown,
			ScaledDamage
		);

	}
	else
	{

		return FString::Printf(TEXT("<Title>ARCANE SHARDS</>\n\n"

			"<Small>Level: </><Level> % d</>\n"
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			"<Default>Summon %d shards of arcane energy, "
			"causing: </><Damage>%d </>"
			"<Default> radial arcane damage at the shard origin</>\n\n"),

			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShards),
			ScaledDamage
		);
	}
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
{
	int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetMananCost(Level));
	const float Cooldown = GetCooldown(Level);

	return FString::Printf(TEXT("<Title>NEXT LEVEL</>\n\n"

		"<Small>Level: </><Level> % d</>\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

		"<Default>Summon %d shards of arcane energy, "
		"causing: </><Damage>%d </>"
		"<Default> radial arcane damage at the shard origin</>\n\n"),

		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, MaxNumShards),
		ScaledDamage
	);
}
