#include "MasterChief.h"

//#include "Weapon.h"
//#include "Grenade.h"



// Sets default values
AMasterChief::AMasterChief()
{
	PrimaryActorTick.bCanEverTick = true;// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	timeToMove = 0;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	canJump = false;
	velocity = 0.75f;

}

// Called when the game starts or when spawned
void AMasterChief::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMasterChief::Tick(float DeltaTime)
{
	timeToMove += DeltaTime;
	Super::Tick(DeltaTime);
	if (canJump)	{
		Jump();
	}
}

// Called to bind functionality to input
void AMasterChief::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (timeToMove >= 3)
	{
		InputComponent->BindAxis("HorizontalMove", this, &AMasterChief::HorizontalMove);
		InputComponent->BindAxis("VerticalMove", this, &AMasterChief::VerticalMove);

		InputComponent->BindAction("Jump", IE_Pressed, this, &AMasterChief::CheckJump);
		InputComponent->BindAction("Jump", IE_Released, this, &AMasterChief::CheckJump);
	}
}

void AMasterChief::HorizontalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorRightVector(), value * velocity);
	}
}

void AMasterChief::VerticalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value * velocity);
	}
}

void AMasterChief::CheckJump()
{
	if (canJump) {
		canJump = false;
	}
	else {
		canJump = true;
	}
}
