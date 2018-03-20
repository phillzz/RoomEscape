// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber is on-line!"))
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get current pawn view point
	TraceDebugLine();

	

	// Trace line forward to detect if the chair close enough to take it
		// If yes attach chair to Owner

	//or
	
	// Add collision box on pawn.
	// if chair is overlapping owner - attach to owner
}

void UGrabber::TraceDebugLine()
{
	/// Draw line for visualization
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);
	FVector LineTraceEnd = ViewPointLocation + ViewPointRotation.Vector() * reach;
	DrawDebugLine(
		GetWorld(),
		ViewPointLocation,
		LineTraceEnd,
		FColor(255,0,0),
		false,
		0.f,
		0.f,
		2.f
	);
	/// Setup query params
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	/// Trace line
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		ViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);
	
	AActor* HittedActor = Hit.GetActor();
		if (HittedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("This is %s"), *(HittedActor->GetName()));
	}
	
	
}

