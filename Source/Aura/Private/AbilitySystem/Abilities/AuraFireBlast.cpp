// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AuraFireBlast.h"

#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Actor/AuraFireBall.h"

FString UAuraFireBlast::GetDescription(int32 Level)
{

	int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetMananCost(Level));
	const float Cooldown = GetCooldown(Level);

	
	return FString::Printf(TEXT("<Title>FIRE BLAST</>\n\n"

		"<Small>Level: </><Level> % d</>\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

		"<Default>Launches %d, "
		"fire balls in all directions, each coming back and</><Damage>%d </>"
		"<Default>exploding upon retunr, causing <Damage>%d </> radial fire damage with a chance to burn</>\n\n"),

		Level,
		ManaCost,
		Cooldown,
		NumFireBalls,
		ScaledDamage
	);

	

}

FString UAuraFireBlast::GetNextLevelDescription(int32 Level)
{
	int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetMananCost(Level));
	const float Cooldown = GetCooldown(Level);


	return FString::Printf(TEXT("<Title>NEXT LEVEL</>\n\n"

		"<Small>Level: </><Level> % d</>\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

		"<Default>Launches %d, "
		"fire balls in all directions, each coming back and</><Damage>%d </>"
		"<Default>exploding upon retunr, causing <Damage>%d </> radial fire damage with a chance to burn</>\n\n"),

		Level,
		ManaCost,
		Cooldown,
		NumFireBalls,
		ScaledDamage
	);
}

TArray<AAuraFireBall*> UAuraFireBlast::SpawnFireBalls()
{
	TArray<AAuraFireBall*> FireBalls;

	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();
	TArray<FRotator> Rotators = UAuraAbilitySystemLibrary::EvenlySpacedRotators(Forward, FVector::UpVector, 360.f, NumFireBalls);

	for(const FRotator& Rotator : Rotators)
	{
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(Location);
		SpawnTransform.SetRotation(Rotator.Quaternion());

		AAuraFireBall* FireBall = GetWorld()->SpawnActorDeferred<AAuraFireBall>(
			FireBallClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			CurrentActorInfo->PlayerController->GetPawn(),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn
		);

		FireBall->DamageEffectParams = MakeDamageEffectParamsFromClassDefaults();
		FireBall->ReturnToActor = GetAvatarActorFromActorInfo();

		FireBall->ExplosionDamageParams = MakeDamageEffectParamsFromClassDefaults();
		FireBall->SetOwner(GetAvatarActorFromActorInfo());
		FDamageEffectParams ExplosionDamageEffectParams = MakeDamageEffectParamsFromClassDefaults();

		FireBalls.Add(FireBall);

		FireBall->FinishSpawning(SpawnTransform);
	}

	return FireBalls;
}
