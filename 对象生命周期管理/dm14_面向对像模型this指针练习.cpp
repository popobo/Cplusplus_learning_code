#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Test14
{
public:
	Test14(int a, int b)//--->>Test(Test*this, int a, int b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	void PrintTest()
	{
		cout << "a:" << m_a << endl;
		cout << "b:" << this->m_b << endl;
	}


	//�����const 
	//1 const д���豸��λ�� û�й�ϵ
	//2 const ���ε��ǣ�
	//3 const ���ε���thisָ����ָ����ڴ�ռ� ��const Test*this
	//4 �����ı��������� const Test*const this
	const void opVar() //const
	{
		cout << "a:" << m_a << endl;
		cout << "b:" << this->m_b << endl;
	}
protected:
private:
	int m_a;
	int m_b;
};

int main14()
{
	Test14 mt = Test14(11, 22);
	mt.PrintTest();
	system("pause");
	return EXIT_SUCCESS;
}
