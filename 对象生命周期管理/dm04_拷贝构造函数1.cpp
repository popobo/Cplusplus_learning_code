#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Test04
{
public:
	Test04()
	{
		cout << "无参构造" << endl;
	}
	Test04(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout << "有参构造" << endl;
	}
	Test04(int a)
	{
		m_a = a;
		m_b = 0;
	}
	Test04(const Test04&obj)
	{
		m_a = 100;
		m_b = 200;
		cout << "拷贝构造函数" << endl;
	}
private:
	int m_a;
	int m_b;
};

//拷贝构造函数 用一个对象初始化另一个对象
int main4()
{
	Test04 t1(1, 2);
	//拷贝构造的两种语法
	Test04 t2 = t1; //用t1初始t2
	Test04 t4(t1);
	
	Test04 t3;//用t1赋值给t3
	t3 = t1;
	system("pause");
	return EXIT_SUCCESS;
}
