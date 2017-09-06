// Copyright Javier Martinez 2017.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorPool.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TESTINGGROUNDS_API UActorPool : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UActorPool();

	AActor* CheckOut();
	void Return(AActor* ActorToReturn);

	void Add(AActor* ActorToAdd);

private:
	TArray<AActor*> Pool;
};
