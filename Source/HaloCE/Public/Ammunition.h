// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/StaticMeshComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ammunition.generated.h"

UCLASS()
class HALOCE_API AAmmunition : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmunition();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	float damage;
	float speed;

	UPROPERTY(EditAnywhere, Category = "Bullet") UStaticMeshComponent* bulletMesh;
};

