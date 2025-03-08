#pragma once
#include "GameplayAbility_SkillBase.h"
#include "GameplayAbility_FireBall.generated.h"

UCLASS()
class UGameplayAbility_FireBall : public UGameplayAbility_SkillBase
{
	GENERATED_BODY()

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};

