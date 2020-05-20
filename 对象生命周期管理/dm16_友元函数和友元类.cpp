#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class A16
{
public:
	friend void modifyA16(A16*pA); //声明的位置与public或pravite等无关
	friend class B16;
	A16(int a = 0, int b = 0)
	{
		this->m_a = a;
		this->m_b = b;
	}
	void PrintA16()
	{
		cout << "a:" << this->m_a << endl;
	}
protected:
private:
	int m_a;
	int m_b;
};

void modifyA16(A16*pA)
{
	pA->m_a = 100;
}

class B16
{
public:
	void setA16()
	{
		a1.m_a = 100;
	}
	void PrintB16()
	{
		cout << "A16:a1.a:" << a1.m_a << endl;
	}
protected:
private:
	A16 a1;
};

//为什么设计友元类函数
//1.java->1.class(字节码)->反射机制分析1.class找到类对象 直接修改类的私有属性
//反射机制 成为一种标准 jdk sun做成标准 jdk的api函数中有体现
//AOP
//2.cpp->
//预编译 编译 连接 生成  gcc -E gcc -g
//gcc -o 1.exe 1.c
//汇编往回找 很难
//所以开了个后门 即友元函数 友元类 
int main16()
{
	A16 a1(1, 3);
	modifyA16(&a1);
	a1.PrintA16();
	B16 b1;
	b1.setA16();
	b1.PrintB16();
	system("pause");
	return EXIT_SUCCESS;
}
