// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();

	if(controlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Possessed: %s"), *(controlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("NO Player Tank Possessed!"));
	}
}

void ATankPlayerController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	AimAtCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if(!GetControlledTank()) return;

	// Out parameter
	FVector hitLocation; 

	// Has "side-effect", is going to linetrace
	if(GetSightRayHitLocation(hitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *hitLocation.ToString());

		// If it hits the landscape
			// TODO Tell controlled tank to aim at this point
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& outHitLocation) const
{
	// Find the crosshair position in pixe coordinates
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation = FVector2D(viewportSizeX * crosshairXLocation, viewportSizeY * crosshairYLocation);
	
	// "De-project" the screen position of the crosshair to a world direction
	FVector lookDirection;

	if(GetLookDirection(screenLocation, lookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *lookDirection.ToString());
	}

	// Linetrace along that lookDirection, and see what we hit (up to max range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const
{
	// To be discarded
	FVector cameraWorldLocation;

	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, lookDirection);
}
