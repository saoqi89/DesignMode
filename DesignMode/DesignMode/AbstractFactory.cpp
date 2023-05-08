#include <iostream>
using namespace std;

//�����Ʒ������
class AbstractProduct
{
public:
	virtual void ShowInfo() = 0;
	virtual ~AbstractProduct();
};

//�����Ʒ�࣬��Ծ���Ĳ�Ʒ��A
class AbstractProductA : public AbstractProduct
{
public:
	virtual void ShowInfo()override
	{
		cout << __FUNCTION__ " This is AbstractProductA" << endl;
	}
};

//�����Ʒ�࣬��Ծ���Ĳ�Ʒ��B
class AbstractProductB : public AbstractProduct
{
public:
	virtual void ShowInfo()override
	{
		cout << __FUNCTION__ " This is AbstractProductB" << endl;
	}
};

//�����Ʒ��A
class ProductA : public AbstractProductA
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ " This is ProductA iPhon" << endl;
	}
};

//�����Ʒ��A2
class ProductA2 : public AbstractProductA
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ " This is ProductA2 HuaWei" << endl;
	}
};

//�����Ʒ��B
class ProductB : public AbstractProductB
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ " This is ProductB iPad" << endl;
	}
};

//�����Ʒ��B2
class ProductB2 : public AbstractProductB
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ " This is ProductB2 HuaWei Pad" << endl;
	}
};

//���󹤳���
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

//���幤����A
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

//���幤����B
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

