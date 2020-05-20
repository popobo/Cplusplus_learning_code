#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class A07
{
public:
	static int a;
	int b;
public:
	
protected:
private:
};
//写出这句话 C++才分配内存 不是简单的变量赋值 
int A07::a = 1;

class B07:public A07
{
public:
	void PrintB07()
	{
		cout << "a:" << A07::a << endl;
	}
	static int a;
protected:
private:
};

int B07::a = 9;

int main07()
{
	B07 b1;
	b1.PrintB07();

	system("pause");
	return EXIT_SUCCESS;
}
