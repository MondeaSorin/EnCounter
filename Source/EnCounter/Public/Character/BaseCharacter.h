// Copyright Mondea Sorin-Gabriel

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

// Forward declarations
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class ENCOUNTER_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	
	TObjectPtr<USkeletalMeshComponent> GetWeaponMesh() const;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	virtual void BeginPlay() override;

	// same as raw pointer, in editor has additional features : access tracking -> we can track how often a pointer is accessed or dereferenced
	//                                                            lazy loading  -> asset is not loaded until it is needed       
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet; 
};
