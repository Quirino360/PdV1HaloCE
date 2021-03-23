// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MasterChief_cpp.h"

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerWidget_cpp.generated.h"
/**
 * 
 */
UCLASS()
class HALOCE_API UPlayerWidget_cpp : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float maxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float maxShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float shield;

	virtual void NativeTick(const FGeometry& geometry, float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* Canvas;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* HealthBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* ShieldBar;

	UFUNCTION(BlueprintCallable)
		void SetCharcaterWeapons(AMasterChief_cpp* _player); //set the grenades and werapons the player has for the UI

	//UFUNCTION(BlueprintCallable)
		

protected:
	
	
};
