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

void test02() throw(int, char, int*)  //throw()�����κ��쳣 //throw��д �����׳��κ����� 
{									  //ֻ��Ϊ�����ӿɶ���
	Test02 t1(1, 2), t2(3, 4);
	cout << "test02�����쳣" << endl;
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
		cout << "int�쳣" << endl;
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}
