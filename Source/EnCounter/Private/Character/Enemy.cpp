// Copyright Mondea Sorin-Gabriel


#include "Character/Enemy.h"

AEnemy::AEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
