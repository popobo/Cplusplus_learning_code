#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class  Complex
{
public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void PrintCom()
	{
		cout << this->a << endl;
		cout << this->b << endl;
	}
public:
	int a;
	int b;
};

Complex myAdd(Complex&c1, Complex&c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}

Complex operator+(Complex&c1, Complex&c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}

int main01()
{
	int a = 0, b = 0;
	int c;
	c = a + b;//������������ �������Ѿ�֪���� �������

	Complex c1(1, 2), c2(3, 4);//��Ҳ���������� �û��Զ����������� C++������ �ǲ�֪����ν��������
	Complex c3;
	Complex c4 = myAdd(c1, c2);
	c4.PrintCom();

	Complex c5 = operator+(c1, c4);
	c5.PrintCom();

	Complex c6 = c1 + c5;
	c6.PrintCom();
	//C++���������Ա�ṩһ�ֻ���
	//���Զ�����������Ҳ���Խ��в��������� ->��������ػ���
	system("pause");
	return EXIT_SUCCESS;
}
