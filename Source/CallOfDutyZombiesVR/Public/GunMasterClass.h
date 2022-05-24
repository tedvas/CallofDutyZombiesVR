// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunMasterClass.generated.h"

UCLASS()
class CALLOFDUTYZOMBIESVR_API AGunMasterClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunMasterClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};