#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent07
{
public:
	//构造函数中调用虚函数能发生多态吗
	Parent07(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent07" << endl;
	}
protected:
private:
	int a;
};

class Child07 :public Parent07
{
public:
	Child07(int a = 0, int b = 0) :Parent07(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << "Child07" << endl;
	}
protected:
private:
	int b;
};

void Test07(Parent07&p)
{
	p.print();
}

int main07()
{
	Child07 c1;
	Child07*pc;
	Parent07*pp;
	Child07 array[] = { Child07(1),Child07(2),Child07(3) };
	pc = array;
	pp = array;
	pc->print();
	pp->print();
	pp++;
	pc++;
	pc->print();//子类和父类的指针步长不一样的问题
	pp->print();//多态是用父类指针指向子类对象和父类步长++是两个不同的概念
	system("pause");
	return EXIT_SUCCESS;
}
