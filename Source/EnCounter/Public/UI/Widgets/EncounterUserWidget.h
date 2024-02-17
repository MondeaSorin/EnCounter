// Copyright Mondea Sorin-Gabriel

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EncounterUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class ENCOUNTER_API UEncounterUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
