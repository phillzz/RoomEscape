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

	Owner = GetOwner();
	ActorThatOpenDoors = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	float ownerPitch = Owner->GetActorRotation().Pitch;
	float ownerYaw = Owner->GetActorRotation().Yaw;
	float ownerRoll = Owner->GetActorRotation().Roll;
	// If door is closed then open it
	if (!bDoorState)
	{
		FRotator NewRotator = FRotator(ownerPitch, ownerYaw - OpenAngle, ownerRoll);
		Owner->SetActorRotation(NewRotator);
		bDoorState = true;
	}
}

void UOpenDoor::CloseDoor()
{
	float ownerPitch = Owner->GetActorRotation().Pitch;
	float ownerYaw = Owner->GetActorRotation().Yaw;
	float ownerRoll = Owner->GetActorRotation().Roll;
	// If door is open then close it
	if (bDoorState)
	{
		FRotator NewRotator = FRotator(ownerPitch, ownerYaw + OpenAngle, ownerRoll);
		Owner->SetActorRotation(NewRotator);
		bDoorState = false;
	}
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	// if the ActorThatOpensDoor in the volume

	if (presurePlate->IsOverlappingActor(ActorThatOpenDoors))	
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
		
	}
	if ( GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
		{
			CloseDoor();
		} 
}

