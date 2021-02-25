// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterChief_cpp.h"

// Sets default values
AMasterChief_cpp::AMasterChief_cpp()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false; //Roll & Pitch are allready false, when Yaw is to true, we need this to be false to use the yaw

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->AttachTo(RootComponent);
	//camera->SetRelativeLocation(FVector(0, 0, 0));

	primaryWeapon = CreateDefaultSubobject<AWeapon>(TEXT("WeaponActor"));
	//primaryWeapon->Attach

	jumping = false;
	shooting = false;
}

// Called when the game starts or when spawned
void AMasterChief_cpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterChief_cpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (jumping)
	{
		Jump();
	}
	if (shooting)
	{
		primaryWeapon->Shoot(FVector(0, 0, 0));
	}
}

// Called to bind functionality to input
void AMasterChief_cpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Horizontal", this, &AMasterChief_cpp::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &AMasterChief_cpp::VerticalMove);

	InputComponent->BindAxis("HorizontalRotation", this, &AMasterChief_cpp::HorizontalRotation);
	InputComponent->BindAxis("VerticalRotation", this, &AMasterChief_cpp::VerticalRotation);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AMasterChief_cpp::CheckJump);  // When is jumpumping, jumping = true 
	InputComponent->BindAction("Jump", IE_Released, this, &AMasterChief_cpp::CheckJump); // When is jumpumping, jumping = false 		

	InputComponent->BindAction("Shoot", IE_Pressed, this, &AMasterChief_cpp::CheckShoot);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AMasterChief_cpp::CheckShoot);

}

void AMasterChief_cpp::HorizontalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void AMasterChief_cpp::VerticalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void AMasterChief_cpp::HorizontalRotation(float value)
{
	if (value)
	{
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}

void AMasterChief_cpp::VerticalRotation(float value)
{
	if (value)
	{
		value *= -1;
		float temp = camera->GetRelativeRotation().Pitch + value;

		if (temp < 45 && temp > -45)
		{
			camera->AddLocalRotation(FRotator((value), 0, 0));
		}
	}
}

void AMasterChief_cpp::CheckJump()
{
	if (jumping)
	{
		jumping = false;
	}
	else
	{
		jumping = true;
	}
}

void AMasterChief_cpp::CheckShoot()
{
	if (shooting)
	{
		shooting = false;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString(TEXT("ShootingFalse")));
	}
	else
	{
		shooting = true;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString(TEXT("ShootingFalse")));
	}
}
