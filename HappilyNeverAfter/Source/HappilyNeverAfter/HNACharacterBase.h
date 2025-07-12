// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "HNACharacterBase.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class HAPPILYNEVERAFTER_API AHNACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AHNACharacterBase();

protected:
	virtual void BeginPlay() override;

	// Enhanced Input System
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PrimaryFireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SecondaryFireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* Ability1Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* Ability2Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* UltimateAction;

	// Hero Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stats")
	float MaxHealth = 200.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hero Stats")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stats")
	float HeroMovementSpeed = 600.0f;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Input callbacks
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void PrimaryFire(const FInputActionValue& Value);
	void SecondaryFire(const FInputActionValue& Value);
	void ActivateAbility1(const FInputActionValue& Value);
	void ActivateAbility2(const FInputActionValue& Value);
	void ActivateUltimate(const FInputActionValue& Value);

	// Health system
	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeDamage(float DamageAmount, class AController* EventInstigator = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void Heal(float HealAmount);

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercentage() const { return CurrentHealth / MaxHealth; }

	UFUNCTION(BlueprintPure, Category = "Health")
	bool IsAlive() const { return CurrentHealth > 0.0f; }

	// Events
	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	void OnHealthChanged(float NewHealth, float MaxHealth);

	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	void OnDeath();

	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	void OnPrimaryFire();

	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	void OnSecondaryFire();
};
