#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Test14
{
public:
	Test14(int a, int b)//--->>Test(Test*this, int a, int b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	void PrintTest()
	{
		cout << "a:" << m_a << endl;
		cout << "b:" << this->m_b << endl;
	}


	//这里的const 
	//1 const 写在设备呢位置 没有关系
	//2 const 修饰的是？
	//3 const 修饰的是this指针所指向的内存空间 即const Test*this
	//4 真正的编译器中是 const Test*const this
	const void opVar() //const
	{
		cout << "a:" << m_a << endl;
		cout << "b:" << this->m_b << endl;
	}
protected:
private:
	int m_a;
	int m_b;
};

int main14()
{
	Test14 mt = Test14(11, 22);
	mt.PrintTest();
	system("pause");
	return EXIT_SUCCESS;
}
