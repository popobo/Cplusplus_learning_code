#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//�����õ�֪ʶ�ṹ
struct Teacher
{
	char name[64];
	int age;
};


void PrintTeacher(const Teacher&myt)
{
	cout << myt.age << endl;
	cout << myt.name << endl;
}
int main()
{
	//��ͨ����
	int a = 10;
	int&b = a;
	int c = 0;
	b = c;
	c = 11;
	a = 22;
	cout << b << endl;
	//������ �ñ�������ֻ��ֻ������ ������ͨ��y�޸�x
	int x = 20;
	const int&y = x;
	//y = 20; ����

	//������ ��ʼ�� ���������
	//1 �ñ�����ʼ��������
	int x1 = 30;
	const int&y1 = x1;
	

	//2 ����������ʼ�������� c++��������a���ڷ��ű���
	const int x2 = 10;
	// int&y2 = 41; ���� ������û���ڴ��ַ ����ͨ���þ��Ǹ��ڴ�ȡ������ƺ�
	const int&y2 = 10;//c++������������ڴ�ռ�
	


	system("pause");
	return EXIT_SUCCESS;
}
