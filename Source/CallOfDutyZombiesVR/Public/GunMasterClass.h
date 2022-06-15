// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunMasterClass.generated.h"

class UStaticMeshComponent;
class UParticleSystem;
class USoundBase;
class UDamageType;

UCLASS()
class CALLOFDUTYZOMBIESVR_API AGunMasterClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunMasterClass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* GunMesh;

	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Fire_BP();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GetFireLocationAndRotation_BP();

	UFUNCTION(BlueprintCallable)
	void SetCanShootTrue();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DelayToSetCanShootTrue_BP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanShoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool HasRoundInChamber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HeadDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LegDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TorsoDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector BarrelLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator BarrelRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* OwningPlayer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UParticleSystem* Blood;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UParticleSystem* Water;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UParticleSystem* DefaultImpactEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USoundBase* FireSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UDamageType> DamageType;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};