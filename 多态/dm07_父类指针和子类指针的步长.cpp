#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent07
{
public:
	//���캯���е����麯���ܷ�����̬��
	Parent07(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent07" << endl;
	}
protected:
private:
	int a;
};

class Child07 :public Parent07
{
public:
	Child07(int a = 0, int b = 0) :Parent07(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << "Child07" << endl;
	}
protected:
private:
	int b;
};

void Test07(Parent07&p)
{
	p.print();
}

int main07()
{
	Child07 c1;
	Child07*pc;
	Parent07*pp;
	Child07 array[] = { Child07(1),Child07(2),Child07(3) };
	pc = array;
	pp = array;
	pc->print();
	pp->print();
	pp++;
	pc++;
	pc->print();//����͸����ָ�벽����һ��������
	pp->print();//��̬���ø���ָ��ָ���������͸��ಽ��++��������ͬ�ĸ���
	system("pause");
	return EXIT_SUCCESS;
}
