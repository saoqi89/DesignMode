#include <iostream>
using namespace std;

// ComplexProduct class stores three strings
class ComplexProduct
{
public:
	void SetValueA(const string& a) 
	{ 
		valueA = a; 
	}
	void SetValueB(const string& b) 
	{ 
		valueB = b; 
	}
	void SetValueC(const string& c) 
	{ 
		valueC = c; 
	}
	void ShowInfo() 
	{ 
		cout << "A: " << valueA << " B: " << valueB << " C: " << valueC << endl; 
	}
private:
	string valueA;
	string valueB;
	string valueC;
};

// AbstractBuilder is an abstract class that defines the interface for creating complex products
class AbstractBuilder
{
public:
	virtual ~AbstractBuilder() {}
	virtual void BuilderPartA() = 0;
	virtual void BuilderPartB() = 0;
	virtual void BuilderPartC() = 0;

	ComplexProduct* GetComplex() 
	{ 
		return complexProduct; 
	}
	void CreateComplex() 
	{ 
		complexProduct = new ComplexProduct; 
	}
protected:
	ComplexProduct* complexProduct;
};

// ProductBuilderA is a concrete class that implements the interface defined by AbstractBuilder
class ProductBuilderA : public AbstractBuilder
{
public:
	virtual ~ProductBuilderA() {}
	virtual void BuilderPartA() override
	{
		complexProduct->SetValueA("1");
	}
	virtual void BuilderPartB() override
	{
		complexProduct->SetValueB("2");
	}
	virtual void BuilderPartC() override
	{
		complexProduct->SetValueC("3");
	}
};

// ProductBuilderB is a concrete class that implements the interface defined by AbstractBuilder
class ProductBuilderB : public AbstractBuilder
{
public:
	virtual ~ProductBuilderB() {}
	virtual void BuilderPartA() override
	{
		complexProduct->SetValueA("7");
	}
	virtual void BuilderPartB() override
	{
		complexProduct->SetValueB("8");
	}
	virtual void BuilderPartC() override
	{
		complexProduct->SetValueC("9");
	}
};

// Director class uses the AbstractBuilder interface to create complex products
class Director
{
public:
	void ShowInfo() const
	{
		abstractBuilder->GetComplex()->ShowInfo();
		delete abstractBuilder->GetComplex();
	}
	void SetBuilder(AbstractBuilder* bp)
	{
		abstractBuilder = bp;
	}
	void ConstructProduct()
	{
		abstractBuilder->CreateComplex();
		abstractBuilder->BuilderPartA();
		abstractBuilder->BuilderPartB();
		abstractBuilder->BuilderPartC();
	}
private:
	AbstractBuilder* abstractBuilder;
};

// Test function for the Builder Pattern
void BuilderPattern_test()
{
	Director director;
	AbstractBuilder* productA = new ProductBuilderA;
	AbstractBuilder* productB = new ProductBuilderB;
	director.SetBuilder(productA);
	director.ConstructProduct();
	director.ShowInfo();
	director.SetBuilder(productB);
	director.ConstructProduct();
	director.ShowInfo();
	delete productA;
	delete productB;
}

