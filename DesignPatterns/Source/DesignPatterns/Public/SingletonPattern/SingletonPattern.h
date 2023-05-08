// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <mutex>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SingletonPattern.generated.h"

UCLASS()
class USingleton : public UObject
{
	GENERATED_BODY()
public:
	static USingleton* GetInstance();
	void ShowInfo();
private:
	USingleton() {}
	static USingleton* SingletonInstance;
	static std::mutex Mutex;
};

UCLASS()
class DESIGNPATTERNS_API ASingletonPattern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASingletonPattern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
