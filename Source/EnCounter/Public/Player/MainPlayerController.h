// Copyright Mondea Sorin-Gabriel

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class ENCOUNTER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMainPlayerController();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> MainContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	
	UFUNCTION()
	void Move(const struct FInputActionValue& InputActionValue);
};
