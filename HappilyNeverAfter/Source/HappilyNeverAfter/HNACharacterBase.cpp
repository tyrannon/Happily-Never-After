// Fill out your copyright notice in the Description page of Project Settings.

#include "HNACharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AHNACharacterBase::AHNACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set default movement values
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxWalkSpeed = HeroMovementSpeed;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;

	// Initialize health
	CurrentHealth = MaxHealth;

	// Don't rotate when the controller rotates (Overwatch-style camera)
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
}

void AHNACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}

	// Initialize health
	CurrentHealth = MaxHealth;
	OnHealthChanged(CurrentHealth, MaxHealth);
}

void AHNACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHNACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		if (JumpAction)
		{
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		}

		// Moving
		if (MoveAction)
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHNACharacterBase::Move);
		}

		// Looking
		if (LookAction)
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AHNACharacterBase::Look);
		}

		// Combat
		if (PrimaryFireAction)
		{
			EnhancedInputComponent->BindAction(PrimaryFireAction, ETriggerEvent::Triggered, this, &AHNACharacterBase::PrimaryFire);
		}

		if (SecondaryFireAction)
		{
			EnhancedInputComponent->BindAction(SecondaryFireAction, ETriggerEvent::Triggered, this, &AHNACharacterBase::SecondaryFire);
		}

		// Abilities
		if (Ability1Action)
		{
			EnhancedInputComponent->BindAction(Ability1Action, ETriggerEvent::Triggered, this, &AHNACharacterBase::ActivateAbility1);
		}

		if (Ability2Action)
		{
			EnhancedInputComponent->BindAction(Ability2Action, ETriggerEvent::Triggered, this, &AHNACharacterBase::ActivateAbility2);
		}

		if (UltimateAction)
		{
			EnhancedInputComponent->BindAction(UltimateAction, ETriggerEvent::Triggered, this, &AHNACharacterBase::ActivateUltimate);
		}
	}
}

void AHNACharacterBase::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AHNACharacterBase::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AHNACharacterBase::PrimaryFire(const FInputActionValue& Value)
{
	if (!IsAlive()) return;
	
	// Call Blueprint event for hero-specific implementation
	OnPrimaryFire();
}

void AHNACharacterBase::SecondaryFire(const FInputActionValue& Value)
{
	if (!IsAlive()) return;
	
	// Call Blueprint event for hero-specific implementation
	OnSecondaryFire();
}

void AHNACharacterBase::ActivateAbility1(const FInputActionValue& Value)
{
	if (!IsAlive()) return;
	
	// TODO: Implement ability system
}

void AHNACharacterBase::ActivateAbility2(const FInputActionValue& Value)
{
	if (!IsAlive()) return;
	
	// TODO: Implement ability system
}

void AHNACharacterBase::ActivateUltimate(const FInputActionValue& Value)
{
	if (!IsAlive()) return;
	
	// TODO: Implement ability system
}

void AHNACharacterBase::TakeDamage(float DamageAmount, AController* EventInstigator)
{
	if (!IsAlive() || DamageAmount <= 0.0f) return;

	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.0f, MaxHealth);
	OnHealthChanged(CurrentHealth, MaxHealth);

	if (CurrentHealth <= 0.0f)
	{
		OnDeath();
	}
}

void AHNACharacterBase::Heal(float HealAmount)
{
	if (!IsAlive() || HealAmount <= 0.0f) return;

	CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, 0.0f, MaxHealth);
	OnHealthChanged(CurrentHealth, MaxHealth);
}

