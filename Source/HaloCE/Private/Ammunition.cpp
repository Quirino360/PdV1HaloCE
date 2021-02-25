// Fill out your copyright notice in the Description page of Project Settings.


#include "Ammunition.h"

// Sets default values
AAmmunition::AAmmunition()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	bulletMesh->AttachTo(RootComponent);
	bulletMesh->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> aux(TEXT("/Game/Meshes/Temporal_Bullet.Temporal_Bullet"));
	if (aux.Succeeded())
	{
		bulletMesh->SetStaticMesh(aux.Object);
	}

	speed = 10; //10units / seconds
}

// Called when the game starts or when spawned
void AAmmunition::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAmmunition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

