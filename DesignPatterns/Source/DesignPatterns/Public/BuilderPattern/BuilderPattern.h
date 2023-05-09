// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderPattern.generated.h"

UCLASS(Blueprintable, BlueprintType)
class  UProducts : public UObject
{
	GENERATED_BODY()
public:
	//产品品牌
	FString Brand = TEXT("None");
	//产品种类
	FString Kind = TEXT("None");
	//颜色
	FString Color = TEXT("None");

	void Showinfo();
};

UCLASS(Abstract)
class  UProductsBuilder : public UObject
{
	GENERATED_BODY()
public:
	UProductsBuilder();
	virtual void BuilderBrand() {};
	virtual void BuilderKind() {};
	virtual void BuilderColor() {};

	UProducts* GetProduct();
	
protected:
	UProducts* Product;
};

UCLASS()
class  UAppleBuilder : public UProductsBuilder
{
	GENERATED_BODY()
public:
	virtual void BuilderBrand() override;
	virtual void BuilderKind() override;
	virtual void BuilderColor() override;
};

UCLASS()
class  UXiaoMiBuilder : public UProductsBuilder
{
	GENERATED_BODY()
public:
	virtual void BuilderBrand() override;
	virtual void BuilderKind() override;
	virtual void BuilderColor() override;
};

UCLASS()
class  UProductsDirector : public UProductsBuilder
{
	GENERATED_BODY()
public:
	UProducts* Construct(UProductsBuilder* Builder);
};

UCLASS()
class DESIGNPATTERNS_API ABuilderPattern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderPattern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
