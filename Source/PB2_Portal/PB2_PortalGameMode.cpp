// Copyright Epic Games, Inc. All Rights Reserved.

#include "PB2_PortalGameMode.h"
#include "PB2_PortalCharacter.h"
#include "UObject/ConstructorHelpers.h"

APB2_PortalGameMode::APB2_PortalGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
