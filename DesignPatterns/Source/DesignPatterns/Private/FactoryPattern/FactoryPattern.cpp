// Fill out your copyright notice in the Description page of Project Settings.


#include "FactoryPattern/FactoryPattern.h"
#if 0
void UProductProjectA::ShowInfo()
{
	Super::ShowInfo();
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " This is ProductA"));
}

void UProductProjectB::ShowInfo()
{
	Super::ShowInfo();
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " This is ProductB"));
}

UProduct* UFactoryA::CreateProduct()
{
	return NewObject<UProductProjectA>();
}

UProduct* UFactoryB::CreateProduct()
{
	return NewObject<UProductProjectB>();
}

#endif

// Sets default values
AFactoryPattern::AFactoryPattern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFactoryPattern::BeginPlay()
{
	Super::BeginPlay();

	/*UFactoryA* FactoryA = NewObject<UFactoryA>();
	UProduct* ProductA = FactoryA->CreateProduct();
	ProductA->ShowInfo();

	UFactoryB* FactoryB = NewObject<UFactoryB>();
	UProduct* ProductB = FactoryB->CreateProduct();
	ProductB->ShowInfo();*/
}

// Called every frame
void AFactoryPattern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

