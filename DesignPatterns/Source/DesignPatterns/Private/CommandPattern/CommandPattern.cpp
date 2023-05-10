// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandPattern/CommandPattern.h"

void UReceivers::MakeiPhone()
{
	UE_LOG(LogTemp, Warning, TEXT("Make a iPhone"));
}

void UReceivers::MakeiPad()
{
	UE_LOG(LogTemp, Warning, TEXT("Make a iPad"));
}

void ConstructCommandA::Excute()
{
	UE_LOG(LogTemp, Warning, TEXT("ConstructCommandA excute..."));
	mUReceivers->MakeiPhone();
}

FString ConstructCommandA::GetCommandName()
{
	return CommandName = TEXT("iPhone");
}

void ConstructCommandB::Excute()
{
	UE_LOG(LogTemp, Warning, TEXT("ConstructCommandB excute..."));
	mUReceivers->MakeiPad();
}

FString ConstructCommandB::GetCommandName()
{
	return CommandName = TEXT("iPad");
}

void Invokes::Add(Command* PostCommand)
{
	mVectorCommand.push_back(PostCommand);
}

void Invokes::Remove(Command* PostCommand)
{
	mVectorCommand.erase(std::find(mVectorCommand.begin(), mVectorCommand.end(), PostCommand));
	UE_LOG(LogTemp, Warning, TEXT("Remove a %s"), *PostCommand->GetCommandName());
}

void Invokes::RemoveAll()
{
	mVectorCommand.clear();
	UE_LOG(LogTemp, Warning, TEXT("Remove All"));
}

void Invokes::Notify()
{
	for (auto it : mVectorCommand)
	{
		it->Excute();
	}
}

// Sets default values
ACommandPattern::ACommandPattern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACommandPattern::BeginPlay()
{
	Super::BeginPlay();

	UReceivers* PSTUReceivers = NewObject<UReceivers>();
	Command* PstStructCommandA = new ConstructCommandA(PSTUReceivers);
	Command* PstStructCommandB = new ConstructCommandB(PSTUReceivers);
	Invokes* PstInvokes = new Invokes();

	PstInvokes->Add(PstStructCommandA);
	PstInvokes->Add(PstStructCommandA);
	PstInvokes->Add(PstStructCommandB);
	PstInvokes->Notify();
	UE_LOG(LogTemp, Warning, TEXT("-----------------------------------"));

	PstInvokes->Remove(PstStructCommandA);
	PstInvokes->Remove(PstStructCommandB);
	PstInvokes->Notify();
	UE_LOG(LogTemp, Warning, TEXT("-----------------------------------"));

	PstInvokes->RemoveAll();
	PstInvokes->Notify();
	
}

// Called every frame
void ACommandPattern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

