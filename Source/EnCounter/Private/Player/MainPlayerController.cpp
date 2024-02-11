// Copyright Mondea Sorin-Gabriel


#include "Player/MainPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Interaction/EnemyInterface.h"

AMainPlayerController::AMainPlayerController()
{
	bReplicates = true;
	LastActor = nullptr;
	ThisActor = nullptr;
}

void AMainPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(MainContext);

	// subsystems are singletons, enhanced input local player subsystem is what we can use to add mapping contexts
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	// the difference between check and normal if statement is that check will crash the game if the condition is not met
	Subsystem->AddMappingContext(MainContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	// bind the action to the function
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainPlayerController::Move);
	
}

void AMainPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// this is a callback function that will be called when the action is triggered
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// the following vectors are normalized
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Print the values of InputAxisVector.Y and InputAxisVector.X to the console -- DEGUBGING
	//UE_LOG(LogTemp, Warning, TEXT("InputAxisVector.Y: %f, InputAxisVector.X: %f"), InputAxisVector.Y, InputAxisVector.X);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
	
}

void AMainPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	/**
	 * Line trace from cursor. There are several scenarios:
	 * A. LastActor is null && ThisActor is null
	 *		- Do nothing.
	 * B. LastActor is null && ThisActor valid
	 *		- Call HighlightActor on ThisActor.
	 * C. LastActor valid && ThisActor is null
	 *		 - Call UnhighlightActor on LastActor.
	 * D. LastActor valid && ThisActor valid
	 *		 - If LastActor is different from ThisActor, call UnhighlightActor on LastActor and HighlightActor on ThisActor.
	 *		 - If LastActor is the same as ThisActor, do nothing.
	 */

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Case B
			ThisActor->HighlightActor();
		}
		else
		{
			// Case A
			// Do nothing
		}
	}
	else
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnhighlightActor();
		}
		else
		{
			if (LastActor != ThisActor)
			{
				// Case D - different actors
				LastActor->UnhighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case D - both are the same
				// Do nothing
			}
		}
	}
}
