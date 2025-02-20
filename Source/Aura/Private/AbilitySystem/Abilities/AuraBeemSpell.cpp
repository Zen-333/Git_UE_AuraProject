// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AuraBeemSpell.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Interactions/CombatInterface.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"

void UAuraBeemSpell::StoreMouseDataInfo(const FHitResult& HitResult)
{
	if(HitResult.bBlockingHit)
	{
		MouseHitLocation = HitResult.ImpactPoint;
		MouseHitActor = HitResult.GetActor();
	}
	else
	{
		CancelAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true);
	}
}

void UAuraBeemSpell::StoreOwnerVariables()
{

	if(CurrentActorInfo)
	{
		OwnerPlayerController = CurrentActorInfo->PlayerController.Get();
		OwningCharacter = Cast<ACharacter>(CurrentActorInfo->AvatarActor);
	}
}

void UAuraBeemSpell::TraceFirstTarget(const FVector& BeamTargetLocation)
{
	check(OwningCharacter);

	if(OwningCharacter->Implements<UCombatInterface>())
	{
		if(USkeletalMeshComponent* Weapon = ICombatInterface::Execute_GetWeapon(OwningCharacter))
		{
			TArray<AActor*> ActorToIgnore;
			ActorToIgnore.Add(OwningCharacter);
			FHitResult HitResult;
			const FVector SocketLocation = Weapon->GetSocketLocation(FName("TipSocket"));
			UKismetSystemLibrary::SphereTraceSingle(OwningCharacter, 
				SocketLocation, 
				BeamTargetLocation, 
				10.f, 
				TraceTypeQuery1, 
				false, 
				ActorToIgnore, 
				EDrawDebugTrace::None, //EDrawDebugTrace::ForDuration, 
				HitResult,
				true);

			if(HitResult.bBlockingHit)
			{
				MouseHitLocation = HitResult.ImpactPoint;
				MouseHitActor = HitResult.GetActor();
			}
		}
	}

}

void UAuraBeemSpell::StoreAdditionalTarget(TArray<AActor*>& OutAdditionalTargets)
{
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetAvatarActorFromActorInfo());
	ActorsToIgnore.Add(MouseHitActor);

	TArray<AActor*> OverlappingActors;

	UAuraAbilitySystemLibrary::GetLivePlayerWithinRadius(GetAvatarActorFromActorInfo(), 
		OverlappingActors, 
		ActorsToIgnore,
		850.f,
		MouseHitActor->GetActorLocation());

	//int32 NumAdditionalTargets = FMath::Min(GetAbilityLevel() - 1, MaxNumShockTargets);

	int32 NumAdditionalTargets = 5;

	UAuraAbilitySystemLibrary::GetClosestTarget(NumAdditionalTargets, OverlappingActors, OutAdditionalTargets, MouseHitActor->GetActorLocation());
}
