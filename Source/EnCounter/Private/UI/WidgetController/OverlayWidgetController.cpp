// Copyright Mondea Sorin-Gabriel


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/EncounterAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UEncounterAttributeSet* EncounterAttributeSet = CastChecked<UEncounterAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(EncounterAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(EncounterAttributeSet->GetMaxHealth());
	ManaChanged.Broadcast(EncounterAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(EncounterAttributeSet->GetMaxMana());

}
