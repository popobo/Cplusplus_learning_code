#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class  Complex03
{
public:
	friend ostream&operator<<(ostream&out, Complex03&c);
	Complex03(int a = 0, int b = 0)
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
	Complex03 operator+(Complex03&obj)
	{
		Complex03 temp(this->a + obj.a, this->b + obj.b);
		return temp;
	}
	Complex03 operator-(Complex03&obj)
	{
		Complex03 temp(this->a - obj.a, this->b - obj.b);
		return temp;
	}
	Complex03 operator++()
	{
		this->a++;
		this->b++;
		return*this;
	}
	Complex03 operator++(int)
	{
		Complex03 temp = *this;
		++this->a;
		++this->b;
		return temp;
	}
	Complex03&operator--()
	{
		--this->a;
		--this->b;
		return*this;
	}
	//后置--
	Complex03 operator--(int)
	{
		Complex03 temp = *this;
		this->a--;
		this->b--;
		return temp;
	}
	
private:
	int a;
	int b;
};

//Complex03 myAdd(Complex03&c1, Complex03&c2)
//{
//	Complex03 temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}

////全局函数 实现运算符重载
//Complex03 operator+(Complex03&c1, Complex03&c2)
//{
//	Complex03 temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}
//
//Complex03 operator-(Complex03&c1, Complex03&c2)
//{
//	Complex03 temp(c1.a - c2.a, c1.b - c2.b);
//	return temp;
//}
//Complex03&operator++(Complex03&c1)
//{
//	c1.a++;
//	c1.b++;
//	return c1;
//}
////后置++ int是占位符
//Complex03 operator++(Complex03&c, int)
//{
//	Complex03 temp = c;
//	c.a++;
//	c.b++;
//	return temp;
//}


ostream&operator<<(ostream&out, Complex03&c)
{
	out << c.a << "+" << c.b << endl;
	return out;
}
//若用成员函数重写cout<< 则应在iostream写

int main03()
{
	int a = 0, b = 0;
	int c;
	c = a + b;//基础数据类型 编译器已经知道了 如果运算

	Complex03 c1(1, 2), c2(3, 4);//类也是数据类型 用户自定义数据类型 C++编译器 是不知道如何进行运算的
	Complex03 c3;


	Complex03 c5 = c1 - c2;
	c5.PrintCom();
	++c5;
	c5.PrintCom();
	--c5;
	c5.PrintCom();
	c5++.PrintCom();
	c5.PrintCom();
	c5--.PrintCom();
	c5.PrintCom();
	//链式编程 函数返回值当左值需要返回
	cout << c5 << endl;
	//Complex03 c5 = operator+(c1, c4);
	//c5.PrintCom();

	//Complex03 c6 = c1 + c5;
	//c6.PrintCom();
	//C++编译给程序员提供一种机制
	//让自定义数据类型也可以进行操作符运算 ->运算符重载机制
	system("pause");
	return EXIT_SUCCESS;
}
