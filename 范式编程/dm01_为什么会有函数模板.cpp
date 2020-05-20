#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

void myswap010(int&a, int&b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

//����ҵ���߼�һ��
//�����������Ͳ�һ��
void myswap011(char&a, char&b)
{
	char c = '\0';
	c = a;
	a = b;
	b = c;
}

//�����Ͳ����� �������Ա
//template����C++��������ʼ��ʽ���
template <typename T>
void myswap012(T&a, T&b)
{
	T c = a;
	a = b;
	b = c;
}



int main01()
{
	int x = 10;
	int y = 20;
	myswap010(x, y);
	cout << "x:" << x << endl;
	cout << "y:" << y << endl;
	char a = 'a';
	char b = 'b';

	//����ģ��ĵ���
	//1 ��ʽ���͵���
	myswap012<int>(x, y);
	//2 �������Ƶ�
	myswap012(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	system("pause");
	return EXIT_SUCCESS;
}
