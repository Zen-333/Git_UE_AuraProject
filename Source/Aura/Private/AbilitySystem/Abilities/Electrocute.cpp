// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/Electrocute.h"
#include "AbilitySystem/Abilities/Electrocute.h"

FString UElectrocute::GetDescription(int32 Level)
{
	int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetMananCost(Level));
	const float Cooldown = GetCooldown(Level);

	if (Level == 1)
	{
		return FString::Printf(TEXT("<Title>ELECTROCUTE</>\n\n"

			"<Small>Level: </><Level> % d</>\n"
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			"<Default>Emits a beam of lightning, "
			"conncecting with the target, repeatedly causing: </><Damage>%d </>"
			"<Default>lightning damage with a chance to stun</>\n\n"),

			Level,
			ManaCost,
			Cooldown,
			ScaledDamage
		);

	}
	else
	{

		return FString::Printf(TEXT("<Title>ELECTROCUTE</>\n\n"

			"<Small>Level: </><Level> % d</>\n"
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			"<Default>Emits a beam of lightning, "
			"propagating to %d additional targets nearby, causing: </><Damage>%d </>"
			"<Default>lightning damage with a chance to stun</>\n\n"),

			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShockTargets - 1),
			ScaledDamage
		);
	}
}

FString UElectrocute::GetNextLevelDescription(int32 Level)
{
	int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetMananCost(Level));
	const float Cooldown = GetCooldown(Level);

	return FString::Printf(TEXT("<Title>NEXT LEVEL</>\n\n"

		"<Small>Level: </><Level> % d</>\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

		"<Default>Emits a beam of lightning, "
		"propagating to %d additional targets nearby, causing: </><Damage>%d </>"
		"<Default>lightning damage with a chance to stun</>\n\n"),

		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, MaxNumShockTargets - 1),
		ScaledDamage);
}
