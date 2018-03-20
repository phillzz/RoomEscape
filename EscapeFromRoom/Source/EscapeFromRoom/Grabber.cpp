// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	CheckForPhysicsHandle();
	SetupInputComponent();

}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//TODO: Refactor this piece
	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
	}

}

// Detect physic actors near enough to pawn 
const FHitResult UGrabber::GetFirstphysicsBodiInReach()
{
	// Setup End point for line trace


	// Setup query params for trace line
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	// Trace line
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);
	// Get name of reached Actor
	AActor* HittedActor = Hit.GetActor();
		if (HittedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("This is %s"), *(HittedActor->GetName()));
	}
		return Hit;
}

// Grab Input
void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab Pressed"))
	auto HitResult = GetFirstphysicsBodiInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	if (ActorHit != nullptr)
	{
		PhysicsHandle->GrabComponent(
		ComponentToGrab,
		NAME_None,
		ComponentToGrab->GetOwner()->GetActorLocation(),
		true // allow rotation
		);
	}

}

// Release Input
void UGrabber::Release()
{
	PhysicsHandle->ReleaseComponent();
	UE_LOG(LogTemp, Warning, TEXT("Grab Released"))
}

// Check if pawn have a physics component 
void UGrabber::CheckForPhysicsHandle()
{

	if (!PhysicsHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("%s haven't physics component!"), *(GetOwner()->GetName()))
	}
};

// Bind key press to Grab and release events
void UGrabber::SetupInputComponent()
{
	if (InputComponent)
	{
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Input Component!"))
	}
};

FVector UGrabber::GetReachLineStart()
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);
	return ViewPointLocation;
};

FVector UGrabber::GetReachLineEnd()
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);
	FVector LineTraceEnd = ViewPointLocation + ViewPointRotation.Vector() * reach;
	return LineTraceEnd;
};