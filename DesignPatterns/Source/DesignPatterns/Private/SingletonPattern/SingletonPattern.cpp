// Fill out your copyright notice in the Description page of Project Settings.


#include "SingletonPattern/SingletonPattern.h"

USingleton* USingleton::SingletonInstance = nullptr;
std::mutex  USingleton::Mutex;

USingleton* USingleton::GetInstance()
{
#if 1
	//双重检查锁定
	if (SingletonInstance == nullptr)
	{
		Mutex.lock();
		if (SingletonInstance == nullptr)
		{
			SingletonInstance = NewObject<USingleton>();
		}
		Mutex.unlock();
	}
	return SingletonInstance;
#else
	//静态局部变量
	static USingleton* Singleton = NewObject<USingleton>();
	return Singleton;
#endif
	
}

void USingleton::ShowInfo()
{
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " This is SingletonPattern"));
}

// Sets default values
ASingletonPattern::ASingletonPattern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASingletonPattern::BeginPlay()
{
	Super::BeginPlay();

	USingleton* Instance = USingleton::GetInstance();
	Instance->ShowInfo();
	
}

// Called every frame
void ASingletonPattern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

