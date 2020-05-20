#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Test02
{
public:
	Test02(int a = 0, int b = 0)
	{
		m_iA = a;
		m_iB = b;
	}
	~Test02()
	{
		cout << "~Test02()" << endl;
	}
private:
	int m_iA;
	int m_iB;
};

void test02() throw(int, char, int*)  //throw()不抛任何异常 //throw或不写 可以抛出任何类型 
{									  //只是为了增加可读性
	Test02 t1(1, 2), t2(3, 4);
	cout << "test02发射异常" << endl;
	throw 1;
}

int main02()
{
	try
	{
		test02();
	}
	catch (int e)
	{
		cout << "int异常" << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}
