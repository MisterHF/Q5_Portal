// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "APortal.generated.h"

UCLASS()
class PB2_PORTAL_API AAPortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAPortal();

	

//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;

	//Variable
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal")
	AAPortal* connectedPortal;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal")
	bool isActive;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal")
	FVector portalNormal;


	//UFUNCTION(BlueprintCallable)
	//AAPortal* CreatePortal(FVector _pos, TSubclassOf<AAPortal> _portalType);

protected:
	//Function
	
	UFUNCTION(BlueprintCallable)
	void TeleportActor(AActor* _actor, AAPortal* _portal);
};
