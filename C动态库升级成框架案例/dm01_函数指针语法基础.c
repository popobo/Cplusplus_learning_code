#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�������ͻ����﷨֪ʶ����
//����һ����������
//����һ����������
//����һ��ָ���������͵�ָ�� �������ָ��


int main01()
{
	int a[10];//a�������������Ԫ�صĵ�ַ &a������������ĵ�ַ ������һ�� a+1:4 &a+1:40
	
	typedef int(myTypeArray)[10];
	myTypeArray arr;
	arr[0] = 10;
	printf("%d\n", arr[0]);

	typedef int(*p_myarray)[10];
	p_myarray parr;//���� sizeof(in)*10
	parr = &arr;
	(*parr)[0] = 20;
	printf("%d\n", arr[0]);

	int(*MyPointer)[10];
	MyPointer = parr;
	(*MyPointer)[0] = 50;
	printf("%d\n", arr[0]);

	system("pause");
	return EXIT_SUCCESS;
}