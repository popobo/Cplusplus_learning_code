#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;


class D
{
public:
	D(int _d)
	{
		cout << "D" << endl;
		m_d = _d;
	}
	~D()
	{
		cout << "~D" << endl;
	}
private:
	int m_d;
};

int main9()
{
	D(1);//临时对象(匿名对象) 只存在一行 因为无变量接收
	cout << "end" << endl;
	system("pause");
	return EXIT_SUCCESS;
}
