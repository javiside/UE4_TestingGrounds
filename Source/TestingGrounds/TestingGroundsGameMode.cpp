// Copyright Javier Martinez 2017.

#include "TestingGroundsGameMode.h"
#include "TestingGroundsHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestingGroundsGameMode::ATestingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Character/Behaviour/BP_Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroundsHUD::StaticClass();
}
