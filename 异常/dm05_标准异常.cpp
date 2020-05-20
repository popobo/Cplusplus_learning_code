// out_of_range
#include "iostream"
using namespace std;
#include <stdexcept>  

class Teacher
{
public:
	Teacher(int age)  //构造函数, 通过异常机制 处理错误
	{
		if (age > 100)
		{
			throw out_of_range("年龄太大");
		}
		this->age = age;
	}
protected:
private:
	int age;
};

class MyException05 :public exception
{
public:
	MyException05(const char*p)
	{
		this->m_p = p;
	}
	virtual const char*what()
	{
		cout << "MyException 类型 " << m_p << endl;
		return m_p;
	}
private:
	const char*m_p;
};

void test_myexception05()
{
	throw MyException05("函数异常");
}

void main()
{
	try
	{
		Teacher t1(102);
	}
	catch (out_of_range e)
	{

		cout << e.what() << endl;
	}
		
	try
	{
		test_myexception05();
	}
	catch (MyException05&e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "未知错误" << endl;
	}
	exception e;
	system("pause");
}
