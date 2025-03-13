// Fill out your copyright notice in the Description page of Project Settings.


#include "APortal.h"

// Sets default values
AAPortal::AAPortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAPortal::CreatePortal(FVector _pos, TSubclassOf<AAPortal> _portalType)
{
	if (IsValid(_portalType)) {
		
		AAPortal* newPortal = GetWorld()->SpawnActor<AAPortal>(_portalType);
		newPortal->SetActorLocation(_pos);
		// appeler une fonction pour set le type du portail
	}
}

void AAPortal::DestroyPortal()
{
}

void AAPortal::TeleportActor(AActor* _actor, AAPortal* _portal)
{
}

//// Called when the game starts or when spawned
//void AAPortal::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//void AAPortal::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//}


