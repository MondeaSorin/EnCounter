// Copyright Mondea Sorin-Gabriel

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class ENCOUNTER_API AEnemy : public ABaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AEnemy();

#pragma region EnemyInterface
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
#pragma endregion
	
protected:
	virtual void BeginPlay() override;
};
