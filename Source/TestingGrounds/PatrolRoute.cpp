// Copyright Francisco Javier Martinez 2017.

#include "PatrolRoute.h"

TArray<AActor*> UPatrolRoute::GetPatrolPoints() const
{
	return PatrolPoints;
}