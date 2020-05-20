#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

void myswap010(int&a, int&b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

//函数业务逻辑一样
//函数参数类型不一样
void myswap011(char&a, char&b)
{
	char c = '\0';
	c = a;
	a = b;
	b = c;
}

//让类型参数化 方便程序员
//template告诉C++编译器开始范式编程
template <typename T>
void myswap012(T&a, T&b)
{
	T c = a;
	a = b;
	b = c;
}



int main01()
{
	int x = 10;
	int y = 20;
	myswap010(x, y);
	cout << "x:" << x << endl;
	cout << "y:" << y << endl;
	char a = 'a';
	char b = 'b';

	//函数模板的调用
	//1 显式类型调用
	myswap012<int>(x, y);
	//2 隐类型推导
	myswap012(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	system("pause");
	return EXIT_SUCCESS;
}
