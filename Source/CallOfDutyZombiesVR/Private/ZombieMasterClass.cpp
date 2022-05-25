// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#include "ZombieMasterClass.h"

// Sets default values
AZombieMasterClass::AZombieMasterClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ZombieMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Zombie Mesh"));
	RootComponent = ZombieMesh;

	bReplicates = true;

	NetUpdateFrequency = 66.0f;
	MinNetUpdateFrequency = 33.0f;
}

// Called when the game starts or when spawned
void AZombieMasterClass::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AZombieMasterClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AZombieMasterClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}