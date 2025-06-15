
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"

#include "AuraEffectActor.generated.h"


class UGameplayEffect;
class UAbilitySystemComponent;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy 
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply,
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy
{
	RemoveOnEndOverlap,
	DoNotRemove
};


UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AAuraEffectActor();

	virtual void Tick(float DeltaTime) override;
	
protected:

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	FVector CalculatedLocation;

	UPROPERTY(BlueprintReadWrite)
	FRotator CalculatedRotation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickUp")
	bool bRotates = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickUp")
	float RotationRate = 45.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickUp")
	bool bSinusoidalMovement = false;

	UFUNCTION(BlueprintCallable)
	void StartSimusoidalMovement();

	UFUNCTION(BlueprintCallable)
	void StartRotation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickUp")
	float SineAmplitude = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickUp")
	float SinePeriodConstant = 1.f; // 2 pi

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickUp")
	FVector InitialLocation;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	bool bDestroyOnEffectApplication = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	bool bApplyEffectsToEnemies = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemoveOnEndOverlap;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Applied Effects")
	float ActorLevel = 1.f;

private:

	float RunningTime = 0.f;
	void ItemMovement(float DeltaTime);
	
};
