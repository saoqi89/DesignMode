// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbstractFactoryPattern.generated.h"

//抽象产品类族
UCLASS(Abstract)
class UProduct : public UObject
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() {};
};

//抽象产品类A
UCLASS()
class UProductPhone : public UProduct
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;
};

//抽象产品类B
UCLASS()
class UProductPad : public UProduct
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;
};

//具体产品类iPhone
UCLASS()
class UiPhone : public UProductPhone
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;
	
};

//具体产品类HuaWeiPhone
UCLASS()
class UHuaWei : public UProductPhone
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;
	
};

//具体产品类iPad
UCLASS()
class UiPad : public UProductPad
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;
	
};

//具体产品类HuaWeiPad
UCLASS()
class UHuaWeiPad : public UProductPad
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;
	
};

//抽象工厂类
UCLASS(Abstract)
class UFactoryObj : public UObject
{
	GENERATED_BODY()
public:
	virtual UProductPhone* CreateProductPhone() {return nullptr;}
	virtual UProductPad* CreateProductPad() {return nullptr;}
};

//具体工厂类A
UCLASS()
class UFactorApple : public UFactoryObj
{
	GENERATED_BODY()
public:
	virtual UProductPad* CreateProductPad() override;
	virtual UProductPhone* CreateProductPhone() override;
};

//具体工厂类B
UCLASS()
class UFactorHuaWei : public UFactoryObj
{
	GENERATED_BODY()
public:
	virtual UProductPad* CreateProductPad() override;
	virtual UProductPhone* CreateProductPhone() override;
};

UCLASS()
class DESIGNPATTERNS_API AAbstractFactoryPattern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbstractFactoryPattern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
