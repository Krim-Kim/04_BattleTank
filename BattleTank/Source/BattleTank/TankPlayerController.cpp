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

	// Get world location if you linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank to aim at this point
}
