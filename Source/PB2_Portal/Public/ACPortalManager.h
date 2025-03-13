// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "ACPortalManager.generated.h"

class AAPortal;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PB2_PORTAL_API UACPortalManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACPortalManager();
	AAPortal* portal;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	UFUNCTION(BlueprintCallable)
	AAPortal* GetConnectedPortalFrom(AAPortal* _portal);
	UFUNCTION(BlueprintCallable)
	void RegisterPortal(AAPortal* _portalToRegister);
	UFUNCTION(BlueprintCallable)
	void UnregisterPortal(AAPortal* _portalToRemove);
	UFUNCTION(BlueprintCallable)
	void DestroyPortail(TArray<AAPortal*> _portalArray);
};
