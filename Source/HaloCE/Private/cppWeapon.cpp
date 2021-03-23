// Fill out your copyright notice in the Description page of Project Settings.


#include "cppWeapon.h"

// Sets default values for this component's properties
UcppWeapon::UcppWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	weaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	ammoType = CreateDefaultSubobject<AAmmunition>(TEXT("BulletActor"));

	/*weaponMesh->AttachTo(usc);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> aux(TEXT("/Game/Meshes/Weapons/UNSC/MagnumMesh.MagnumMesh"));
	if (aux.Succeeded())
	{
		weaponMesh->SetStaticMesh(aux.Object);
	}*/
	// ...
}

void UcppWeapon::AttachSceneComponent(USceneComponent* usc)
{
	weaponMesh->AttachTo(usc);
}

void UcppWeapon::Shoot(FVector _direction)
{
	GetWorld()->SpawnActor<AAmmunition>(weaponMesh->GetComponentLocation() + FVector(10, 0, 10) + _direction, FRotator::ZeroRotator, FActorSpawnParameters());
}

void UcppWeapon::Reload()
{
}

void UcppWeapon::Aim()
{
}

// Called when the game starts
void UcppWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UcppWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//Shoot(tempVec);
	//tempVec += FVector(1, 0, 0);
	// ...
}

