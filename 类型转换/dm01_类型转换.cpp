#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//dynamic_cast 
class Animal01
{
public:
	virtual void cry() = 0;
	static int animal01;
};

int Animal01::animal01 = 10;

class Dog01 :public Animal01
{
public:
	virtual void cry()
	{
		cout << "wangwang" << endl;
	}
	void doSwim()
	{
		cout << "我要狗爬" << endl;
	}
};

class Cat01 :public Animal01
{
public:
	virtual void cry()
	{
		cout << "miaomiao" << endl;
	}
	void doTree()
	{
		cout << "我要爬树" << endl;
	}
	static int animal01;
};

int Cat01::animal01 = 99;


void print_buf01(const char*const p)
{
	//程序员要确保p指向的内存空间能被修改 否则会造成灾难性后果
	char*p1 = NULL;
	p1 = const_cast<char*>(p);
	p1[0] = 'Z';
	cout << p << endl;
	//const char* ==> char* 把只读属性去掉
}

class Book01
{
public:
	void print_price()
	{
		cout << m_iPrice << endl;
	}
private:
	int m_iPrice;
};

void obj_play(Animal01*base)
{
	base->cry();
	Dog01*p_dog = dynamic_cast<Dog01*>(base);
	if (p_dog != NULL)
	{
		p_dog->cry();
		p_dog->doSwim();
	}
	Cat01*p_cat = dynamic_cast<Cat01*>(base);
	if (p_cat != NULL)
	{
		p_cat->cry();
		p_cat->doTree();
		cout << p_cat->animal01 << endl;
	}
}

int main()
{
	double dpi = 3.1415926;
	int num1 = (int)dpi;//C类型转换
	int num2 = static_cast<int>(dpi);//静态类型转换 编译时C++编译器会做类型检查
	int num3 = dpi;//warning: C语言中隐式类型转换的地方 均可使用static_cast<>()进行类型转换
	
	char*p1 = NULL;
	p1 = new char[sizeof("hello world!")];
	int*p2 = NULL;
	strcpy_s(p1, sizeof("hello world!"), "hello world!");
	//p2 = p1;//报错
	//p2 = static_cast<int*>(p1);//报错
	p2 = reinterpret_cast<int*>(p1);
	cout << p1 << endl;
	cout << p2 << endl;
	delete[]p1;
	//总结:通过reinterpret_cast和static_cast把C语言的强制类型转换都覆盖了
	
	char buf[] = "hello space!";
	print_buf01(buf);
	
	//dynamic_cast
	Animal01*base = NULL;
	//1 可以把子类指针赋给父类指针 但是反过来不行 需要如下转换
	Dog01*p_dog = static_cast<Dog01*>(base);
	//2 把base转换成其他非动物相关的err
	//Book01*book = static_cast<Book01*>(base);
	//3 reinterpret_cast可以强制类型转换
	Book01*book02 = reinterpret_cast<Book01*>(base);

	//4 dynamic_cast的用法
	//obj_play(new Cat01());

	cout << Cat01::animal01 << endl;
	Cat01 cat;
	cout << cat.animal01 << endl;

	system("pause");
	return EXIT_SUCCESS;
}
