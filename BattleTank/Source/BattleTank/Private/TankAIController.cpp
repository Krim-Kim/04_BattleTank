// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	ATank* playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* controlledTank = Cast<ATank>(GetPawn());

	if(!playerTank || !controlledTank) return;

	// TODO Move towards the Player


	// Aim towards the Player
	controlledTank->AimAt(playerTank->GetActorLocation());
	controlledTank->Fire(); // TODO limit fire rate
}
