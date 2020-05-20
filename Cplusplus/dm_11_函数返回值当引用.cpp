#include<iostream>
using namespace std;

int getA1()
{
	int a;
	a = 10;
	return a;
}

int&getA2()
{
	int a;
	a = 20; 
	return a;//如果返回栈上的引用 会产生问题
}

int*getA3()
{
	int a;
	a = 30;
	return &a;
}

int getA4()
{
	static int a = 10;
	a++;
	return a;
}

int&getA5()
{
	static int a = 10;
	a++;
	return a;
}
//返回变量的值
int g()
{
	static int a = 10;
	a++;
	return a;
}
//返回变量本身
int&g2()
{
	static int a = 10;
	a++;
	return a;
}


int main()
{
	//int a1 = getA1();

	//int a2 = getA2();

	//int&a3 = getA2();

	//返回值为引用
	//printf("%d", a3);
	//cout << a3;

	//int a1 = getA4();

	//int a4 = getA4();

	//int a2 = getA5();

	//int&a3 = getA5();

	//printf("a1:%d a4:%d a2:%d a3:%d", a1, a4, a2, a3);
	
	//函数当左值

	//g1() = 100;//报错
	int x = g2();
	g2() = 300;//可行 函数返回值是一个引用 当左值 但其内存空间必须是可用的
	cout << x<<endl;
	int y = g2();
	cout << y << endl;

	system("pause");

	return EXIT_SUCCESS;
}
