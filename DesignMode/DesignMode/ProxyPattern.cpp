#include <iostream>
using namespace std;

// Base class for communication
class Communication
{
public:
	// Pure virtual function to be implemented by derived classes
	virtual void communication() = 0;
	virtual ~Communication() {}
};

// Derived class for Speaker
class Speaker : public Communication
{
public:
	// Overriding the base class function
	virtual void communication() override
	{
		cout << "Start Speaker" << endl;
	}
};

// Derived class for Proxy
class Proxy : public Communication
{
public:
	Proxy()
	{
		m_isStart = true;
		m_speaker = new Speaker;
	}
	~Proxy()
	{
		if (m_speaker != nullptr)
		{
			delete m_speaker;
		}
	}
	// Function to check if start
	bool isStart()
	{
		return m_isStart;
	}
	// Overriding the base class function
	virtual void communication() override
	{
		if (isStart())
		{
			cout << "---- Copy ----" << endl;
		}
		m_speaker->communication();
	}
private:
	// Flag to check if start
	bool m_isStart = false;
	// Pointer to Speaker object
	Speaker* m_speaker = nullptr;
};

// Test function for Proxy Pattern
void ProxyPattern_test()
{
	// Create a Speaker object
	Communication* comm = new Speaker;
	comm->communication();
	delete comm;
	cout << "============================" << endl;
	// Create a Proxy object
	comm = new Proxy;
	comm->communication();
	delete comm;
}

//int main()
//{
//	// Call the test function
//	ProxyPattern_test();
//	return 0;
//}