<<<<<<< HEAD
#include <iostream>
#include <mutex>
using namespace std;

/*
   ��ľ�̬��Ա������ʹ��֮ǰ����������ⲿ���г�ʼ������ʹ�á�
*/

//����ģʽ
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

//����ģʽ
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
/*----------ǣ�������߳����̰߳�ȫ������--------*/

/*���ڶ���ģʽ��û���̰߳�ȫ����ģ�������ģʽ�·��ʵ��������ʱ����������Ѿ������������ˡ�
  Ҫ�������ģʽ���̰߳�ȫ���⣬��õĽ����������ʹ�û�������*/
//����ģʽ --- ˫�ؼ������
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

//����ģʽ --- ��̬�ֲ�����
/*
	��̬�ֲ������洢��ȫ����������
	��������Ϊ�������������
	��̬�ֲ������ĳ�ʼ����ȫ�ֱ������ƣ�
	�����Ϊ��ʾ��ʼ������ôC++���Զ���ʼ��Ϊ0��
	������δ����ʼ��ʱ�����в���ִ�ж�Ӧ���ȴ��ñ�����ʼ����ɡ�
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
	����ģʽ��ȱ�����ڴ���ʵ�������ʱ���а�ȫ���⣬���������Լ����ڴ���˷ѣ�����ò����Ͳ�ȥ�����ڴ��ˣ���
	����ģʽ���෴�������ǲ���Ҫ���ʵ�������ʱ�����Ѿ�������������ռ����һ���ڴ档
	�������ڵļ�������ԣ��ڴ����������㹻��ģ����ȱ�ݿ��Ա����ӡ�
*/
void main()
{
	
}
=======
#include <iostream>
#include <mutex>
using namespace std;

/*
   ��ľ�̬��Ա������ʹ��֮ǰ����������ⲿ���г�ʼ������ʹ�á�
*/

//����ģʽ
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

//����ģʽ
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
/*----------ǣ�������߳����̰߳�ȫ������--------*/

/*���ڶ���ģʽ��û���̰߳�ȫ����ģ�������ģʽ�·��ʵ��������ʱ����������Ѿ������������ˡ�
  Ҫ�������ģʽ���̰߳�ȫ���⣬��õĽ����������ʹ�û�������*/
//����ģʽ --- ˫�ؼ������
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

//����ģʽ --- ��̬�ֲ�����
/*
	��̬�ֲ������洢��ȫ����������
	��������Ϊ�������������
	��̬�ֲ������ĳ�ʼ����ȫ�ֱ������ƣ�
	�����Ϊ��ʾ��ʼ������ôC++���Զ���ʼ��Ϊ0��
	������δ����ʼ��ʱ�����в���ִ�ж�Ӧ���ȴ��ñ�����ʼ����ɡ�
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
	����ģʽ��ȱ�����ڴ���ʵ�������ʱ���а�ȫ���⣬���������Լ����ڴ���˷ѣ�����ò����Ͳ�ȥ�����ڴ��ˣ���
	����ģʽ���෴�������ǲ���Ҫ���ʵ�������ʱ�����Ѿ�������������ռ����һ���ڴ档
	�������ڵļ�������ԣ��ڴ����������㹻��ģ����ȱ�ݿ��Ա����ӡ�
*/
>>>>>>> ca4495876d162e7bd9e68ab73713665b33b1d38e
