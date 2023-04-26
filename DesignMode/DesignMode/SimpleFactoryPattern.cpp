#include <iostream>
using namespace::std;

/*
  �򵥹���ģʽ
*/

//ö�ٳ���Ʒ����
enum class Type : char
{
	ProductA,
	ProductB
};

//�����Ʒ��
class AbstractProduct
{
public:
	virtual void ShowInfo() = 0;

	//���ڲ�Ʒ����ڼ̳й�ϵ����ʵ�ֶ�̬�����Ը������������Ϊ�麯���������Ϳ���ͨ������ָ�������ȥ�����������
	virtual ~AbstractProduct() {}; 
};

//�����Ʒ��A
class ProductA : public AbstractProduct
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ << endl;
	}
};

//�����Ʒ��B
class ProductB : public AbstractProduct
{
public:
	virtual void ShowInfo() override
	{
		cout << __FUNCTION__ << endl;
	}
};

//������
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

//����
void SimpleFactory_test()
{
	FactoryObject* factoryObject = new FactoryObject;
	AbstractProduct* obj1 = factoryObject->CreateProduct(Type::ProductA);
	obj1->ShowInfo();

	AbstractProduct* obj2 = factoryObject->CreateProduct(Type::ProductB);
	obj2->ShowInfo();
}