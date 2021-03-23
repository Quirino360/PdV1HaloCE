// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/Engine.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/EngineTypes.h"
#include "cppWeapon.h"
#include "Test.h"


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
	UPROPERTY(EditAnywhere, Category = "Weapon") UcppWeapon* primaryWeapon; //, meta = (BindWidget)
	UPROPERTY() bool jumping;
	UPROPERTY() bool shooting;


	UPROPERTY() float maxHealth;
	UPROPERTY() float health;

	UPROPERTY() float maxShield;
	UPROPERTY() float shield;


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

	UFUNCTION(BlueprintCallable) 
		bool getIsShooting() { return shooting; };
public:
	// ------------------- Getters & Setters ----------------------------- //

	float getMaxHealth() { return maxHealth; };
	float getHealth() { return health; };
	void setHealth(float _health) { health = _health; };

	float getMaxShield() { return maxShield; };
	float getShield() { return shield; };
	void setShield(float _shield) { shield = _shield; };
};
