// Copyright Mondea Sorin-Gabriel


#include "Actor/EncounterEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/EncounterAttributeSet.h"
#include "Components/SphereComponent.h"

AEncounterEffectActor::AEncounterEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	SetRootComponent(Mesh);
	Sphere->SetupAttachment(Mesh);
}

void AEncounterEffectActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// todo: Change this to apply a gameplay effect. For now, we use const_cast just to be able to modify the health attribute.
	if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UEncounterAttributeSet* EncounterAttributeSet = Cast<UEncounterAttributeSet>(AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(UEncounterAttributeSet::StaticClass()));

		// bad practice, but we don't have a gameplay effect yet
		UEncounterAttributeSet* EncounterAttributeSetNonConst = const_cast<UEncounterAttributeSet*>(EncounterAttributeSet);
		EncounterAttributeSetNonConst->SetHealth(EncounterAttributeSet->GetHealth() - 10.f);
		EncounterAttributeSetNonConst->SetMana(EncounterAttributeSet->GetMana() - 10.f);
		Destroy();
	}
}

void AEncounterEffectActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AEncounterEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AEncounterEffectActor::OnOverlapBegin);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AEncounterEffectActor::OnOverlapEnd);
}

