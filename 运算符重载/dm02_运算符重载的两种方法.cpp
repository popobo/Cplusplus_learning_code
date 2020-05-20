#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class  Complex02
{
public:
	Complex02(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void PrintCom()
	{
		cout << this->a << endl;
		cout << this->b << endl;
	}
	//成员函数实现+运算符重载
	Complex02 operator+(Complex02&obj) 
	{
		Complex02 temp(this->a + obj.a, this->b + obj.b);
		return temp;
	}
	Complex02&operator--()
	{
		--this->a;
		--this->b;
		return*this;
	}
	//后置--
	Complex02 operator--(int)
	{
		Complex02 temp = *this;
		this->a--;
		this->b--;
		return temp;
	}
	
public:
	int a;
	int b;
};

Complex02 myAdd(Complex02&c1, Complex02&c2)
{
	Complex02 temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}

//全局函数 实现运算符重载
Complex02 operator+(Complex02&c1, Complex02&c2)
{
	Complex02 temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}

Complex02 operator-(Complex02&c1, Complex02&c2)
{
	Complex02 temp(c1.a - c2.a, c1.b - c2.b);
	return temp;
}
Complex02&operator++(Complex02&c1)
{
	c1.a++;
	c1.b++;
	return c1;
}
//后置++ int是占位符
Complex02 operator++(Complex02&c, int)
{
	Complex02 temp = c;
	c.a++;
	c.b++;
	return temp;
}

int main02()
{
	int a = 0, b = 0;
	int c;
	c = a + b;//基础数据类型 编译器已经知道了 如果运算

	Complex02 c1(1, 2), c2(3, 4);//类也是数据类型 用户自定义数据类型 C++编译器 是不知道如何进行运算的
	Complex02 c3;
	Complex02 c4 = myAdd(c1, c2);
	c4.PrintCom();
	
	Complex02 c5 = c1 - c2;
	c5.PrintCom();
	++c5;
	c5.PrintCom();
	--c5;
	c5.PrintCom();
	c5++.PrintCom();
	c5.PrintCom();
	c5--.PrintCom();
	c5.PrintCom();
	//Complex02 c5 = operator+(c1, c4);
	//c5.PrintCom();

	//Complex02 c6 = c1 + c5;
	//c6.PrintCom();
	//C++编译给程序员提供一种机制
	//让自定义数据类型也可以进行操作符运算 ->运算符重载机制
	system("pause");
	return EXIT_SUCCESS;
}
