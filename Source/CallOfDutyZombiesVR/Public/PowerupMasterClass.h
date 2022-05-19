// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PowerupMasterClass.generated.h"

class UStaticMeshComponent;
class USoundBase;
class UParticleSystemComponent;

UCLASS()
class CALLOFDUTYZOMBIESVR_API APowerupMasterClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerupMasterClass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* PowerupMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* PowerupParticle;

	UFUNCTION(BlueprintCallable)
	void GetPickedup();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GetPickedup_BP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* UniversalPowerupPickupSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* PickupSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* PickupSound1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};