#define _CRT_SECURE_NO_WA06RNINGS  
#include<iostream>
using namespace std;

//模板类
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

//模板类派普通类生时 需要具体化模板类 C++编译器需要知道父类的数据类型具体是什么
//==>要知道父类所占的内存大小是多少 只有数据类型固定下来 才知道如何分配内存
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

//从模板类派生模板类
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
	//模板类(本身就是类型化的)==>具体的类==>定义具体的变量
	A06<int>a1(1); //模板类是抽象的==>需要进行 类型具体
	a1.print_A06();
	Test05(a1);
	B06 b1(10, 20);
	b1.print_B06();
	b1.print_A06();
	system("pause");
	return EXIT_SUCCESS;
}
