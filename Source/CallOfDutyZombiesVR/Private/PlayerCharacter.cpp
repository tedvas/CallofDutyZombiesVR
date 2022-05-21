// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#include "PlayerCharacter.h"
#include "TimerManager.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// non VR is only for testing
	VR = true;

	PlayerIndex = 0;
	StartedMatch = false;
	CanMove = true;
	CanJump1 = true;
	RobotEjectTeleportTime = 2.0f;
	RobotEjectLandTime = 5.0f;

	// 0 = none // 1 = moderate // 2 = comfortable
	ComfortSetting = 0;
	
	bReplicates = true;

	NetUpdateFrequency = 66.0f;
	MinNetUpdateFrequency = 33.0f;
}

void APlayerCharacter::EjectFromOriginsRobot()
{
	EjectFromOriginsRobot_BP();
	
	CanMove = false;
	CanJump1 = false;

	GetWorldTimerManager().SetTimer(RobotEjectDelay, this, &APlayerCharacter::TeleportAfterRobotEject, RobotEjectTeleportTime, false, RobotEjectTeleportTime);
}

void APlayerCharacter::TeleportAfterRobotEject()
{
	TeleportAfterRobotEject_BP();

	NotifyOfTeleport(true);
	TeleportTo(RobotEjectTeleportLocaion, FRotator::ZeroRotator);

	GetWorldTimerManager().SetTimer(RobotEjectDelay, this, &APlayerCharacter::LandAfterRobotEject, RobotEjectLandTime, false, RobotEjectLandTime);
}

void APlayerCharacter::LandAfterRobotEject()
{
	NotifyOfTeleport(true);
	TeleportTo(RobotEjectLandLocation, FRotator::ZeroRotator);

	CanMove = true;
	CanJump1 = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	BeginPlay_BP();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlayerCharacter, PlayerIndex);
	DOREPLIFETIME(APlayerCharacter, StartedMatch);
	DOREPLIFETIME(APlayerCharacter, CanMove);
	DOREPLIFETIME(APlayerCharacter, CanJump1);
}