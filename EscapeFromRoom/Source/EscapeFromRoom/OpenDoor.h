// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EscapeFromRoom.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEFROMROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenDoorAngle = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* presurePlate;

	UPROPERTY(VisibleAnywhere)
	AActor* ActorThatOpenDoors;
};
