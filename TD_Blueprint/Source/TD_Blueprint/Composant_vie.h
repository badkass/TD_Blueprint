// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Composant_vie.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_BLUEPRINT_API UComposant_vie : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComposant_vie();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vie")
		float DefaultHealth;

	UPROPERTY(BlueprintReadOnly)
		float Vie;
	UFUNCTION()
		void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};
