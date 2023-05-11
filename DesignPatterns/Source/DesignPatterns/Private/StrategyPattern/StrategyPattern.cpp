// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyPattern/StrategyPattern.h"

void UWeChat::PayInfo()
{
	UE_LOG(LogTemp, Warning, TEXT("WeChat payment"));
}

void UAlipay::PayInfo()
{
	UE_LOG(LogTemp, Warning, TEXT("Alipay payment"));
}

void UCreditCards::PayInfo()
{
	UE_LOG(LogTemp, Warning, TEXT("Sorry, the balance is insufficient."));
}

void UArticles::Buy()
{
	if (PaymentMethod)
	{
		PaymentMethod->PayInfo();
	}
}

void UArticles::Sell(UPaymentMethod* Method)
{
	PaymentMethod = Method;
	UE_LOG(LogTemp, Warning, TEXT("Items to sell"));
}

UComputer::UComputer()
{
	PaymentMethod = NewObject<UWeChat>();
	UE_LOG(LogTemp, Warning, TEXT("This is Computer"));
}

UPhone::UPhone()
{
	PaymentMethod = NewObject<UAlipay>();
	UE_LOG(LogTemp, Warning, TEXT("This is Phone"));
}

// Sets default values
AStrategyPattern::AStrategyPattern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategyPattern::BeginPlay()
{
	Super::BeginPlay();

	UComputer* Computer = NewObject<UComputer>();
	Computer->Buy();

	Computer->Sell(NewObject<UCreditCards>());
	Computer->Buy();

	UPhone* Phone = NewObject<UPhone>();
	Phone->Buy();

	Phone->Sell(NewObject<UCreditCards>());
	Phone->Buy();
	
}

// Called every frame
void AStrategyPattern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

