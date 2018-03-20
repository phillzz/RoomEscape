// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EscapeFromRoom.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEFROMROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
	UGrabber();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void TraceDebugLine();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:
	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	float reach = 100.f;
	
};
