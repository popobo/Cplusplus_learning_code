#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Test02
{
public:
	Test02()
	{
		cout << "�޲ι���" << endl;
	}
	Test02(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout << "�вι���" << endl;
	}
	Test02(int a)
	{
		m_a = a;
		m_b = 0;
	}
	Test02(const Test02&obj)
	{
		cout << "�������캯��" << endl;
	}
private:
	int m_a;
	int m_b;
};

int main2()
{
	Test02 t1;//�����޲ι��� ����Ҫ����
	
	Test02 t2(1, 2);//1�������вι��� ���ŷ� C++�������Զ��ص��ù��캯��
	Test02 t3 = (3, 4);//2��C++��=���й�����ǿ ���ű��ʽ ȥ���һ��ֵ �������ȼ���� һ����������� C++�������Զ��ص��ù��캯��
	 
	Test02 t4 = Test02(5, 6);//3��ֱ�ӵ��ù��캯�� �ֶ��ص��ù��캯�� �����һ���������� ����:���������ȥ���� t4����ĳ�ʼ��
	t1 = t4;//t4 copy�� t1 //��ֵ���� 
	// ����ĳ�ʼ���Ͷ���ĸ�ֵ ��������ͬ�ĸ���
	system("pause");
	return EXIT_SUCCESS;
}
