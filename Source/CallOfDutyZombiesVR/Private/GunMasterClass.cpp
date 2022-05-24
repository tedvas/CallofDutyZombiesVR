// Everything in this project was initially developed by Treyarch and Activision, I'm simply porting it to VR

#include "GunMasterClass.h"

// Sets default values
AGunMasterClass::AGunMasterClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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