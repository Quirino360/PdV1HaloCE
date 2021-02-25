// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NPC_cpp.generated.h"

UCLASS()
class HALOCE_API ANPC_cpp : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANPC_cpp();
	//~ANPC_cpp();


private:


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

};
