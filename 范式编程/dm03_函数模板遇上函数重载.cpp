#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

void myswap020(int&a, int&b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

//����ҵ���߼�һ��
//�����������Ͳ�һ��
void myswap021(char&a, char&b)
{
	char c = '\0';
	c = a;
	a = b;
	b = c;
}

//�����Ͳ����� �������Ա
//template����C++��������ʼ��ʽ���
template <typename T>
void myswap022(T&a, T&b)
{
	T c = a;
	a = b;
	b = c;
}

void myswap023(int a, char b)
{
	cout << "hello world!" << endl;
}


int main03()
{
	int x = 10;
	int y = 20;
	myswap020(x, y);
	cout << "x:" << x << endl;
	cout << "y:" << y << endl;
	char a = 'a';
	char b = 'b';

	//����ģ��ĵ���
	//1 ��ʽ���͵���
	myswap022<int>(x, y);
	//2 �������Ƶ�
	myswap022(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	myswap023(x, a);
	//���û�����ϸ������ƥ�� 
	//����ֵ�����������ʽ����ת��
	myswap023(a, x);//��ͨ�������� ���Խ�����ʽ����ת��
	myswap023(a, a);//���ú���ģ�壨����:���Ͳ����������ϸ������ͽ���ƥ�� ��������Զ�����ת��
	system("pause");
	return EXIT_SUCCESS;
}
