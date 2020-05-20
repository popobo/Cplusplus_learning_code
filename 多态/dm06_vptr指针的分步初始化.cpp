#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent06
{
public:
	//构造函数中调用虚函数能发生多态吗
	Parent06(int a = 0)
	{
		this->a = a;
		print();
	}
	virtual void print() 
	{
		cout << "Parent06" << endl;
	}
protected:
private:
	int a;
};

class Child06 :public Parent06
{
public:
	Child06(int a = 0, int b = 0) :Parent06(a)
	{
		this->b = b;
		print();
	}
	void print()
	{
		cout << "Child06" << endl;
	}
protected:
private:
	int b;
};

void Test06(Parent06&p)
{
	p.print();
}

int main06()
{
	Parent06 p1(1);
	Child06 c1(2, 3); //定义一个子类对象 在这个过程中 在父类构造函数中调用虚函数print() 能发生多态吗
					  //不能 子类的vptr指针是分步初始化的
					  //调用父类构造函数时 子类的vptr指针指向父类的虚函数表
					  //调用子类的构造函数时 子类的vptr指针才指向父类的虚函数表

	Test06(p1);
	Test06(c1);
	system("pause");
	return EXIT_SUCCESS;
}
