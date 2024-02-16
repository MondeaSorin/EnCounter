// Copyright Mondea Sorin-Gabriel


#include "Character/Enemy.h"

#include "AbilitySystem/EncounterAbilitySystemComponent.h"
#include "AbilitySystem/EncounterAttributeSet.h"

AEnemy::AEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UEncounterAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UEncounterAttributeSet>("AttributeSet");
	// AttributeSet->SetIsReplicated(true);
	
}

void AEnemy::HighlightActor()
{
	// highlights the actor

	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250);

	GetWeaponMesh()->SetRenderCustomDepth(true);
	GetWeaponMesh()->SetCustomDepthStencilValue(250);

	// debug line
	// UE_LOG(LogTemp, Warning, TEXT("HighlightActor"));

}

void AEnemy::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	GetWeaponMesh()->SetRenderCustomDepth(false);
	
	// debug line
	//UE_LOG(LogTemp, Warning, TEXT("UnhighlightActor"));
	
}
