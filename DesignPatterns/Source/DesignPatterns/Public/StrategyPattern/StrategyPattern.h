// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrategyPattern.generated.h"

//抽象策略类 --支付方式
UCLASS(Abstract)
class DESIGNPATTERNS_API UPaymentMethod : public UObject
{
	GENERATED_BODY()
public:
	virtual void PayInfo() PURE_VIRTUAL(,);
};

//具体策略类 --微信支付
UCLASS()
class DESIGNPATTERNS_API UWeChat : public UPaymentMethod
{
	GENERATED_BODY()
public:
	virtual void PayInfo() override;
};

//具体策略类 --支付宝支付
UCLASS()
class DESIGNPATTERNS_API UAlipay : public UPaymentMethod
{
	GENERATED_BODY()
public:
	virtual void PayInfo() override;
};

//具体策略类 --信用卡支付
UCLASS()
class DESIGNPATTERNS_API UCreditCards : public UPaymentMethod
{
	GENERATED_BODY()
public:
	virtual void PayInfo() override;
};

//抽象环境类 --物品
UCLASS(Abstract)
class DESIGNPATTERNS_API UArticles : public UObject
{
	GENERATED_BODY()
public:
	virtual void Buy();
	virtual void Sell(UPaymentMethod* Method);
protected:
	UPROPERTY()
	UPaymentMethod* PaymentMethod = nullptr;
};

//具体环境类 --电脑
UCLASS()
class DESIGNPATTERNS_API UComputer : public UArticles
{
	GENERATED_BODY()
public:
	UComputer();
};

//具体环境类 --手机
UCLASS()
class DESIGNPATTERNS_API UPhone : public UArticles
{
	GENERATED_BODY()
public:
	UPhone();
};

UCLASS()
class DESIGNPATTERNS_API AStrategyPattern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStrategyPattern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
