// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMacCalc/MCC_Max_Mana.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interactions/CombatInterface.h"

UMCC_Max_Mana::UMCC_Max_Mana()
{
	IntDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	IntDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntDef.bSnapshot = false; // when do we want to capture the game play effect when its created or applied. false getting the value when its applied

	RelevantAttributesToCapture.Add(IntDef);
}

float UMCC_Max_Mana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Gather tags from source and target

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();

	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Intelligence = 0.f;
	GetCapturedAttributeMagnitude(IntDef, Spec, EvaluationParameters, Intelligence);
	Intelligence = FMath::Max<float>(Intelligence, 0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	return 50.f + 2.5f * Intelligence + 15.f * PlayerLevel;
}
