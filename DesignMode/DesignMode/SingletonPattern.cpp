<<<<<<< HEAD
#include <iostream>
#include <mutex>
using namespace std;

/*
   类的静态成员变量在使用之前必须在类的外部进行初始化才能使用。
*/

//饿汉模式
class HungerPattern
{
public:
	HungerPattern(const	HungerPattern& obj) = delete;
	HungerPattern& operator	= (const HungerPattern& obj) = delete;
	static HungerPattern* GetInstance()
	{
		return m_HungerPattern;
	}

private:
	HungerPattern() = default;
	static HungerPattern* m_HungerPattern;
};

HungerPattern* HungerPattern::m_HungerPattern = new HungerPattern;

void Hunger_test()
{
	HungerPattern* obj = HungerPattern::GetInstance();
}

//懒汉模式
class LazyPattern
{
public:
	LazyPattern(const LazyPattern& obj) = delete;
	LazyPattern& operator = (const LazyPattern& obj) = delete;
	static LazyPattern* GetInstance()
	{
		if (m_LazyPattern != nullptr)
		{
			m_LazyPattern = new LazyPattern;
		}
		return m_LazyPattern;
	}
private:
	LazyPattern() = default;
	static LazyPattern* m_LazyPattern;
};

LazyPattern* LazyPattern::m_LazyPattern = nullptr;

void Lazy_test()
{
	LazyPattern* obj = LazyPattern::GetInstance();
}

/*----------------------------------------------------------------------------*/
/*----------牵扯到多线程中线程安全的问题--------*/

/*对于饿汉模式是没有线程安全问题的，在这种模式下访问单例对象的时候，这个对象已经被创建出来了。
  要解决懒汉模式的线程安全问题，最常用的解决方案就是使用互斥锁。*/
//饿汉模式 --- 双重检查锁定
namespace DoubleCheck {

	class LazyPattern
	{
	public:
		LazyPattern(const LazyPattern& obj) = delete;
		LazyPattern& operator = (const LazyPattern& obj) = delete;
		static LazyPattern* GetInstance()
		{
			if (m_LazyPattern == nullptr)
			{
				m_Mutex.lock();
				if (m_LazyPattern == nullptr)
				{
					m_LazyPattern = new LazyPattern;
				}
				m_Mutex.unlock();
			}
			return m_LazyPattern;
		}
	private:
		LazyPattern() = default;
		static LazyPattern* m_LazyPattern;
		static mutex m_Mutex;
	};

	LazyPattern* LazyPattern::m_LazyPattern = nullptr;
	mutex LazyPattern::m_Mutex;

	void Lazy_test()
	{
		LazyPattern* obj = LazyPattern::GetInstance();
	}
}

//饿汉模式 --- 静态局部变量
/*
	静态局部变量存储在全局数据区；
	生命周期为整个程序结束；
	静态局部变量的初始化与全局变量类似；
	如果不为显示初始化，那么C++将自动初始化为0；
	当变量未被初始化时，所有并发执行都应当等待该变量初始化完成。
*/
namespace StaticLocalVariable {

	class LazyPattern
	{
	public:
		LazyPattern(const LazyPattern& obj) = delete;
		LazyPattern& operator = (const LazyPattern& obj) = delete;
		static LazyPattern* GetInstance()
		{
			static LazyPattern m_LazyPattern;
			return &m_LazyPattern;
		}
		void Print()
		{
			cout << "!!!!----!!!!" << endl;
		}
	private:
		LazyPattern() = default;
	};

	void Lazy_test()
	{
		LazyPattern* obj = LazyPattern::GetInstance();
		obj->Print();
	}
}

/* 
	懒汉模式的缺点是在创建实例对象的时候有安全问题，但这样可以减少内存的浪费（如果用不到就不去申请内存了）。
	饿汉模式则相反，在我们不需要这个实例对象的时候，它已经被创建出来，占用了一块内存。
	对于现在的计算机而言，内存容量都是足够大的，这个缺陷可以被无视。
*/
void main()
{
	
}
=======
#include <iostream>
#include <mutex>
using namespace std;

