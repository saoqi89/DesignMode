#include <iostream>
using namespace::std;

/*
  简单工厂模式
*/

//枚举出产品类型
enum class Type : char
{
	ProductA,
	ProductB
};

//抽象产品类
class AbstractProduct
{
public:
	virtual void ShowInfo() = 0;

	//由于产品类存在继承关系，并实现多态，所以父类的析构函数为虚函数，这样就可以通过父类指针或引用去析构子类对象。
	virtual ~AbstractProduct() {}; 
};

//具体产品类A
class ProductA : public AbstractProduct
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ << endl;
	}
};

//具体产品类B
class ProductB : public AbstractProduct
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ << endl;
	}
};

//工厂类
class FactoryObject
{
public:
	static AbstractProduct* CreateProduct(Type type)
	{
		AbstractProduct* ptr = nullptr;
		switch (type)
		{
		case Type::ProductA:
			ptr = new ProductA;
			break;
		case Type::ProductB:
			ptr = new ProductB;
			break;
		default:
			break;
		}
		return ptr;
	}
};

//测试
void SimpleFactory_test()
{
	FactoryObject* factoryObject = new FactoryObject;
	AbstractProduct* obj1 = factoryObject->CreateProduct(Type::ProductA);
	obj1->ShowInfo();

	AbstractProduct* obj2 = factoryObject->CreateProduct(Type::ProductB);
	obj2->ShowInfo();
}