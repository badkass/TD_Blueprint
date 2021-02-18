// Fill out your copyright notice in the Description page of Project Settings.


#include "Composant_vie.h"

// Sets default values for this component's properties
UComposant_vie::UComposant_vie()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	DefaultHealth = 3;
	Vie = DefaultHealth;

}


// Called when the game starts
void UComposant_vie::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	if (Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UComposant_vie::TakeDamage);
	}

}

void UComposant_vie::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0)
	{
		return;
	}

	Vie = FMath::Clamp(Vie - Damage, 0.0f, DefaultHealth);

}