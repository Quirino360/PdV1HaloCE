// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Ammunition.h"
#include "Components/StaticMeshComponent.h"

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "cppWeapon.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HALOCE_API UcppWeapon : public USceneComponent
{
	GENERATED_BODY()

public:	
	UcppWeapon();

	void AttachSceneComponent(USceneComponent* usc);
	void Shoot(FVector _direction);
	void Reload();
	void Aim();

	UPROPERTY(EditAnywhere, Category = "Weapon") float aimZoom;
	UPROPERTY(EditAnywhere, Category = "Weapon") float maxAmmo;
	UPROPERTY(EditAnywhere, Category = "Weapon") float ammoCount;

	AAmmunition* ammoType;
	UPROPERTY(EditAnywhere, Category = "Weapon") UStaticMeshComponent* weaponMesh;

private:
	FVector tempVec = FVector(0, 0, 0);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	private:
};
