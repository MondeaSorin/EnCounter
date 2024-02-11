// Copyright Mondea Sorin-Gabriel


#include "Character/BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon"); // TEXT macro is not needed here because the CreateDefaultSubobject function takes
																	   // an FName as an argument, which does not require TEXT macro, TEXT macro is used for FString
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

TObjectPtr<USkeletalMeshComponent> ABaseCharacter::GetWeaponMesh() const
{ 
	return Weapon;
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

