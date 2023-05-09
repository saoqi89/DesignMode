// Fill out your copyright notice in the Description page of Project Settings.


#include "PrototypePattern/PrototypePattern.h"

void UProductPhones::ShowInfos()
{
	UE_LOG(LogTemp, Warning, TEXT("Brand:[%s], Capacity:[%d], Color:[%s]"), *this->GetName(), Capacity, *Color);
}

UProductPhones* UVivo::Clone()
{
	UVivo* UVivo = NewObject<class UVivo>();
	UVivo->Capacity = Capacity;
	UVivo->Color = Color;
	return UVivo;
}

UOppo::UOppo()
{
	Capacity = 256;
	Color = TEXT("White");
}

UProductPhones* UOppo::Clone()
{
	UOppo* Oppo = NewObject<UOppo>();
	Oppo->Capacity = Capacity;
	Oppo->Color = Color;
	Oppo->RAM = RAM;
	return Oppo;
}

void UOppo::ShowInfos()
{
	UE_LOG(LogTemp, Warning, TEXT("Brand:[%s], Capacity:[%d], Color:[%s], RAM[%d]"), *this->GetName(), Capacity, *Color, RAM);
}

UProductPhones* UPhoneSpawner::Spawner(UProductPhones* PhonesClass)
{
	return PhonesClass->Clone();
}

// Sets default values
APrototypePattern::APrototypePattern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APrototypePattern::BeginPlay()
{
	Super::BeginPlay();

	UPhoneSpawner* PhoneSpawner = NewObject<UPhoneSpawner>();

	UVivo* Vivo = PhoneSpawner->Spawner<UVivo>();
	UVivo* VivoCopy = Cast<UVivo>(PhoneSpawner->Spawner(Vivo));
	Vivo->ShowInfos();
	VivoCopy->ShowInfos();

	UOppo* Oppo = PhoneSpawner->Spawner<UOppo>();
	UOppo* OppoCopy = Cast<UOppo>(PhoneSpawner->Spawner(Oppo));
	Oppo->ShowInfos();
	OppoCopy->ShowInfos();
	
}

// Called every frame
void APrototypePattern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

