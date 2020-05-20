#include "iostream"
using namespace std;

/*
C++中没有接口的概念
C++中可以使用纯虚函数实现接口
接口类中只有函数原型定义，没有任何数据的定义。
*/

class Interface110
{
public:
	virtual void print() = 0;
	virtual int add(int a, int b) = 0;
};

class Interface210
{
public:
	virtual void print() = 0;
	virtual int add(int a, int b) = 0;
	virtual int minus(int a, int b) = 0;
};

class Parent10
{
public:
	int a;
};
//C++ 多继承也必须实现抽象类中的所有方法 包括重名 但返回值不同或者参数列表不同的方法
class Child10 : public Parent10, public Interface110, public Interface210
{
public:
	void print()
	{
		cout << "Child10::print" << endl;
	}

	int add(int a, int b)
	{
		return a + b;
	}

	int minus(int a, int b)
	{
		return a - b;
	}
};

int main10()
{
	Child10 c;

	c.print();

	cout << c.add(3, 5) << endl;
	cout << c.minus(4, 6) << endl;

	Interface110* i1 = &c;
	Interface210* i2 = &c;

	cout << i1->add(7, 8) << endl;
	cout << i2->add(7, 8) << endl;
	system("pause");
	return EXIT_SUCCESS;
}
