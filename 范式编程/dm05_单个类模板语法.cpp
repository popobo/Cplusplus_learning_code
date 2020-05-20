#define _CRT_SECURE_NO_WA05RNINGS  
#include<iostream>
using namespace std;

//模板类
template<typename T>
class A05
{
public:
	A05(T a = 0)
	{
		this->a = a;
	}
	void print_A05()
	{
		cout << "a:" << a << endl;
	}
private:
	T a;
};

void Test05(A05<int>&a)
{
	a.print_A05();
}

int main05()
{
	//模板类(本身就是类型化的)==>具体的类==>定义具体的变量
	A05<int>a1(1); //模板类是抽象的==>需要进行 类型具体
	a1.print_A05();
	Test05(a1);
	system("pause");
	return EXIT_SUCCESS;
}
