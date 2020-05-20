#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Test10
{
public:
	Test10()
	{
		cout << "Test10" << endl;
	}
	Test10(int _a)
	{
		cout << "Test10" << endl;
		m_a = _a;
	}
	~Test10()
	{
		cout << "~Test10" << endl;
	}
protected:
private:
	int m_a;
};

int main11()
{
	int*p = (int*)malloc(sizeof(int));
	*p = 10;

	int*p2 = new int;
	*p2 = 30;

	int*p3 = new int[30];
	for (int i = 0; i < 30; i++)
	{
		p3[i] = i;
		cout << p3[i] << endl;
	}
	
	free(p);
	delete p2;
	delete[]p3; //数据不要忘记[]

	Test10*tp1 = (Test10*)malloc(sizeof(Test10));
	free(tp1);
	tp1 = NULL;

	//new 能执行类的构造函数 delete 能执行析构函数
	Test10*tp2 = new Test10(10);
	delete tp2;
	tp2 = NULL;

	system("pause");
	return EXIT_SUCCESS;
}
