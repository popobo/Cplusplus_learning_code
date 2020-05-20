#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent04
{
public:
	void PrintP()
	{
		cout << "father:" << a << endl;;
	}
	Parent04()
	{
		cout << "Parent04" << endl;
	}
	void set_a(int in_a)
	{
		a = in_a;
	}
private:
	int a;
};

class Child040:public Parent04
{
public:
	void PrintC()
	{
		cout << "child:" << c << endl;
	}
	void set_c(int in_c)
	{
		c = in_c;
	}
	Child040()
	{
		cout << "Child040" << endl;
	}
protected:
private:
	int c;
};


void Test04(Parent04*base)
{
	base->PrintP();
}
void Test041(Parent04&base)
{
	base.PrintP();
}

int main04()
{
	Parent04 p1;
	p1.set_a(10000);
	p1.PrintP();
	Child040 c1;
	c1.set_c(10086);
	c1.set_a(10010);
	c1.PrintC();
	c1.PrintP();

	//基类指针（引用）指向子类对象
	Parent04*p = NULL;
	p = &c1;
	p->PrintP();
	//指针做函数参数
	Test04(&c1);
	//引用作函数参数
	Test041(c1);

	//第二层含义
	//可以让父类对象初始化子类对象
	//子类是一种特殊的父类
	
	Parent04 p2 = c1;
	p2.PrintP();

	system("pause");
	return EXIT_SUCCESS;
}
