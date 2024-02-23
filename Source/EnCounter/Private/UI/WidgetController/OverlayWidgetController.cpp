// Copyright Mondea Sorin-Gabriel


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/EncounterAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UEncounterAttributeSet* EncounterAttributeSet = CastChecked<UEncounterAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(EncounterAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(EncounterAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(EncounterAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(EncounterAttributeSet->GetMaxMana());

}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UEncounterAttributeSet* EncounterAttributeSet = CastChecked<UEncounterAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		EncounterAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		EncounterAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		EncounterAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		EncounterAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data)
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data)
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}


