#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent01
{
public:
	Parent01(int a)
	{
		this->a = a;
		cout << "Parent01" << endl;
	}
	virtual void print()
	{
		cout << "Parent01" << a << endl;
	}
protected:
private:
	int a;
};

class Child01:public Parent01
{
public:
	Child01(int b) :Parent01(10)
	{
		this->b = b;
		cout << "Child01" << endl;
	}
	virtual void print()
	{
		cout << "Child01" << b << endl;
	}
protected:
private:
	int b;
};

void Test01(Parent01&p)
{
	p.print();//一个调用语句有多种表现形态
}

int main01()
{
	Parent01*p = NULL;
	Parent01 p1(20);
	Child01 c1(25);
	p = &p1;
	p->print();//执行父类的打印函数

	p = &c1;
	p->print();//执行谁的打印函数 父类指针无法使用子类方法

	Parent01&p2 = p1;
	p2.print();
	Parent01&p3 = c1;
	p3.print();
	Test01(c1);
	system("pause");
	return EXIT_SUCCESS;
}
