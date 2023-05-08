// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObserverPattern.generated.h"

class UTarget;

//抽象观察者类
UCLASS(Abstract)
class UObserver : public UObject
{
	GENERATED_BODY()
public:
	virtual void Update() PURE_VIRTUAL(,);
};

//具体观察者类
UCLASS()
class UWorker : public UObserver
{
	GENERATED_BODY()
public:
	void SetTarget(UTarget* Target);
	virtual void Update() override;
private:
	UTarget* mTarget;
};

//抽象目标类
UCLASS(Abstract)
class USubject : public UObject
{
	GENERATED_BODY()
public:
	virtual void BindNotify(UObserver* Observer);
	virtual void UnBindNotify(UObserver* Observer);
	virtual void Notify();
protected:
	TArray<UObserver*> ObserversList;
};

//具体目标类
UCLASS()
class UTarget : public USubject
{
	GENERATED_BODY()
public:
	void UpdateTargetLevel(int32 Level);
	int32 GetTargetLevel();
private:
	int32 mLevel;
};

UCLASS()
class DESIGNPATTERNS_API AObserverPattern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObserverPattern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
