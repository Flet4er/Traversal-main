// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "ParkourAbility.generated.h"

#define ECC_Parkour ECC_GameTraceChannel1
/**
 * 
 */
UCLASS()
class TRAVERSAL_API UParkourAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UParkourAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* ParkourMontageMantle_1_5m;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* ParkourMontageMantle_1m;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* ParkourMontageVaultFast;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* ParkourMontageVaultNormal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourBalanc")
	float Parkour1_5m = 30.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourBalanc")
	float Parkour1m = 82.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourBalanc")
	float ParkourVault = -10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourBalanc")
	float DistanceToWall = 20.f;

protected:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourConst")
	float MaxWallHeightToClimb = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourConst")
	float MantlingHeightPoint = 60.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourConst")
	float MaxWallDetection = 85.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourConst")
	float WallThicknessCheck = 60.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourConst")
	float MaxHeightDifference = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourConst")
	float ChangeVaultingSpeed = 700.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParkourConst")
	float MantleDifference = 130.f;

	UFUNCTION()
	void OnMontageDone();
	UFUNCTION()
	void OnMontageInterupted();
	UFUNCTION()
	void PlayMontage(UAnimMontage* MontageToPlay);
};
