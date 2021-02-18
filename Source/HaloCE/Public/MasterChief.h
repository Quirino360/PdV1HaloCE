#pragma once

#include "Components/InputComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MasterChief.generated.h"

UCLASS()
class HALOCE_API AMasterChief : public APawn
{
	GENERATED_BODY()

public:
	AMasterChief(); // Sets default values for this pawn's properties

	//class AWeapon* primaryWeapon;
	//class AWeapon* secondaryWeapon;

	//class AGrenade* fragmentGrenade;
	//class AGrenade* plasmaGrenade;


	float maxLife;
	float actualLife;
	bool canRTechargeHealth;

	float maxShield;
	float actualShield;
	bool canRechargeShield;



private:
	UPROPERTY(EditAnywhere) float velocity;
	UPROPERTY() bool canJump;
	UPROPERTY() float timeToMove;


public:
	//void Shoot();
	//void Reload();
	//void Aim();

	//void Jump();
	//void Move();
	//void Hit();
	//void Crouch();

	//void ChangeWeapon();
	//void PickUpWeapon();

	//void ThrowGrenade();
	//void ChangeGrenade();

	//void RechargeShield();
	//void RechrageHeralth();


private:
	void HorizontalMove(float value);
	void VerticalMove(float value);
	void CheckJump();




protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
