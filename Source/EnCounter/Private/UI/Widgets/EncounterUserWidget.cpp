// Copyright Mondea Sorin-Gabriel


#include "UI/Widgets/EncounterUserWidget.h"

void UEncounterUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
