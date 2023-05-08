// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FactoryPattern.generated.h"

#if 0
//抽象产品类
UCLASS(Abstract)
class DESIGNPATTERNS_API UProduct : public UObject
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() {};
};

//具体产品类A
UCLASS()
class DESIGNPATTERNS_API UProductProjectA : public UProduct
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;
};

//具体产品类B
UCLASS()
class DESIGNPATTERNS_API UProductProjectB : public UProduct
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;
};

//抽象工厂类
UCLASS(Abstract)
class DESIGNPATTERNS_API UFactoryObj : public UObject
{
	GENERATED_BODY()
public:
	virtual UProduct* CreateProduct() {return nullptr;}
};

//具体工厂类A
UCLASS()
class DESIGNPATTERNS_API UFactoryA : public UFactoryObj
{
	GENERATED_BODY()
public:
	virtual UProduct* CreateProduct() override;
};

//具体工厂类B
UCLASS()
class DESIGNPATTERNS_API UFactoryB : public UFactoryObj
{
	GENERATED_BODY()
public:
	virtual UProduct* CreateProduct() override;
};
#endif

UCLASS()
class DESIGNPATTERNS_API AFactoryPattern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFactoryPattern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

