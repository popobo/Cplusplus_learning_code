#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;


class Test03
{
public:
	void initTest03(int a, int b)
	{
		m_a = a;
		m_b = b;
	}
private:
	int m_a;
	int m_b;
};


int main3()
{
	Test03 t1;
	t1.initTest03(1, 2);
	Test03 tArray[3];
	tArray[0].initTest03(3, 4);
	tArray[1].initTest03(3, 4);
	tArray[2].initTest03(3, 4);
	system("pause");
	return EXIT_SUCCESS;
}
