// Copyright Epic Games, Inc. All Rights Reserved.

#include "rts2GameMode.h"
#include "rts2Character.h"
#include "UObject/ConstructorHelpers.h"

Arts2GameMode::Arts2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
