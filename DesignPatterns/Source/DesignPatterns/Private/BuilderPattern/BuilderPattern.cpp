// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderPattern/BuilderPattern.h"

void UProducts::Showinfo()
{
	UE_LOG(LogTemp, Warning, TEXT("%s, %s, %s"), *Brand, *Kind, *Color);
}

UProductsBuilder::UProductsBuilder()
{
	Product = NewObject<UProducts>();
}

UProducts* UProductsBuilder::GetProduct()
{
	return Product;
}

void UAppleBuilder::BuilderBrand()
{
	Product->Brand = TEXT("Apple");
}

void UAppleBuilder::BuilderKind()
{
	Product->Kind = TEXT("Phone");
}

void UAppleBuilder::BuilderColor()
{
	Product->Color = TEXT("Purple");
}

void UXiaoMiBuilder::BuilderBrand()
{
	Product->Brand = TEXT("XiaoMi");
}

void UXiaoMiBuilder::BuilderKind()
{
	Product->Kind = TEXT("Pad");
}

void UXiaoMiBuilder::BuilderColor()
{
	Product->Color = TEXT("Black");
}

UProducts* UProductsDirector::Construct(UProductsBuilder* Builder)
{
	Builder->BuilderBrand();
	Builder->BuilderKind();
	Builder->BuilderColor();
	return Builder->GetProduct();
}

// Sets default values
ABuilderPattern::ABuilderPattern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilderPattern::BeginPlay()
{
	Super::BeginPlay();

	UProductsDirector* ProductDirector = NewObject<UProductsDirector>();
	
	UProducts* Apple = ProductDirector->Construct(NewObject<UAppleBuilder>());
	Apple->Showinfo();

	UProducts* XiaoMi = ProductDirector->Construct(NewObject<UXiaoMiBuilder>());
	XiaoMi->Showinfo();
}

// Called every frame
void ABuilderPattern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

