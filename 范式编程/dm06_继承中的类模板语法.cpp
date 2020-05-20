#define _CRT_SECURE_NO_WA06RNINGS  
#include<iostream>
using namespace std;

//ģ����
template<typename T>
class A06
{
public:
	A06(T a = 0)
	{
		this->a = a;
	}
	void print_A06()
	{
		cout << "a:" << a << endl;
	}
private:
	T a;
};

//ģ��������ͨ����ʱ ��Ҫ���廯ģ���� C++��������Ҫ֪��������������;�����ʲô
//==>Ҫ֪��������ռ���ڴ��С�Ƕ��� ֻ���������͹̶����� ��֪����η����ڴ�
class B06:public A06<int>
{
public:
	B06(int a = 20, int b = 10) : A06<int>(a)
	{
		this->b = b;
	}
	void print_B06()
	{
		cout << "b:" << b << endl;
	}
protected:
private:
	int b;
};

//��ģ��������ģ����
template<typename T>
class C06:public A06<T>
{
public:
	C06(T c, T a):A06(a)
	{
		this->c = c;
	}
protected:
private:
	T c;
};

void Test05(A06<int>&a)
{
	a.print_A06();
}

int main06()
{
	//ģ����(����������ͻ���)==>�������==>�������ı���
	A06<int>a1(1); //ģ�����ǳ����==>��Ҫ���� ���;���
	a1.print_A06();
	Test05(a1);
	B06 b1(10, 20);
	b1.print_B06();
	b1.print_A06();
	system("pause");
	return EXIT_SUCCESS;
}
