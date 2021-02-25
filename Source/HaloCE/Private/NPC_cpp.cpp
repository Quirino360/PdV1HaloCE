// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_cpp.h"

// Sets default values
ANPC_cpp::ANPC_cpp()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPC_cpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC_cpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC_cpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

