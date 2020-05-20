#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

void myswap020(int&a, int&b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

//函数业务逻辑一样
//函数参数类型不一样
void myswap021(char&a, char&b)
{
	char c = '\0';
	c = a;
	a = b;
	b = c;
}

//让类型参数化 方便程序员
//template告诉C++编译器开始范式编程
template <typename T>
void myswap022(T&a, T&b)
{
	T c = a;
	a = b;
	b = c;
}

void myswap023(int a, char b)
{
	cout << "hello world!" << endl;
}


int main03()
{
	int x = 10;
	int y = 20;
	myswap020(x, y);
	cout << "x:" << x << endl;
	cout << "y:" << y << endl;
	char a = 'a';
	char b = 'b';

	//函数模板的调用
	//1 显式类型调用
	myswap022<int>(x, y);
	//2 隐类型推导
	myswap022(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	myswap023(x, a);
	//引用会进行严格的类型匹配 
	//而赋值操作会进行隐式类型转换
	myswap023(a, x);//普通函数调用 可以进行隐式类型转换
	myswap023(a, a);//调用函数模板（本质:类型参数话）将严格按照类型进行匹配 不会进行自动类型转换
	system("pause");
	return EXIT_SUCCESS;
}
