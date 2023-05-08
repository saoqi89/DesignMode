#include <iostream>
#include <string>
#include <thread>
using namespace std;
// Product class
//class Pizza {
//public:
//	void setDough(const string& dough) {
//		m_dough = dough;
//	}
//	void setSauce(const string& sauce) {
//		m_sauce = sauce;
//	}
//	void setTopping(const string& topping) {
//		m_topping = topping;
//	}
//	void open() const {
//		cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
//			<< m_topping << " topping. Mmm." << endl;
//	}
//private:
//	string m_dough;
//	string m_sauce;
//	string m_topping;
//};
//
//// Builder Abstract class
//class PizzaBuilder {
//public:
//	virtual ~PizzaBuilder() {};
//	Pizza* getPizza() {
//		return m_pizza;
//	}
//	void createNewPizzaProduct() {
//		m_pizza = new Pizza;
//	}
//	virtual void buildDough() = 0;
//	virtual void buildSauce() = 0;
//	virtual void buildTopping() = 0;
//protected:
//	Pizza* m_pizza;
//};
//
//// Concrete Builder Class
//class HawaiianPizzaBuilder : public PizzaBuilder {
//public:
//	virtual ~HawaiianPizzaBuilder() {};
//	virtual void buildDough() {
//		m_pizza->setDough("cross");
//	}
//	virtual void buildSauce() {
//		m_pizza->setSauce("mild");
//	}
//	virtual void buildTopping() {
//		m_pizza->setTopping("ham+pineapple");
//	}
//};
//
//// Concrete Builder Class
//class SpicyPizzaBuilder : public PizzaBuilder {
//public:
//	virtual ~SpicyPizzaBuilder() {};
//	virtual void buildDough() {
//		m_pizza->setDough("pan baked");
//	}
//	virtual void buildSauce() {
//		m_pizza->setSauce("hot");
//	}
//	virtual void buildTopping() {
//		m_pizza->setTopping("pepperoni+salami");
//	}
//};
//// Director Class
//class Cook {
//public:
//	void openPizza() const {
//		m_pizzaBuilder->getPizza()->open();
//		delete m_pizzaBuilder->getPizza();
//	}
//	void setPizzaBuilder(PizzaBuilder* pb) {
//		m_pizzaBuilder = pb;
//	}
//	void constructPizza() {
//		m_pizzaBuilder->createNewPizzaProduct();
//		m_pizzaBuilder->buildDough();
//		m_pizzaBuilder->buildSauce();
//		m_pizzaBuilder->buildTopping();
//	}
//private:
//	PizzaBuilder* m_pizzaBuilder;
//};
void thread_one()
{
	cout << "This is thread_one" << endl;
}

void thread_two()
{
	cout << "This is Thread_two" << endl;
}

void _test()
{
	thread first(thread_one);
	thread second(thread_two);

	cout << "Main thread" << endl;

	first.join();
	second.join();
	cout << "thread end" << endl;
}

//Client code
int main() {

	_test();

	
	return 0;
}