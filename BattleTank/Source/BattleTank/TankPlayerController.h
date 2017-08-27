// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
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

	UPROPERTY(EditAnywhere)
	float crosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float crosshairYLocation = 0.3333f;

	UPROPERTY(EditAnywhere)
	float lineTraceRange = 1000000.0f;
};
