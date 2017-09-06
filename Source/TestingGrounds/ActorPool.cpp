// Copyright Javier Martinez 2017.

#include "ActorPool.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor* UActorPool::CheckOut()
{
	UE_LOG(LogTemp, Warning, TEXT("%s checkout"), *(this->GetName()))
	return nullptr;
}
void UActorPool::Return(AActor* ActorToReturn)
{
	if (ActorToReturn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Returned null actor"), *(this->GetName()))
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] actor returned: %s"), *(this->GetName()), *ActorToReturn->GetName())
}

void UActorPool::Add(AActor* ActorToAdd)
{
	if (ActorToAdd == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Added null actor"), *(this->GetName()))
			return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor added: %s"), *(this->GetName()), *ActorToAdd->GetName())
}

