// Fill out your copyright notice in the Description page of Project Settings.


#include "ObserverPattern/ObserverPattern.h"

void UWorker::SetTarget(UTarget* Target)
{
	mTarget = Target;
}

void UWorker::Update()
{
	Super::Update();
	if (mTarget)
	{
		int32 Num = mTarget->GetTargetLevel();
		switch (Num)
		{
		case 1:
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " %s Target Level: %d, Is Warning"), *this->GetName(),Num);
			break;
		case 2:
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " %s Target Level: %d, Is Error"), *this->GetName(),Num);
			break;
		case 3:
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " %s Target Level: %d, Is Nore"), *this->GetName(),Num);
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ " %s Target Level: %d, Is Default"), *this->GetName(),Num);
			break;
		}
	}
}

void USubject::BindNotify(UObserver* Observer)
{
	if (!ObserversList.Contains(Observer))
	{
		ObserversList.Add(Observer);
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ "%s is Bind"), *Observer->GetName());
		Observer->Update();
	}
}

void USubject::UnBindNotify(UObserver* Observer)
{
	if (ObserversList.Contains(Observer))
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__ "%s is UnBind"), *Observer->GetName());
		ObserversList.Remove(Observer);
	}
}

void USubject::Notify()
{
	/*for (auto It = ObserversList.CreateIterator(); It; ++It)
	{
		if (IsValid(*It))
		{
			(*It)->Update();
		}
	}*/

	for (const auto It : ObserversList)
	{
		if (IsValid(It))
		{
			It->Update();
		}
	}
}

void UTarget::UpdateTargetLevel(int32 Level)
{
	mLevel = Level;
	Notify();
}

int32 UTarget::GetTargetLevel()
{
	return  mLevel;
}

// Sets default values
AObserverPattern::AObserverPattern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObserverPattern::BeginPlay()
{
	Super::BeginPlay();

	//创建目标类实例
	UTarget* Target = NewObject<UTarget>();
	
	//创建观察者类实例1
	UWorker* Worker1 = NewObject<UWorker>();
	Worker1->SetTarget(Target);
	Target->BindNotify(Worker1);

	//创建观察者类实例2
	UWorker* Worker2 = NewObject<UWorker>();
	Worker2->SetTarget(Target);
	Target->BindNotify(Worker2);

	//更新目标等级
	Target->UpdateTargetLevel(1);
	Target->UpdateTargetLevel(2);

	//取消绑定Worker2
	Target->UnBindNotify(Worker1);

	//更新目标等级
	Target->UpdateTargetLevel(3);
	Target->UpdateTargetLevel(4);
	
}

// Called every frame
void AObserverPattern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

