#include<iostream>
using namespace std;

int getA1()
{
	int a;
	a = 10;
	return a;
}

int&getA2()
{
	int a;
	a = 20; 
	return a;//�������ջ�ϵ����� ���������
}

int*getA3()
{
	int a;
	a = 30;
	return &a;
}

int getA4()
{
	static int a = 10;
	a++;
	return a;
}

int&getA5()
{
	static int a = 10;
	a++;
	return a;
}
//���ر�����ֵ
int g()
{
	static int a = 10;
	a++;
	return a;
}
//���ر�������
int&g2()
{
	static int a = 10;
	a++;
	return a;
}


int main()
{
	//int a1 = getA1();

	//int a2 = getA2();

	//int&a3 = getA2();

	//����ֵΪ����
	//printf("%d", a3);
	//cout << a3;

	//int a1 = getA4();

	//int a4 = getA4();

	//int a2 = getA5();

	//int&a3 = getA5();

	//printf("a1:%d a4:%d a2:%d a3:%d", a1, a4, a2, a3);
	
	//��������ֵ

	//g1() = 100;//����
	int x = g2();
	g2() = 300;//���� ��������ֵ��һ������ ����ֵ �����ڴ�ռ�����ǿ��õ�
	cout << x<<endl;
	int y = g2();
	cout << y << endl;

	system("pause");

	return EXIT_SUCCESS;
}
