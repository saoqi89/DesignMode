// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractFactoryPattern/AbstractFactoryPattern.h"

/*namespace AbstractFactoryPattern
{*/
	void UProductPhone::ShowInfo()
	{
		Super::ShowInfo();
		UE_LOG(LogTemp, Error, TEXT(__FUNCTION__ " This is ProductPhone"));
	}

	void UProductPad::ShowInfo()
	{
		Super::ShowInfo();
		UE_LOG(LogTemp, Error, TEXT(__FUNCTION__ " This is ProductPad"));
	}

	void UiPhone::ShowInfo()
	{
		//Super::ShowInfo();
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " This is iPhone"));
	}

	void UXiaoMi::ShowInfo()
	{
		//Super::ShowInfo();
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " This is XiaoMiPhone"));
	}

	void UiPad::ShowInfo()
	{
		//Super::ShowInfo();
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " This is iPad"));
	}

	void UXiaoMiPad::ShowInfo()
	{
		//Super::ShowInfo();
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " This is XiaoMiPad"));
	}

	UProductPad* UFactorApple::CreateProductPad()
	{
		return NewObject<UiPad>();
	}

	UProductPhone* UFactorApple::CreateProductPhone()
	{
		return NewObject<UiPhone>();
	}

	UProductPad* UFactorXiaoMi::CreateProductPad()
	{
		return NewObject<UXiaoMiPad>();
	}

	UProductPhone* UFactorXiaoMi::CreateProductPhone()
	{
		return NewObject<UXiaoMi>();
	}

	// Sets default values
	AAbstractFactoryPattern::AAbstractFactoryPattern()
	{
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;

	}

	// Called when the game starts or when spawned
	void AAbstractFactoryPattern::BeginPlay()
	{
		Super::BeginPlay();

		UFactorApple* FactorApple = NewObject<UFactorApple>();
		FactorApple->CreateProductPad()->ShowInfo();
		FactorApple->CreateProductPhone()->ShowInfo();

		UFactorXiaoMi* FactorXiaoMi = NewObject<UFactorXiaoMi>();
		FactorXiaoMi->CreateProductPad()->ShowInfo();
		FactorXiaoMi->CreateProductPhone()->ShowInfo();
	
	}

	// Called every frame
	void AAbstractFactoryPattern::Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);

	}
	
//}

