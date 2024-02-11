// Copyright Mondea Sorin-Gabriel


#include "Player/MainPlayerState.h"

#include "AbilitySystem/EncounterAbilitySystemComponent.h"
#include "AbilitySystem/EncounterAttributeSet.h"

AMainPlayerState::AMainPlayerState()
{
	NetUpdateFrequency = 100.f; // how often the server updates the client

	AbilitySystemComponent = CreateDefaultSubobject<UEncounterAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UEncounterAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AMainPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
