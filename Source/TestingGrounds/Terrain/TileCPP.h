// Copyright Javier Martinez 2017.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileCPP.generated.h"

class UActorPool;

USTRUCT(BlueprintType)
struct FPlacingProperties
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placing Properties Struct")
	int32 MinSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placing Properties Struct")
	int32 MaxSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placing Properties Struct")
	float MinScale;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placing Properties Struct")
	float MaxScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placing Properties Struct")
	float Radius;

};

USTRUCT()
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()

	FVector Location;
	float Rotation;
	float Scale;
};

UCLASS()
class TESTINGGROUNDS_API ATileCPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileCPP();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, FPlacingProperties PlacingProperties);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
		FVector MinExtent;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
		FVector MaxExtent;

	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
		FVector NavigationBoundsOffset;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Pool")
		void SetPool(UActorPool* InPool);

private:

	TArray<FSpawnPosition> RandomSpawnPositions(FPlacingProperties PlacingProperties);

	bool FindEmptyLocation(FVector &OutLocation, float Radius);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FSpawnPosition SpawnPosition);

	bool CanSpawnAtLocation(FVector Location, float Radius);	

	void PositionNavMeshBoundsVolume();

	UActorPool* Pool = nullptr;

	AActor* NavMeshBoundsVolume = nullptr;
};