#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class A
{
public:
	A(int _a)
	{
		cout << "A" << _a << endl;
		m_a = _a;
	}
	~A()
	{
		cout << "~A" << m_a << endl;
	}
protected:
private:
	int m_a;
};

class C
{
public:
	C(int _c)
	{
		m_c = _c;
	}
protected:
private:
	int m_c;
};

class B
{
public:
	B(int _b1, int _b2) :a2(1), a1(2), c1(1)
	{
		m_b1 = _b1;
		m_b2 = _b2;
	}
	B(int _b1, int _b2, int m, int n) :a1(m), a2(n), c1(5) 
	{
		cout << "B" << endl;
		m_b1 = _b1;
		m_b2 = _b2;
	}
	~B()
	{
		cout << "~B" << endl;
	}
protected:
//�����϶����ж�� ���ն���˳�� ���г�ʼ�� ��a2 a1
private:
	int m_b1;
	int m_b2;
	A a2; // �����ʹ�� ��ʼ���б� ����������Զ�����Ĭ�Ϲ��캯�� ��ΪA a1;����������ʽ���ǵ���Ĭ�Ϲ��캯���� ����������캯������ʱ
	A a1; // �������ᰴ��������˳����г�ʼ�� �����ǳ�ʼ���б��е�˳��
	const C c1;//const ���εĳ����ı����ʼ�� �ڳ�ʼ���б��н��г�ʼ��
};

void objplay08()
{
	B(1, 2, 3, 4);
}
int main8()
{
	objplay08();
	system("pause");
	return EXIT_SUCCESS;
}
