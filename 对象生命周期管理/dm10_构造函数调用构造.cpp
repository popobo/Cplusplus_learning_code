#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;


//构造函数中
class Mytest
{
public:
	Mytest(int _a, int _b)
	{
		m_a = _a;
		m_b = _b;
		Mytest(_a, _b, 100);
	}
	Mytest(int _a, int _b, int _c)
	{	
		m_a = _a;
		m_b = _b;
		m_c = _c;
	}
	void PrintTest()
	{
		cout << m_a << m_b << m_c << endl;
	}
	~Mytest()
	{
		cout << "~Mytest" << endl;
	}
protected:
private:
	int m_a;
	int m_b;
	int m_c;
};

void objplay10()
{
	Mytest test = Mytest(1, 2);
	test.PrintTest();
}

int main10()
{
	objplay10();
	system("pause");
	return EXIT_SUCCESS;
}
