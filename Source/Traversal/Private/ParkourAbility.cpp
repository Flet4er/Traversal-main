// Fill out your copyright notice in the Description page of Project Settings.

#include "ParkourAbility.h"

UParkourAbility::UParkourAbility()
{

}

void UParkourAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UE_LOG(LogTemp, Log, TEXT("Parkour!!"));

	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}