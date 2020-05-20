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

int main()
{
	double dpi = 3.1415926;
	int num1 = (int)dpi;//C����ת��
	int num2 = static_cast<int>(dpi);//��̬����ת�� ����ʱC++�������������ͼ��
	int num3 = dpi;//warning: C��������ʽ����ת���ĵط� ����ʹ��static_cast<>()��������ת��
	
	char*p1 = NULL;
	p1 = new char[sizeof("hello world!")];
	int*p2 = NULL;
	strcpy_s(p1, sizeof("hello world!"), "hello world!");
	//p2 = p1;//����
	//p2 = static_cast<int*>(p1);//����
	p2 = reinterpret_cast<int*>(p1);
	cout << p1 << endl;
	cout << p2 << endl;
	delete[]p1;
	//�ܽ�:ͨ��reinterpret_cast��static_cast��C���Ե�ǿ������ת����������
	
	char buf[] = "hello space!";
	print_buf01(buf);
	
	//dynamic_cast
	Animal01*base = NULL;
	//1 ���԰�����ָ�븳������ָ�� ���Ƿ��������� ��Ҫ����ת��
	Dog01*p_dog = static_cast<Dog01*>(base);
	//2 ��baseת���������Ƕ�����ص�err
	//Book01*book = static_cast<Book01*>(base);
	//3 reinterpret_cast����ǿ������ת��
	Book01*book02 = reinterpret_cast<Book01*>(base);

	//4 dynamic_cast���÷�
	//obj_play(new Cat01());

	cout << Cat01::animal01 << endl;
	Cat01 cat;
	cout << cat.animal01 << endl;

	system("pause");
	return EXIT_SUCCESS;
}
