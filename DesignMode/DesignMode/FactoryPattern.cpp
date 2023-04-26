#include <iostream>
using namespace::std;

/*
	����ģʽ
*/

//�����Ʒ��
class AbstractProduct
{
public:
	virtual void ShowInfo() = 0;
	virtual ~AbstractProduct() {};
};

//�����ƷA
class ProductA : public AbstractProduct
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ << endl;
	}
};

//�����ƷB
class ProductB : public AbstractProduct
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ << endl;
	}
};

//���󹤳���
class AbstractFactory
{
public:
	virtual AbstractProduct* CreateProduct() = 0;
	virtual ~AbstractFactory() {}
};

//���󹤳���A
class FactoryA : public AbstractFactory
{
public:
	virtual AbstractProduct* CreateProduct() override
	{
		return new ProductA;
	}

	~FactoryA() override { cout << __FUNCTION__ << endl; }
};

//���󹤳���B
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
