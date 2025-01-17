// Copyright Javier Martinez 2017.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TestingGroundsHUD.generated.h"

UCLASS()
class ATestingGroundsHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATestingGroundsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

