// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();

	if(controlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Possessed! = %s"), *(controlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("NO Player Tank Possessed!"));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


