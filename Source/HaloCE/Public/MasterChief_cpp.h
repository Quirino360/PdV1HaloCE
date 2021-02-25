// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/Engine.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Weapon.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MasterChief_cpp.generated.h"

UCLASS()
class HALOCE_API AMasterChief_cpp : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMasterChief_cpp();
	//~AMasterChief_cpp();

private:
	
	UPROPERTY(EditAnywhere, Category = "Camera") UCameraComponent* camera;
	UPROPERTY(EditAnywhere, Category = "Weapon") AWeapon* primaryWeapon;
	UPROPERTY() bool jumping;
	UPROPERTY() bool shooting;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void HorizontalMove(float value);
	void VerticalMove(float value);

	void HorizontalRotation(float value);
	void VerticalRotation(float value);

	void CheckJump(); //It is jumping?

	void CheckShoot();
};
