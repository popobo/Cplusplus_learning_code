#include <cstdlib>
#include <iostream>

using namespace std;

class Parent04
{
public:
	Parent04()
	{
		cout << "Parent04:printf()..do" << endl;
	}
	void printabc()
	{
		cout << "abc" << endl;
	}
public:
	//以下三个函数的关系为重载 发生在同一个类中
	virtual void func()
	{
		cout << "Parent04:void func()" << endl;
	}

	virtual void func(int i)
	{
		cout << "Parent:void func(int i)" << endl;
	}

	virtual void func(int i, int j)
	{
		cout << "Parent:void func(int i, int j)" << endl;
	}
};

class Child04 : public Parent04
{

public:
	//重写分为两类 虚函数重写将发生多态 非虚函数重写 重定义
	void printabc()
	{
		cout << "abcd" << endl;
	}
	//此处2个参数，和子类func函数是什么关系 子类无法重载父类的函数 父类的同名函数将被名称覆盖
	void func(int i, int j)
	{
		cout << "Child:void func(int i, int j)" << " " << i + j << endl;
	}

	//此处3个参数的，和子类func函数是什么关系
	void func(int i, int j, int k)
	{
		cout << "Child:void func(int i, int j, int k)" << " " << i + j + k << endl;
	}
};

void run01(Parent04* p)
{
	p->func(1, 2);
}

int main()
{
	Parent04 p;

	p.func();
	p.func(1);
	p.func(1, 2);

	Child04 c;
	//c.func(); //问题1
	c.Parent04::func();
	c.func(1, 2);
	c.Parent04::func();
	c.printabc();
	c.Parent04::printabc();
	run01(&p);
	run01(&c);

	system("pause");
	return 0;
}
