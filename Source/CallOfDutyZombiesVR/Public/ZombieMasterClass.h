// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "ZombieMasterClass.generated.h"

class USkeletalMeshComponent;

UCLASS()
class CALLOFDUTYZOMBIESVR_API AZombieMasterClass : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieMasterClass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* ZombieMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};