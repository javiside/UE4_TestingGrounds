// Copyright Javier Martinez 2017.

#include "CharacterCPP.h"
#include "Weapons/Gun.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ACharacterCPP::ACharacterCPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a CameraComponent	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("RightEye"));
	CameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ACharacterCPP::BeginPlay()
{
	Super::BeginPlay();

	if (!GunBlueprint) {
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint missing."));
		return;
	}
	Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	Gun->AnimInstance3P = GetMesh()->GetAnimInstance();
}

// Called every frame
void ACharacterCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterCPP::PullTrigger()
{
	Gun->OnFire();
	MakeNoise(1.0f, this, GetActorLocation());
}