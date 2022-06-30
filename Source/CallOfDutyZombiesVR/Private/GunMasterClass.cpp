// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#include "GunMasterClass.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine.h"
#include "CallOfDutyZombiesVR/CallOfDutyZombiesVR.h"
// for some reason it won't work unless you put the full file path for this file

// Sets default values
AGunMasterClass::AGunMasterClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	RootComponent = GunMesh;

	CanShoot = true;
	HasRoundInChamber = true;
	Range = 10000000.0f;
	Damage = 15.0f;
	HeadDamage = 25.0f;
	LegDamage = 10.0f;
	TorsoDamage = 15.0f;

	// The Amount Of Time In Between Shots
	FireRate = 0.05f;
}

void AGunMasterClass::Fire()
{
	if (CanShoot == true && HasRoundInChamber == true)
	{
		GetFireLocationAndRotation_BP();

		Fire_BP();

		FVector ShotDirection = BarrelRotation.Vector();
		FVector TraceEnd = BarrelLocation + (ShotDirection * Range);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = true;
		QueryParams.bReturnPhysicalMaterial = true;

		FHitResult Hit;
		if (GetWorld()->LineTraceSingleByChannel(Hit, BarrelLocation, TraceEnd, ECC_Visibility, QueryParams))
		{
			AActor* HitActor = Hit.GetActor();

			EPhysicalSurface SurfaceType = UGameplayStatics::GetSurfaceType(Hit);

			UParticleSystem* HitEffect = nullptr;

			switch (SurfaceType)
			{
			case SURFACE_CHEST:
				HitEffect = Blood;
				break;
			case SURFACE_HEAD:
				HitEffect = Blood;
				break;
			case SURFACE_LEG:
				HitEffect = Blood;
				break;
			case SURFACE_TORSO:
				HitEffect = Blood;
				break;
			case SURFACE_WATER:
				HitEffect = Water;
				break;
			default:
				HitEffect = DefaultImpactEffect;
				break;
			}

			if (SurfaceType == SURFACE_HEAD)
			{
				UGameplayStatics::ApplyPointDamage(HitActor, HeadDamage, ShotDirection, Hit, OwningPlayer->GetInstigatorController(), OwningPlayer, DamageType);
			}
			else if (SurfaceType == SURFACE_LEG)
			{
				UGameplayStatics::ApplyPointDamage(HitActor, LegDamage, ShotDirection, Hit, OwningPlayer->GetInstigatorController(), OwningPlayer, DamageType);
			}
			else if (SurfaceType == SURFACE_TORSO)
			{
				UGameplayStatics::ApplyPointDamage(HitActor, TorsoDamage, ShotDirection, Hit, OwningPlayer->GetInstigatorController(), OwningPlayer, DamageType);
			}
			else
			{
				UGameplayStatics::ApplyPointDamage(HitActor, Damage, ShotDirection, Hit, OwningPlayer->GetInstigatorController(), OwningPlayer, DamageType);
			}
		}

		CanShoot = false;

		DelayToSetCanShootTrue_BP();
	}
}

void AGunMasterClass::SetCanShootTrue()
{
	CanShoot = true;
}

// Called when the game starts or when spawned
void AGunMasterClass::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGunMasterClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}