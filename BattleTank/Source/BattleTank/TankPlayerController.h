// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;

private:

	ATank* GetControlledTank() const;

	/*	Start the tank moving the barrel so that a shot
	*	would hit where the crosshair intersects the world
	*/
	void AimTowardsCrosshair();
	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& outHitLocation) const;
	bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;
	bool GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float crosshairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
	float crosshairYLocation = 0.3333f;

	UPROPERTY(EditDefaultsOnly)
	float lineTraceRange = 1000000.0f;
};
