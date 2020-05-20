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
	c = a + b;//基础数据类型 编译器已经知道了 如果运算

	Complex c1(1, 2), c2(3, 4);//类也是数据类型 用户自定义数据类型 C++编译器 是不知道如何进行运算的
	Complex c3;
	Complex c4 = myAdd(c1, c2);
	c4.PrintCom();

	Complex c5 = operator+(c1, c4);
	c5.PrintCom();

	Complex c6 = c1 + c5;
	c6.PrintCom();
	//C++编译给程序员提供一种机制
	//让自定义数据类型也可以进行操作符运算 ->运算符重载机制
	system("pause");
	return EXIT_SUCCESS;
}
