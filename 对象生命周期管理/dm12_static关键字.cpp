#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class BB
{
public:
	int getC()
	{
		cout << c;
		return c;
	}
	void addC()
	{
		c++;
	}
	//��̬������ ����ʹ����ͨ��Ա���� ��ͨ��Ա����
	static void printC()
	{
		cout << "c:" << c << endl;
	}
private:
	int m_a;
	int m_b;
	static int c;
};

int BB::c = 0;
int main12()
{
	BB b1, b2;
	b1.getC();
	b2.addC();
	b1.getC();
	b2.addC();
	b2.getC();
	BB::printC();
	system("pause");
	return EXIT_SUCCESS;
}
