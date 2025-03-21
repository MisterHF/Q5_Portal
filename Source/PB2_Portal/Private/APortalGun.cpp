// Fill out your copyright notice in the Description page of Project Settings.

#include "APortalGun.h"
#include "Camera/CameraComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/GameplayStatics.h>

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
FVector AAPortalGun::CreateLineTrace(APlayerController* _playerController, FVector _startPosLineTrace, AActor* _self, AActor* _portalType)
{
    if (_playerController == nullptr || _portalType == nullptr)
        return FVector::Zero();

    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Hit Position: %s"), *_startPosLineTrace.ToString()));

    FRotator CameraRotation;
    FVector CameraLocation;
    _playerController->GetPlayerViewPoint(CameraLocation, CameraRotation);

    FHitResult Hit;
    FVector End = _startPosLineTrace + CameraRotation.Vector() * 2000.f;

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(_self);

    GetWorld()->LineTraceSingleByChannel(Hit, _startPosLineTrace, End, ECC_Visibility, CollisionParams);

    DrawDebugLine(GetWorld(), _startPosLineTrace, End, Hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 1.0f, 10.0f);

    if (Hit.bBlockingHit && IsValid(Hit.GetActor()))
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Hit Actor: %s"), *Hit.GetActor()->GetName()));

        FVector ImpactNormal = Hit.ImpactNormal;
        FVector PlayerPosition = CameraLocation;
        FVector LookDirection = PlayerPosition - ImpactNormal;
        FVector ProjectedForward;
        FQuat PortalRotation;
        FVector wallPos; 
        LookDirection.Z = 0; 

        FVector DirectionToPlayer = (CameraLocation - Hit.ImpactPoint).GetSafeNormal();


        /*if (Hit.GetActor() && Hit.GetActor()->ActorHasTag(TEXT("Wall")))
        {
            ProjectedForward = FVector::VectorPlaneProject(DirectionToPlayer, ImpactNormal).GetSafeNormal();
            PortalRotation = FRotationMatrix::MakeFromXY(ImpactNormal, ProjectedForward).ToQuat();
            wallPos = ImpactNormal * 70;
        }
        else
        {
        }*/
            ProjectedForward = FVector::VectorPlaneProject(DirectionToPlayer, ImpactNormal).GetSafeNormal();
            PortalRotation = FRotationMatrix::MakeFromXZ(ProjectedForward, ImpactNormal).ToQuat();
        _portalType->SetActorLocation(Hit.ImpactPoint + wallPos);

        GEngine->AddOnScreenDebugMessage(
            -1,
            15.0f,
            FColor::Yellow,
            FString::Printf(TEXT("Portal rotation: %s"), *PortalRotation.Vector().ToString())
        );
        _portalType->SetActorRotation(PortalRotation);
        return Hit.ImpactPoint;
    }

    return FVector::Zero();
}



