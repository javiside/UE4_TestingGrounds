// Copyright Javier Martinez 2017.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterCPP.generated.h"


UCLASS()
class TESTINGGROUNDS_API ACharacterCPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class AGun> GunBlueprint;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void PullTrigger();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class AGun* Gun;
};
