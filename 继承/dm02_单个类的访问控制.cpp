#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent02
{
public: //类的内部外部均能使用
	int a;
protected:// 在类的内部使用 在继承的子类中可用 
	int b;
private://只能在类的内部使用 
	int c;
};


//项目开发中 一般均是public继承
class Child02:public Parent02
{
public:
	void PrintChild02()
	{
		cout << "a:" << this->a << endl;
		cout << "b:" <<this->b << endl;
	}
protected:
private:
};

//保护继承 父类中 public protected -> 子类中 protected protected 
//protected 关键字 修饰的成员变量和成员函数 是为了在家族中使用
class Child021:protected Parent02
{
public:
	void PrintChild021()
	{
		cout << "a:" << this->a << endl;
		cout << "b:" << this->b << endl;
	}
protected:
private:
};

//私有继承
class Child022 :private Parent02
{
public:
	void PrintChild022()
	{
		cout << "a:" << this->a << endl;
		cout << "b:" << this->b << endl;
	}
protected:
private:
};

int main02()
{
	
	system("pause");
	return EXIT_SUCCESS;
}
