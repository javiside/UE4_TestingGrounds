// Copyright Javier Martinez 2017.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileCPP.generated.h"

UCLASS()
class TESTINGGROUNDS_API ATileCPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileCPP();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void PlaceActors(TSubclassOf<AActor> ToSpawn, int32 MinSpawn = 1, int32 MaxSpawn = 1, float Radius = 500);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	bool FindEmptyLocation(FVector &OutLocation, float Radius);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint);

	bool CanSpawnAtLocation(FVector Location, float Radius);	
};
