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

	float Pitch = Owner->GetActorRotation().Pitch;
	float Yaw = Owner->GetActorRotation().Yaw;
	float Roll = Owner->GetActorRotation().Roll;
	auto NewRotator = FRotator(Pitch, Yaw - 60.f, Roll);
	Owner->SetActorRotation(NewRotator);


//	UE_LOG(LogTemp, Warning, TEXT(" %s rotation is %f"), *OwnerName, *NewRotator);

		
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

