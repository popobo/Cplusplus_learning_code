#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//dynamic_cast 
class Animal01
{
public:
	virtual void cry() = 0;
	static int animal01;
};

int Animal01::animal01 = 10;

class Dog01 :public Animal01
{
public:
	virtual void cry()
	{
		cout << "wangwang" << endl;
	}
	void doSwim()
	{
		cout << "��Ҫ����" << endl;
	}
};

class Cat01 :public Animal01
{
public:
	virtual void cry()
	{
		cout << "miaomiao" << endl;
	}
	void doTree()
	{
		cout << "��Ҫ����" << endl;
	}
	static int animal01;
};

int Cat01::animal01 = 99;


void print_buf01(const char*const p)
{
	//����ԱҪȷ��pָ����ڴ�ռ��ܱ��޸� �������������Ժ��
	char*p1 = NULL;
	p1 = const_cast<char*>(p);
	p1[0] = 'Z';
	cout << p << endl;
	//const char* ==> char* ��ֻ������ȥ��
}

class Book01
{
public:
	void print_price()
	{
		cout << m_iPrice << endl;
	}
private:
	int m_iPrice;
};

void obj_play(Animal01*base)
{
	base->cry();
	Dog01*p_dog = dynamic_cast<Dog01*>(base);
	if (p_dog != NULL)
	{
		p_dog->cry();
		p_dog->doSwim();
	}
	Cat01*p_cat = dynamic_cast<Cat01*>(base);
	if (p_cat != NULL)
	{
		p_cat->cry();
		p_cat->doTree();
		cout << p_cat->animal01 << endl;
	}
}

//i)���� ������
//
//Ĭ�ϵ��á�������()��������캯������ջ�ڴ��д��ڶ��������ڶ��ڴ��д���ʵ�ʶ���
//
//ii)���� ������(һ�������ϸ�����)
//
//Ĭ�ϵ�����Ӧ�Ĺ��캯������ջ�ڴ��д��ڶ��������ڶ��ڴ���Ҳ�Ǵ���ʵ�ʶ���ģ�
//
//iii)���� ������()
//
//�������κι��캯���������󣬽���ջ�����д��ڶ��������ڶ��ڴ��в�������ʵ�ʵĶ���
/*




ǧ��ע����һ����Ŀ�в�Ҫ��ͬ���� �����������˱�ը��Bug




*/
int main()
{
	Cat01 cat1();

	Cat01 cat2;

	system("pause");
	return EXIT_SUCCESS;
}
