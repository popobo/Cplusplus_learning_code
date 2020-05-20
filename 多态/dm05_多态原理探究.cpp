#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent05
{
public:
	Parent05(int a = 0)
	{
		this->a = a;
	}
	virtual void print() //1 动手脚的地方 写virtual关键字会特殊处理
	{
		cout << "Parent05" << endl;
	}
protected:
private:
	int a;  
};

class Child05:public Parent05
{
public:
	Child05(int a = 0,int b=0):Parent05(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << "Child05" << endl;
	}
protected:
private:
	int b;
};

void Test05(Parent05&p)
{
	p.print();//有多态发生 //2 动手脚
	//效果:传来子类对象 执行子类的print函数 传来父类对象 执行父类的print函数
	//C++编译器根部不需要区分是子类对象 还是父类对象
	//父类对象和子类对象分别有vptr指针 ==》虚函数==》函数的入口地址
	//迟绑定 运行的时候 C++编译器才去判断
}

int main05()
{
	Parent05 p1(1);//3 动手脚 C++编译器会在对象中添加一个vptr指针
	Child05 c1(2, 3);

	Test05(p1);
	Test05(c1);
	system("pause");
	return EXIT_SUCCESS;
}
