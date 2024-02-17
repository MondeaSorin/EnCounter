// Copyright Mondea Sorin-Gabriel


#include "Character/MainCharacter.h"

#include "AbilitySystem/EncounterAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/MainPlayerController.h"
#include "Player/MainPlayerState.h"
#include "UI/HUD/EncounterHUD.h"

AMainCharacter::AMainCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 450.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AMainCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
}

void AMainCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the client
	InitAbilityActorInfo();
}

void AMainCharacter::InitAbilityActorInfo()
{
	AMainPlayerState* PS = GetPlayerState<AMainPlayerState>();
	check(PS);
	PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
	AbilitySystemComponent = PS->GetAbilitySystemComponent();
	AttributeSet = PS->GetAttributeSet();

	if (AMainPlayerController* MPC = Cast<AMainPlayerController>(GetController()))
	{
		if (AEncounterHUD* EncounterHUD = Cast<AEncounterHUD>(MPC->GetHUD()))
		{
			EncounterHUD->InitOverlay(MPC, PS, AbilitySystemComponent, AttributeSet);
		}
	}
}
