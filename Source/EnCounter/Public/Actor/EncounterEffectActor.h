// Copyright Mondea Sorin-Gabriel

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EncounterEffectActor.generated.h"

class USphereComponent;

UCLASS()
class ENCOUNTER_API AEncounterEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AEncounterEffectActor();

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
