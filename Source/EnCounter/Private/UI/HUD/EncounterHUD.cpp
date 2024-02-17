 // Copyright Mondea Sorin-Gabriel


#include "UI/HUD/EncounterHUD.h"

#include "UI/WidgetController/OverlayWidgetController.h"
#include "UI/Widgets/EncounterUserWidget.h"

UOverlayWidgetController* AEncounterHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
	}

	return OverlayWidgetController;
}

void AEncounterHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC,
	UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not initialized, please fill out BP_EncounderHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is not initialized, please fill out BP_EncounderHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UEncounterUserWidget>(Widget);

	const FWidgetControllerParams WCParams(PC, PS, ASC, AS);
	UOverlayWidgetController* Controller = GetOverlayWidgetController(WCParams);

	OverlayWidget->SetWidgetController(Controller);
	Controller->BroadcastInitialValues();
	Widget->AddToViewport();
}
