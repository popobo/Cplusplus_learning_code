#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ζ���һ����������
//��ζ���һ������ָ������
//��ζ���һ������ָ�� ָ��������ڵ�ַ

int add(int a, int b)
{
	printf("func add\n");
	return a + b;
}

int main02()
{
	
	add(1, 2);//ֱ�ӵ��� ���������Ǻ�������ڵ�ַ
	typedef int(my_function_type)(int a, int b); //������һ����������
	my_function_type*mfp = NULL;
	mfp = &add;//ϸ��:
	mfp(1, 2);
	mfp = add;//ϸ�� //C������ʷ�汾��ԭ��
	//������ָ�븳ֵʱ��������&fun��ֱ���ú�����fun��������Ϊ������������֮����ʵ����һ����ַ��
	//�������������÷�û�б��ʵĲ��
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