#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add03(int a, int b) //�����ʵ����
{
	printf("func add03\n");
	return a + b;
}

int add04(int a, int b) //�����ʵ����
{
	printf("func add04\n");
	return a + b + 20;
}

typedef int(*my_func_p)(int a, int b);

//��ӵ��� ָ������������ ���԰������ʵ��������ĵ��÷ֿ���
//�����˽����
int Test(my_func_p in_mfp)//����ĵ����� 
{
	return in_mfp(1, 2);
}

int Test1(int(*my_func_pp)(int a, int b))
{
	return	my_func_pp(1, 2);
}
int main()
{
	add03(1, 2);
	my_func_p mfp1 = NULL;
	mfp1 = add03;
	mfp1(1, 2);

	printf("%d\n", Test(add04));
	printf("%d\n", Test1(add04));



	system("pause");
	return EXIT_SUCCESS;
}