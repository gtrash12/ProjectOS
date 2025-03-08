#pragma once
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_ProjectileBase.generated.h"

UCLASS()
class UAbilityTask_ProjectileBase : public UAbilityTask
{
	GENERATED_BODY()

public:
	DECLARE_DELEGATE_OneParam(FOnProjectileHit, const FHitResult& HitResult)
	FOnProjectileHit OnProjectileHitDelegate;

protected:
	virtual void Activate() override;
	virtual void OnDestroy(bool AbilityEnded) override;

	void OnProjectileHit(AActor* HitActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& HitResult);

protected:
	TObjectPtr<AActor> ProjectileTemplate;
};

