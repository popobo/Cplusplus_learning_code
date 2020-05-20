#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class A
{
public:
	A(int _a)
	{
		cout << "A" << _a << endl;
		m_a = _a;
	}
	~A()
	{
		cout << "~A" << m_a << endl;
	}
protected:
private:
	int m_a;
};

class C
{
public:
	C(int _c)
	{
		m_c = _c;
	}
protected:
private:
	int m_c;
};

class B
{
public:
	B(int _b1, int _b2) :a2(1), a1(2), c1(1)
	{
		m_b1 = _b1;
		m_b2 = _b2;
	}
	B(int _b1, int _b2, int m, int n) :a1(m), a2(n), c1(5) 
	{
		cout << "B" << endl;
		m_b1 = _b1;
		m_b2 = _b2;
	}
	~B()
	{
		cout << "~B" << endl;
	}
protected:
//如果组合对象有多个 按照定义顺序 进行初始化 即a2 a1
private:
	int m_b1;
	int m_b2;
	A a2; // 如果不使用 初始化列表 则编译器会自动调用默认构造函数 因为A a1;这种声明方式就是调用默认构造函数的 而且如果构造函数传参时
	A a1; // 编译器会按照声明的顺序进行初始化 而不是初始化列表中的顺序
	const C c1;//const 修饰的常量的必须初始化 在初始化列表中进行初始化
};

void objplay08()
{
	B(1, 2, 3, 4);
}
int main8()
{
	objplay08();
	system("pause");
	return EXIT_SUCCESS;
}
