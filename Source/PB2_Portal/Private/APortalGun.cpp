// Fill out your copyright notice in the Description page of Project Settings.

#include "APortalGun.h"
#include "Camera/CameraComponent.h"

// Sets default values
AAPortalGun::AAPortalGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAPortalGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAPortalGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AAPortalGun::CreateLineTrace(APlayerController* _playerController, FVector _startPosLineTrace, AActor* _actor, TSubclassOf<AAPortal> _portalType)
{
	
	if (_playerController == nullptr && _portalType == nullptr) return FVector::Zero();

	FRotator CameraRotation;
	FVector CameraLocation;

	_playerController->GetPlayerViewPoint(CameraLocation, CameraRotation);
	
	
	FHitResult Hit;																								// Getting the Forward Vector, where the Actor is currently facing
																												// Get the Actors Location which will be our Starting point for the Trace
	
	FVector End = _startPosLineTrace + CameraRotation.Vector() * 1000.f;										// Combine both to have the full LineTrace
	FCollisionQueryParams CollisionParams;																		// define the collision
	CollisionParams.AddIgnoredActor(_actor);

	GetWorld()->LineTraceSingleByChannel(Hit, _startPosLineTrace, End, ECC_Visibility, CollisionParams);
																												// To vizualize the LineTrace in-game, lets also draw a DebugLine:
	DrawDebugLine(GetWorld(), _startPosLineTrace, End, Hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 1.0f, 10.0f);
	
	if (Hit.bBlockingHit && IsValid(Hit.GetActor()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Hit Actor: %s"), *Hit.GetActor()->GetName()));
		
		AAPortal* newPortal = GetWorld()->SpawnActor<AAPortal>(_portalType);
		if (IsValid(newPortal)) {
			newPortal->SetActorLocation(FVector(Hit.ImpactPoint));
			return FVector(Hit.GetActor()->GetActorLocation());
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("New portal cannot be NULL: ")));
		}
	}
	return FVector::Zero();
	
}

