#include <iostream>
using namespace std;

//抽象产品类族类
class AbstractProduct
{
public:
	virtual void ShowInfo() = 0;
	virtual ~AbstractProduct();
};

//抽象产品类，相对具体的产品类A
class AbstractProductA : public AbstractProduct
{
public:
	virtual void ShowInfo()override
	{
		cout << __FUNCTION__ " This is AbstractProductA" << endl;
	}
};

//抽象产品类，相对具体的产品类B
class AbstractProductB : public AbstractProduct
{
public:
	virtual void ShowInfo()override
	{
		cout << __FUNCTION__ " This is AbstractProductB" << endl;
	}
};

//具体产品类A
class ProductA : public AbstractProductA
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ " This is ProductA iPhon" << endl;
	}
};

//具体产品类A2
class ProductA2 : public AbstractProductA
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ " This is ProductA2 HuaWei" << endl;
	}
};

//具体产品类B
class ProductB : public AbstractProductB
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ " This is ProductB iPad" << endl;
	}
};

//具体产品类B2
class ProductB2 : public AbstractProductB
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ " This is ProductB2 HuaWei Pad" << endl;
	}
};

//抽象工厂类
class AbstractFactory
{
public:
	virtual AbstractProductA* CreateProductA() = 0
	{
		return nullptr;
	}

	virtual AbstractProductB* CreateProductB() = 0
	{
		return nullptr;
	}
};

//具体工厂类A
class ProductFactoryX : public AbstractFactory
{
public:
	virtual AbstractProductA* CreateProductA() override
	{
		return new ProductA;
	}

	virtual AbstractProductB* CreateProductB() override
	{
		return new ProductB;
	}
};

//具体工厂类B
class ProductFactoryY : public AbstractFactory
{
public:
	virtual AbstractProductA* CreateProductA() override
	{
		return new ProductA2;
	}

	virtual AbstractProductB* CreateProductB() override
	{
		return new ProductB2;
	}
};

void AbstractFactory_test()
{
	ProductFactoryX* FactoryA = new ProductFactoryX;
	FactoryA->CreateProductA()->ShowInfo();
	FactoryA->CreateProductB()->ShowInfo();

	ProductFactoryY* FactoryB = new ProductFactoryY;
	FactoryB->CreateProductA()->ShowInfo();
	FactoryB->CreateProductB()->ShowInfo();
}

