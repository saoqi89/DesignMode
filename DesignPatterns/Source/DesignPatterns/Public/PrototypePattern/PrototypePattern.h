// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PrototypePattern.generated.h"

UCLASS(Abstract)
class UProductPhones : public UObject
{
	GENERATED_BODY()
public:
	virtual UProductPhones* Clone() PURE_VIRTUAL(, return nullptr;);
	virtual void ShowInfos();
protected:
	int32 Capacity = 128;
	FString Color = TEXT("Black");
};

UCLASS()
class UVivo : public UProductPhones
{
	GENERATED_BODY()
public:
	virtual UProductPhones* Clone() override;
};

UCLASS()
class UOppo : public UProductPhones
{
	GENERATED_BODY()
public:
	UOppo();
	virtual UProductPhones* Clone() override;
	virtual void ShowInfos() override;
protected:
	int32 RAM = 16;
};

UCLASS()
class UPhoneSpawner : public UObject
{
	GENERATED_BODY()
public:
	template<class T>
	T* Spawner()
	{
		return NewObject<T>();
	}
	UProductPhones* Spawner(UProductPhones* PhonesClass);
};

UCLASS()
class DESIGNPATTERNS_API APrototypePattern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APrototypePattern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
