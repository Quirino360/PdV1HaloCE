// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	weaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	weaponMesh->AttachTo(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> aux(TEXT("/Game/Meshes/Weapons/UNSC/MagnumMesh.MagnumMesh"));
	if (aux.Succeeded())
	{
		weaponMesh->SetStaticMesh(aux.Object);
	}

	ammoType = CreateDefaultSubobject<AAmmunition>(TEXT("BulletActor"));

}

void AWeapon::Shoot(FVector _direction)
{
	FVector location(0, 0, 0);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;

	GetWorld()->SpawnActor<AAmmunition>(weaponMesh->GetComponentLocation() + FVector(10,10,10), rotation, spawnInfo);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	Shoot(FVector(0, 0, 0));
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

