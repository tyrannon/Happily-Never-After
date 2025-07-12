// Fill out your copyright notice in the Description page of Project Settings.

#include "HNAGameMode.h"
#include "HNACharacterBase.h"
#include "UObject/ConstructorHelpers.h"

AHNAGameMode::AHNAGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AHNACharacterBase::StaticClass();
}

