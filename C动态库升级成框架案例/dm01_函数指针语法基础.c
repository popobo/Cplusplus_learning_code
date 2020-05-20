#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//数组类型基本语法知识梳理
//定义一个数组类型
//定义一个数组类型
//定义一个指向数组类型的指针 数组类的指针


int main01()
{
	int a[10];//a代表的是数组首元素的地址 &a代表整个数组的地址 步长不一样 a+1:4 &a+1:40
	
	typedef int(myTypeArray)[10];
	myTypeArray arr;
	arr[0] = 10;
	printf("%d\n", arr[0]);

	typedef int(*p_myarray)[10];
	p_myarray parr;//步长 sizeof(in)*10
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