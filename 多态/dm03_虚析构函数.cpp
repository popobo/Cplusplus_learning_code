#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class A03
{
public:
	A03()
	{
		p = new char[20];
		strcpy(p, "hello world A");
	}
	virtual~A03()
	{
		cout << "~A03" << endl;
		delete[]p;
	}
protected:
private:
	char*p;
};

class B03: public A03
{
public:
	B03()
	{
		p = new char[20];
		strcpy(p, "hello world B");
	}
	virtual~B03()
	{
		cout << "~B03" << endl;
		delete[]p;
	}
protected:
private:
	char*p;
};

class C03:public B03
{
public:
	C03()
	{
		p = new char[20];
		strcpy(p, "hello world C");
	}
	virtual~C03()
	{
		cout << "~C03" << endl;
		delete[]p;
	}
protected:
private:
	char*p;
};

//通过父类指针将所有的子类对象的析构函数都执行一遍
//即通过父类指针释放所有子类资源
void Test03(A03*base)
{
	delete base;//delete只能析构使用new申请得到的对象 即堆中的数据
}

int main03()
{
	
	C03*c1=new C03();
	Test03(c1);
	system("pause");
	return EXIT_SUCCESS;
}
