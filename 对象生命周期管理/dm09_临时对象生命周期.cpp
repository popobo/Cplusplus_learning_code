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
	D(1);//��ʱ����(��������) ֻ����һ�� ��Ϊ�ޱ�������
	cout << "end" << endl;
	system("pause");
	return EXIT_SUCCESS;
}
