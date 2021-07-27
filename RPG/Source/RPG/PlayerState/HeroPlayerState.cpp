// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroPlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RPG/Attributes/HeroPlayerAttributeSet.h"
#include "RPG/RPGCharacter.h"

AHeroPlayerState::AHeroPlayerState()
{
	// Create ability system component, and set it to be explicitly replicated
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSetBase = CreateDefaultSubobject<UHeroPlayerAttributeSet>(TEXT("AttributeSetBase"));
}

UAbilitySystemComponent* AHeroPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UHeroPlayerAttributeSet* AHeroPlayerState::GetAttributeSetBase() const
{
	return AttributeSetBase;
}

float AHeroPlayerState::GetMovementSpeed() const
{
	return AttributeSetBase->GetPlayerMovementSpeed();
}

float AHeroPlayerState::GetMovementSPeedMultiplier() const
{
	return AttributeSetBase->GetPlayerMovementMultiplier();
}

void AHeroPlayerState::BeginPlay()
{
	Super::BeginPlay();

	ARPGCharacter* Player = Cast<ARPGCharacter>(GetPawn());
	if (Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hero Player"));
		Player->GetCharacterMovement()->MaxWalkSpeed = 5000.0f;
	}
}
