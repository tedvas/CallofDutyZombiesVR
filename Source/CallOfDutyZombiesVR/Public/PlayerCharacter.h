// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#pragma once

#include "CoreMinimal.h"
#include "VRCharacter.h"
#include "Net/UnrealNetwork.h"
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

	UFUNCTION(BlueprintCallable)
	void GivePerk(int Perk);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void GivePerk_BP(int Perk);

	UFUNCTION(BlueprintCallable)
	void EjectFromOriginsRobot();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void EjectFromOriginsRobot_BP();

	UFUNCTION(BlueprintCallable)
	void TeleportAfterRobotEject();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TeleportAfterRobotEject_BP();

	UFUNCTION(BlueprintCallable)
	void LandAfterRobotEject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool VR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ComfortSetting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	int PlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPaused;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	int Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	int MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	bool StartedMatch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	bool CanMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	bool CanJump1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RobotEjectMoveToLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RobotEjectTeleportLocaion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RobotEjectLandLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RobotEjectTeleportTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RobotEjectLandTime;

	FTimerHandle Delay;

	FTimerHandle RobotEjectDelay;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};