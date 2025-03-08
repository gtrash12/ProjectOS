#include "AbilityTask_ProjectileBase.h"

void UAbilityTask_ProjectileBase::Activate()
{
	Super::Activate();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Template = ProjectileTemplate;
	AActor*ProjectileActor = GetWorld()->SpawnActor<AActor>(SpawnParams);

	ProjectileActor->OnActorHit.AddDynamic(this, &UAbilityTask_ProjectileBase::OnProjectileHit);
}

void UAbilityTask_ProjectileBase::OnDestroy(bool AbilityEnded)
{
	Super::OnDestroy(AbilityEnded);
}

void UAbilityTask_ProjectileBase::OnProjectileHit(AActor* HitActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& HitResult)
{
	OnProjectileHitDelegate.ExecuteIfBound(HitResult);
}