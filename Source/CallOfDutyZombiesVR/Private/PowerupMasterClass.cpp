// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#include "PowerupMasterClass.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APowerupMasterClass::APowerupMasterClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PowerupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = PowerupMesh;
	PowerupParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	PowerupParticle->SetupAttachment(PowerupMesh, NAME_None);

	bReplicates = true;

	NetUpdateFrequency = 66.0f;
	MinNetUpdateFrequency = 33.0f;
}

void APowerupMasterClass::GetPickedup()
{
	GetPickedup_BP();

	if (UniversalPowerupPickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), UniversalPowerupPickupSound, GetActorLocation());
	}

	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSound, GetActorLocation());
	}

	if (PickupSound1)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSound1, GetActorLocation());
	}

	Destroy();
}

// Called when the game starts or when spawned
void APowerupMasterClass::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APowerupMasterClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}