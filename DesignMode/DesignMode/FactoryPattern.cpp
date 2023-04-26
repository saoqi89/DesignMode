#include <iostream>
using namespace::std;

/*
	工厂模式
*/

//抽象产品类
class AbstractProduct
{
public:
	virtual void ShowInfo() = 0;
	virtual ~AbstractProduct() {};
};

//具体产品A
class ProductA : public AbstractProduct
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ << endl;
	}
};

//具体产品B
class ProductB : public AbstractProduct
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ << endl;
	}
};

//抽象工厂类
class AbstractFactory
{
public:
	virtual AbstractProduct* CreateProduct() = 0;
	virtual ~AbstractFactory() {}
};

//具象工厂类A
class FactoryA : public AbstractFactory
{
public:
	virtual AbstractProduct* CreateProduct() override
	{
		return new ProductA;
	}

	~FactoryA() override { cout << __FUNCTION__ << endl; }
};

//具象工厂类B
class FactoryB : public AbstractFactory
{
public:
	virtual AbstractProduct* CreateProduct() override
	{
		return new ProductB;
	}
};

void Factory_test()
{
	AbstractFactory* factorA = new FactoryA;
	AbstractProduct* objA = factorA->CreateProduct();
	objA->ShowInfo();

	AbstractFactory* factorB = new FactoryB;
	AbstractProduct* objB = factorB->CreateProduct();
	objB->ShowInfo();
}
