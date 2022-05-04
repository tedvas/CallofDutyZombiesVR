// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#pragma once

#include "CoreMinimal.h"
#include "VRCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class CALLOFDUTYZOMBIESVR_API APlayerCharacter : public AVRCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void BeginPlay_BP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool VR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanMove;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};