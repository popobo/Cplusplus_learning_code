#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

void myfunc(int a)
{
	printf("%d\n", a);
}

void myfunc(char*p)
{
	printf("%s\n", p);
}

void myfunc(int a, int b)
{
	cout << a << " " << b << endl;
}
//����ָ��
//����һ����������
typedef void (myTypeFunc)(int a, int b);
//����һ������ָ������
typedef void (*myPTypeFunc)(int a, int b);
//����һ������ָ�����
void(*myVarFunc)(int a, int b);

int main()
{
	myTypeFunc*p1 = NULL;
	myPTypeFunc p2 = NULL;
	p1 = myfunc;
	p1(1, 2);
	myVarFunc = myfunc;

	system("pause");
	return EXIT_SUCCESS;
}