/*
   类的静态成员变量在使用之前必须在类的外部进行初始化才能使用。
*/

//饿汉模式
class HungerPattern
{
public:
	HungerPattern(const	HungerPattern& obj) = delete;
	HungerPattern& operator	= (const HungerPattern& obj) = delete;
	static HungerPattern* GetInstance()
	{
		return m_HungerPattern;
	}

private:
	HungerPattern() = default;
	static HungerPattern* m_HungerPattern;
};

HungerPattern* HungerPattern::m_HungerPattern = new HungerPattern;

void Hunger_test()
{
	HungerPattern* obj = HungerPattern::GetInstance();
}

//懒汉模式
class LazyPattern
{
public:
	LazyPattern(const LazyPattern& obj) = delete;
	LazyPattern& operator = (const LazyPattern& obj) = delete;
	static LazyPattern* GetInstance()
	{
		if (m_LazyPattern != nullptr)
		{
			m_LazyPattern = new LazyPattern;
		}
		return m_LazyPattern;
	}
private:
	LazyPattern() = default;
	static LazyPattern* m_LazyPattern;
};

LazyPattern* LazyPattern::m_LazyPattern = nullptr;

void Lazy_test()
{
	LazyPattern* obj = LazyPattern::GetInstance();
}

/*----------------------------------------------------------------------------*/
/*----------牵扯到多线程中线程安全的问题--------*/

/*对于饿汉模式是没有线程安全问题的，在这种模式下访问单例对象的时候，这个对象已经被创建出来了。
  要解决懒汉模式的线程安全问题，最常用的解决方案就是使用互斥锁。*/
//饿汉模式 --- 双重检查锁定
namespace DoubleCheck {

	class LazyPattern
	{
	public:
		LazyPattern(const LazyPattern& obj) = delete;
		LazyPattern& operator = (const LazyPattern& obj) = delete;
		static LazyPattern* GetInstance()
		{
			if (m_LazyPattern == nullptr)
			{
				m_Mutex.lock();
				if (m_LazyPattern == nullptr)
				{
					m_LazyPattern = new LazyPattern;
				}
				m_Mutex.unlock();
			}
			return m_LazyPattern;
		}
	private:
		LazyPattern() = default;
		static LazyPattern* m_LazyPattern;
		static mutex m_Mutex;
	};

	LazyPattern* LazyPattern::m_LazyPattern = nullptr;
	mutex LazyPattern::m_Mutex;

	void Lazy_test()
	{
		LazyPattern* obj = LazyPattern::GetInstance();
	}
}

//饿汉模式 --- 静态局部变量
/*
	静态局部变量存储在全局数据区；
	生命周期为整个程序结束；
	静态局部变量的初始化与全局变量类似；
	如果不为显示初始化，那么C++将自动初始化为0；
	当变量未被初始化时，所有并发执行都应当等待该变量初始化完成。
*/
namespace StaticLocalVariable {

	class LazyPattern
	{
	public:
		LazyPattern(const LazyPattern& obj) = delete;
		LazyPattern& operator = (const LazyPattern& obj) = delete;
		static LazyPattern* GetInstance()
		{
			static LazyPattern m_LazyPattern;
			return &m_LazyPattern;
		}
		void Print()
		{
			cout << "!!!!----!!!!" << endl;
		}
	private:
		LazyPattern() = default;
	};

	void Lazy_test()
	{
		LazyPattern* obj = LazyPattern::GetInstance();
		obj->Print();
	}
}

/* 
	懒汉模式的缺点是在创建实例对象的时候有安全问题，但这样可以减少内存的浪费（如果用不到就不去申请内存了）。
	饿汉模式则相反，在我们不需要这个实例对象的时候，它已经被创建出来，占用了一块内存。
	对于现在的计算机而言，内存容量都是足够大的，这个缺陷可以被无视。
*/
>>>>>>> ca4495876d162e7bd9e68ab73713665b33b1d38e
