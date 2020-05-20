#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class MyArray04
{
public:
	MyArray04(int len);
	~MyArray04();
	int operator[](int index);
	int getLen();
	class eSize 
	{
	public:
		eSize(int size)
		{
			m_size = size;
		}
		virtual void print_err()
		{
			cout << "size:" << m_size <<endl;
		}
	protected:
		int m_size;
	};
	class eNegative :public eSize 
	{
	public:
		eNegative(int size) :eSize(size) {}
		virtual void print_err()
		{
			cout << "eNegative size:" << m_size << endl;
		}
	};
	class eZero :public eSize 
	{
	public:
		eZero(int size) :eSize(size) {}
		virtual void print_err()
		{
			cout << "eZero size:" << m_size << endl;
		}
	};
	class eToobig :public eSize
	{
	public:
		eToobig(int size) :eSize(size) {}
		virtual void print_err()
		{
			cout << "eToobig size:" << m_size << endl;
		}
	};
	class eToosmall :public eSize 
	{
	public:
		eToosmall(int size) :eSize(size) {}
		virtual void print_err()
		{
			cout << "eToosmall size:" << m_size << endl;
		}
	};
	
protected:
private:
	int*m_space;
	int m_len;
};

MyArray04::MyArray04(int len)
{
	if (len < 0)
	{
		throw eNegative(len);
	}
	else if (len == 0)
	{
		throw eZero(len);
	}
	else if (len > 1000)
	{
		throw eToobig(len);
	}
	else if (len < 3)
	{
		throw eToosmall(len);
	}
	m_len = len;
	m_space = new int[m_len];
}

MyArray04::~MyArray04()
{
	if (m_space != NULL)
	{
		delete[]m_space;
		m_space = NULL;
		m_len = 0;
	}
}
int MyArray04::operator[](int index)
{
	return m_space[index];
}

int MyArray04::getLen()
{
	return m_len;
}



int main04()
{
	try
	{
		MyArray04 arr(-1);
		for (int i = 0; i < arr.getLen(); ++i)
		{
			cout << arr[i] << endl;
		}
	}
	//推荐使用多态
	catch (MyArray04::eSize&e)
	{
		e.print_err();
	}
	//不推荐的做法
	catch (MyArray04::eNegative&e)
	{
		cout << "eNegative类型异常" << endl;
	}
	catch (MyArray04::eZero&e)
	{
		cout << "eZero类型异常" << endl;
	}
	catch (MyArray04::eToobig&e)
	{
		cout << "eToobig类型异常" << endl;
	}
	catch (MyArray04::eToosmall&e)
	{
		cout << "eToosmall类型异常" << endl;
	}
	catch (...)
	{
		cout << "未知错误" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}
