// Copyright Mondea Sorin-Gabriel


#include "Character/Enemy.h"

void AEnemy::HighlightActor()
{
	// highlights the actor

	if (UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(GetRootComponent()))
	{
		PrimitiveComponent->SetRenderCustomDepth(true);
	}
	
	UE_LOG(LogTemp, Warning, TEXT("HighlightActor"));

}

void AEnemy::UnhighlightActor()
{
	if (UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(GetRootComponent()))
	{
		PrimitiveComponent->SetRenderCustomDepth(false);
	}
	
	UE_LOG(LogTemp, Warning, TEXT("UnhighlightActor"));
	
}
