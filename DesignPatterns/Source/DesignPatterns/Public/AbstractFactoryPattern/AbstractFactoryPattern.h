// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbstractFactoryPattern.generated.h"

/*namespace AbstractFactoryPattern
{*/
		//抽象产品类族
	UCLASS(Abstract)
	class DESIGNPATTERNS_API UProduct : public UObject
	{
		GENERATED_BODY()
	public:
		virtual void ShowInfo() {};
	};

	//抽象产品类A
	UCLASS()
	class DESIGNPATTERNS_API UProductPhone : public UProduct
	{
		GENERATED_BODY()
	public:
		virtual void ShowInfo() override;
	};

	//抽象产品类B
	UCLASS()
	class DESIGNPATTERNS_API UProductPad : public UProduct
	{
		GENERATED_BODY()
	public:
		virtual void ShowInfo() override;
	};

	//具体产品类iPhone
	UCLASS()
	class DESIGNPATTERNS_API UiPhone : public UProductPhone
	{
		GENERATED_BODY()
	public:
		virtual void ShowInfo() override;
		
	};

	//具体产品类XiaoMiPhone
	UCLASS()
	class DESIGNPATTERNS_API UXiaoMi : public UProductPhone
	{
		GENERATED_BODY()
	public:
		virtual void ShowInfo() override;
		
	};

	//具体产品类iPad
	UCLASS()
	class DESIGNPATTERNS_API UiPad : public UProductPad
	{
		GENERATED_BODY()
	public:
		virtual void ShowInfo() override;
		
	};

	//具体产品类XiaoMiPad
	UCLASS()
	class DESIGNPATTERNS_API UXiaoMiPad : public UProductPad
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
		virtual UProductPhone* CreateProductPhone() {return nullptr;}
		virtual UProductPad* CreateProductPad() {return nullptr;}
	};

	//具体工厂类A
	UCLASS()
	class DESIGNPATTERNS_API UFactorApple : public UFactoryObj
	{
		GENERATED_BODY()
	public:
		virtual UProductPad* CreateProductPad() override;
		virtual UProductPhone* CreateProductPhone() override;
	};

	//具体工厂类B
	UCLASS()
	class DESIGNPATTERNS_API UFactorXiaoMi : public UFactoryObj
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

//}

