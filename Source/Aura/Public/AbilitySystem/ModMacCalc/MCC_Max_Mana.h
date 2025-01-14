// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MCC_Max_Mana.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMCC_Max_Mana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:

	UMCC_Max_Mana();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

	FGameplayEffectAttributeCaptureDefinition IntDef;
};
