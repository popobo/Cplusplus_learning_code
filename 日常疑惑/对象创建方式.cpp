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

//i)类名 对象名
//
//默认调用“对象名()”这个构造函数，在栈内存中存在对象名，在堆内存中存在实际对象；
//
//ii)类名 对象名(一个或以上个参数)
//
//默认调用相应的构造函数，在栈内存中存在对象名，在堆内存中也是存在实际对象的；
//
//iii)类名 对象名()
//
//不调用任何构造函数创建对象，仅在栈内在中存在对象名，在堆内存中并不存在实际的对象；
/*




千万注意在一个项目中不要有同名类 否则会出现让人爆炸的Bug




*/
int main()
{
	Cat01 cat1();

	Cat01 cat2;

	system("pause");
	return EXIT_SUCCESS;
}
