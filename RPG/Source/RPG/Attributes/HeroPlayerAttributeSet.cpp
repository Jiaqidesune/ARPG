// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroPlayerAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "RPG/RPGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UHeroPlayerAttributeSet::UHeroPlayerAttributeSet()
{
	
}

void UHeroPlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// This is called whenever attributes change, so for max health/mana we want to scale the current totals to match
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetPlayerMovementSpeedAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 150, 1000);
		//UE_LOG(LogTemp, Warning, TEXT("New Value %f"), NewValue);
	}
}