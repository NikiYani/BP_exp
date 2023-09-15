// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class BP_EXP_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	FString PlayerName = "";
	
	UPROPERTY(EditAnywhere)
	int dopeNum = 2120;

	UPROPERTY(EditAnywhere)
	int EnemyNum = 120;
	
	UPROPERTY(EditDefaultsOnly)
	float CurrentHealth = 57.54678;
	
	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	UPROPERTY(EditAnywhere)
	float Amplitude = 70.0f;

	UPROPERTY(EditAnywhere)
	float Frequency = 4.0f;
		
	UPROPERTY(EditAnywhere) 
	FVector InitialLocation = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere)
	EMovementState enumState;

	UFUNCTION(BlueprintCallable)
	void ShowInformation();

	UFUNCTION(BlueprintCallable)
	float SinMovement(float z);
};
