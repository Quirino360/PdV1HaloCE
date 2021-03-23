// Fill out your copyright notice in the Description page of Project Settings.
#include "PlayerWidget_cpp.h"

#include "Components/ProgressBar.h"
#include "Components/CanvasPanel.h"

void UPlayerWidget_cpp::NativeTick(const FGeometry& geometry, float DeltaTime)
{
	Super::NativeTick(geometry, DeltaTime);

}

void UPlayerWidget_cpp::SetCharcaterWeapons(AMasterChief_cpp* _player)
{
	maxHealth = _player->getMaxHealth();
	health = _player->getHealth();

	maxShield = _player->getMaxShield();
	shield = _player->getMaxShield();
}
