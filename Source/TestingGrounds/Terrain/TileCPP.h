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
	int32 MinSpawn = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placing Properties Struct")
	int32 MaxSpawn = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placing Properties Struct")
	float MinScale = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placing Properties Struct")
	float MaxScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placing Properties Struct")
	float Radius = 500.0f;

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

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, FPlacingProperties PlacingProperties);

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void PlaceAIPawns(TSubclassOf<APawn> AIToSpawn, int32 MinSpawn, int32 MaxSpawn);

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

	bool FindEmptyLocation(FVector &OutLocation, float Radius);

	template<class T>
	void RandomlyPlaceActor(TSubclassOf<T> ToSpawn, FPlacingProperties PlacingProperties);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FSpawnPosition SpawnPosition);
	void PlaceActor(TSubclassOf<APawn>  ToSpawn, FSpawnPosition SpawnPosition);

	bool CanSpawnAtLocation(FVector Location, float Radius);	

	void PositionNavMeshBoundsVolume();

	UActorPool* Pool = nullptr;

	AActor* NavMeshBoundsVolume = nullptr;
};