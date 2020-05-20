#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Test02
{
public:
	Test02()
	{
		cout << "无参构造" << endl;
	}
	Test02(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout << "有参构造" << endl;
	}
	Test02(int a)
	{
		m_a = a;
		m_b = 0;
	}
	Test02(const Test02&obj)
	{
		cout << "拷贝构造函数" << endl;
	}
private:
	int m_a;
	int m_b;
};

int main2()
{
	Test02 t1;//调用无参构造 不需要括号
	
	Test02 t2(1, 2);//1、调用有参构造 括号法 C++编译器自动地调用构造函数
	Test02 t3 = (3, 4);//2、C++对=进行功能增强 逗号表达式 去最后一个值 但其优先级最低 一般与括号配合 C++编译器自动地调用构造函数
	 
	Test02 t4 = Test02(5, 6);//3、直接调用构造函数 手动地调用构造函数 会产生一个匿名对象 问题:匿名对象的去和留 t4对象的初始化
	t1 = t4;//t4 copy给 t1 //赋值操作 
	// 对象的初始化和对象的赋值 是两个不同的概念
	system("pause");
	return EXIT_SUCCESS;
}
