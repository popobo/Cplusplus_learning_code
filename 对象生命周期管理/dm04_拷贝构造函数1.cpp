#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Test04
{
public:
	Test04()
	{
		cout << "�޲ι���" << endl;
	}
	Test04(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout << "�вι���" << endl;
	}
	Test04(int a)
	{
		m_a = a;
		m_b = 0;
	}
	Test04(const Test04&obj)
	{
		m_a = 100;
		m_b = 200;
		cout << "�������캯��" << endl;
	}
private:
	int m_a;
	int m_b;
};

//�������캯�� ��һ�������ʼ����һ������
int main4()
{
	Test04 t1(1, 2);
	//��������������﷨
	Test04 t2 = t1; //��t1��ʼt2
	Test04 t4(t1);
	
	Test04 t3;//��t1��ֵ��t3
	t3 = t1;
	system("pause");
	return EXIT_SUCCESS;
}
