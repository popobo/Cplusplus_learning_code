#define _CRT_SECURE_NO_WA05RNINGS  
#include<iostream>
using namespace std;

//ģ����
template<typename T>
class A05
{
public:
	A05(T a = 0)
	{
		this->a = a;
	}
	void print_A05()
	{
		cout << "a:" << a << endl;
	}
private:
	T a;
};

void Test05(A05<int>&a)
{
	a.print_A05();
}

int main05()
{
	//ģ����(����������ͻ���)==>�������==>�������ı���
	A05<int>a1(1); //ģ�����ǳ����==>��Ҫ���� ���;���
	a1.print_A05();
	Test05(a1);
	system("pause");
	return EXIT_SUCCESS;
}
