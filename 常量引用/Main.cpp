#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//常引用的知识结构
struct Teacher
{
	char name[64];
	int age;
};


void PrintTeacher(const Teacher&myt)
{
	cout << myt.age << endl;
	cout << myt.name << endl;
}
int main()
{
	//普通引用
	int a = 10;
	int&b = a;
	int c = 0;
	b = c;
	c = 11;
	a = 22;
	cout << b << endl;
	//常引用 让变量引用只有只读属性 即不能通过y修改x
	int x = 20;
	const int&y = x;
	//y = 20; 报错

	//常引用 初始化 分两种情况
	//1 用变量初始化常引用
	int x1 = 30;
	const int&y1 = x1;
	

	//2 用字面量初始化常引用 c++编译器把a放在符号表里
	const int x2 = 10;
	// int&y2 = 41; 报错 字面量没有内存地址 而普通引用就是给内存取多个门牌号
	const int&y2 = 10;//c++编译器会分配内存空间
	


	system("pause");
	return EXIT_SUCCESS;
}
