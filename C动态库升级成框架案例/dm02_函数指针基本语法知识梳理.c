#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//如何定义一个函数类型
//如何定义一个函数指针类型
//如何定义一个函数指针 指向函数的入口地址

int add(int a, int b)
{
	printf("func add\n");
	return a + b;
}

int main02()
{
	
	add(1, 2);//直接调用 函数名就是函数的入口地址
	typedef int(my_function_type)(int a, int b); //定义了一个函数类型
	my_function_type*mfp = NULL;
	mfp = &add;//细节:
	mfp(1, 2);
	mfp = add;//细节 //C兼容历史版本的原因
	//给函数指针赋值时，可以用&fun或直接用函数名fun。这是因为函数名被编译之后其实就是一个地址，
	//所以这里两种用法没有本质的差别
	mfp(1, 2);

	typedef int(*my_func_p)(int a, int b);
	my_func_p mfp2;
	mfp2 = add;
	mfp2(1, 2);
	
	int(*mfp3)(int a, int b);
	mfp3 = add;
	mfp3(1, 2);

	system("pause");
	return EXIT_SUCCESS;
}