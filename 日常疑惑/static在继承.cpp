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

	//��Dog1�̳���Animal01�е�animal01 Animal01����animal01�ı� Dog01::animal01Ҳ��֮�ı�
	cout << Dog01::animal01 << endl;
	Dog01 dog1;
	cout << dog1.animal01 << endl;
	cout << "---------------------" << endl;
	Animal01::animal01 = 666;
	cout << Dog01::animal01 << endl;
	cout << dog1.animal01 << endl;

	cout << "---------------------" << endl;
	//��Cat1��������һ��ͬ����static���� ��Animal����animal01�ĸı䲻������Cat01::animal01�ĸı�
	cout << Cat01::animal01 << endl;
	Cat01 cat;
	cout << cat.animal01 << endl;
	cout << "---------------------" << endl;
	Animal01::animal01 = 666;
	cout << Cat01::animal01 << endl;
	cout << cat.animal01 << endl;


	system("pause");
	return EXIT_SUCCESS;
}
