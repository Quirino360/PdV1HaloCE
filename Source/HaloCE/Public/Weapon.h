// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Ammunition.h"
#include "Components/StaticMeshComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class HALOCE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	void Shoot(FVector _direction);
	void Reload();
	void Aim();

	float aimZoom;
	float maxAmmo;
	float ammoCount;

	AAmmunition* ammoType;
	UPROPERTY(EditAnywhere, Category = "Weapon") UStaticMeshComponent* weaponMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:

};
