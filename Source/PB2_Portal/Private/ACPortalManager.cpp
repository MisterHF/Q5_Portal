// Fill out your copyright notice in the Description page of Project Settings.


#include "ACPortalManager.h"

// Sets default values for this component's properties
UACPortalManager::UACPortalManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACPortalManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UACPortalManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AAPortal* UACPortalManager::GetConnectedPortalFrom(AAPortal* _portal)
{
	return nullptr;
}

void UACPortalManager::RegisterPortal(AAPortal* _portalToRegister)
{
}

void UACPortalManager::UnregisterPortal(AAPortal* _portalToRemove)
{
}

void UACPortalManager::DestroyPortail(TArray<AAPortal*>)
{
}



