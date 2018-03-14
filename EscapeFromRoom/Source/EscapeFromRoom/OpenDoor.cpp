// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	FString OwnerName = GetOwner()->GetName();
	AActor* Owner = GetOwner();
//	float OwnerRotPitch = Owner->GetActorRotation().Pitch();
//	float OwnerRotYaw = Owner->GetActorRotation().Yaw();
//	float OwnerRotRoll = Owner->GetActorRotation().Roll();

	FRotator NewRotator = FRotator(0.f, - 60.f, 0.f);
	Owner->SetActorRotation(NewRotator);


//	UE_LOG(LogTemp, Warning, TEXT(" %s rotation is %f"), *OwnerName, *NewRotator);

	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

