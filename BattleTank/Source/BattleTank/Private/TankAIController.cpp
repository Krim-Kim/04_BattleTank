// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto playerTank = GetPlayerTank();

	if(playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player: %s"), *(playerTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("NO Player Tank Found!"));
	}
}

void ATankAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if(!GetPlayerTank()) return;

	// TODO Move towards the Player

	// Aim towards the Player
	FVector aimLocation = GetPlayerTank()->GetActorLocation();
	GetControlledTank()->AimAt(aimLocation);

	// Fire if ready

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if(!playerPawn) return nullptr;

	return Cast<ATank>(playerPawn);
}


