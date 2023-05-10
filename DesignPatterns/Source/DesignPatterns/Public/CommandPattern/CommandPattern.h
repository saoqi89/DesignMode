// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CommandPattern.generated.h"

UCLASS()
class DESIGNPATTERNS_API ACommandPattern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACommandPattern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

//最低层的调用类
UCLASS()
class DESIGNPATTERNS_API UReceivers : public UObject
{
	GENERATED_BODY()
public:
	void MakeiPhone();
	void MakeiPad();
};

//基类
class DESIGNPATTERNS_API Command
{
public:
	Command(UReceivers* PostUReceivers): mUReceivers(PostUReceivers) {}
	virtual void Excute() PURE_VIRTUAL(,);
	virtual ~Command() {}
	virtual FString GetCommandName() PURE_VIRTUAL(, return TEXT(""););
	
protected:
	UReceivers* mUReceivers;
	FString CommandName;
};

//具体类，用于构造产品A
class DESIGNPATTERNS_API ConstructCommandA : public Command
{
public:
	ConstructCommandA(UReceivers* PostUReceivers) : Command(PostUReceivers){}
	virtual void Excute() override;
	virtual FString GetCommandName() override;
};

//具体类，用于构造产品B
class DESIGNPATTERNS_API ConstructCommandB : public Command
{
public:
	ConstructCommandB(UReceivers* PostUReceivers) : Command(PostUReceivers){}
	virtual void Excute() override;
	virtual FString GetCommandName() override;
};

class DESIGNPATTERNS_API Invokes
{
public:
	void Add(Command* PostCommand);
	void Remove(Command* PostCommand);
	void RemoveAll();
	void Notify();
private:
	std::vector<Command*> mVectorCommand;
};


