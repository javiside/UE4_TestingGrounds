// Copyright Javier Martinez 2017.

#include "TileCPP.h"
#include "ActorPool.h"
#include "AI/Navigation/NavigationSystem.h"

// Sets default values
ATileCPP::ATileCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NavigationBoundsOffset = FVector(2000, 0, 0);

	MinExtent = FVector(0, -2000, 0); // TODO make Y parameters
	MaxExtent = FVector(4000, 2000, 0);
}

void ATileCPP::SetPool(UActorPool* InPool)
{
	Pool = InPool;

	PositionNavMeshBoundsVolume();
}

void ATileCPP::PositionNavMeshBoundsVolume()
{
	NavMeshBoundsVolume = Pool->CheckOut();
	if (NavMeshBoundsVolume == nullptr)
	{
		return;
	}
	NavMeshBoundsVolume->SetActorLocation(GetActorLocation() + NavigationBoundsOffset);
	GetWorld()->GetNavigationSystem()->Build();
}

void ATileCPP::PlaceActors(TSubclassOf<AActor> ToSpawn, FPlacingProperties PlacingProperties)
{
		RandomlyPlaceActor(ToSpawn, PlacingProperties);
}

void ATileCPP::PlaceAIPawns(TSubclassOf<APawn> AIToSpawn, int32 MinSpawn, int32 MaxSpawn)
{
	FPlacingProperties PlacingAIProperties;
	PlacingAIProperties.MaxSpawn = MinSpawn;
	PlacingAIProperties.MinScale = MaxSpawn;
	PlacingAIProperties.MinScale = 1.0f;
	PlacingAIProperties.MaxScale = 1.0f;
	PlacingAIProperties.Radius = 200.0f;

	RandomlyPlaceActor(AIToSpawn, PlacingAIProperties);
}

template<class T>
void ATileCPP::RandomlyPlaceActor(TSubclassOf<T> ToSpawn, FPlacingProperties PlacingProperties)
{
	int32 NumberToSpawn = FMath::RandRange(PlacingProperties.MinSpawn, PlacingProperties.MaxSpawn);
	for (size_t i = 0; i < NumberToSpawn; i++)
	{
		FSpawnPosition SpawnPosition;
		SpawnPosition.Scale = FMath::RandRange(PlacingProperties.MinScale, PlacingProperties.MaxScale);
		bool Found = FindEmptyLocation(SpawnPosition.Location, PlacingProperties.Radius * SpawnPosition.Scale);
		
		if (Found)
		{
			SpawnPosition.Rotation = FMath::RandRange(-180.0f, 180.0f);
			PlaceActor(ToSpawn, SpawnPosition);
		}
	}
}

bool ATileCPP::FindEmptyLocation(FVector &OutLocation, float Radius)
{
	FBox Bounds(MinExtent, MaxExtent);

	int32 const MAX_ATTEMPTS = 100;
	for (size_t i = 0; i < MAX_ATTEMPTS; i++)
	{
		FVector CandidatePoint = FMath::RandPointInBox(Bounds);
		if (CanSpawnAtLocation(CandidatePoint, Radius))
		{
			OutLocation = CandidatePoint + FVector(0, 0, 5);
			return true;
		}
	}
	return false;
}

void ATileCPP::PlaceActor(TSubclassOf<AActor> ToSpawn, FSpawnPosition SpawnPosition)
{
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	if (Spawned)
	{
		Spawned->SetActorRelativeLocation(SpawnPosition.Location);
		Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
		Spawned->SetActorRotation(FRotator(0, SpawnPosition.Rotation, 0));
		Spawned->SetActorScale3D(FVector(SpawnPosition.Scale));
	}
}

void ATileCPP::PlaceActor(TSubclassOf<APawn> ToSpawn, FSpawnPosition SpawnPosition)
{

	APawn* Spawned = GetWorld()->SpawnActor<APawn>(ToSpawn);
	if (Spawned)
	{
		Spawned->SetActorRelativeLocation(SpawnPosition.Location);
		Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
		Spawned->SetActorRotation(FRotator(0, SpawnPosition.Rotation, 0));
		Spawned->SetActorScale3D(FVector(SpawnPosition.Scale));

		Spawned->SpawnDefaultController();
		Spawned->Tags.Add(FName("Enemy"));
	}
}

// Called when the game starts or when spawned
void ATileCPP::BeginPlay()
{
	Super::BeginPlay();
}

void ATileCPP::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (!Pool || !NavMeshBoundsVolume) { return; }
	Pool->Return(NavMeshBoundsVolume);
}

// Called every frame
void ATileCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATileCPP::CanSpawnAtLocation(FVector Location, float Radius)
{
	FHitResult HitResult;

	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);

	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
	);

	FColor ResultColor = HasHit ? FColor::Red : FColor::Green;
	return !HasHit;
}
