#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent05
{
public:
	Parent05(int a = 0)
	{
		this->a = a;
	}
	virtual void print() //1 ���ֽŵĵط� дvirtual�ؼ��ֻ����⴦��
	{
		cout << "Parent05" << endl;
	}
protected:
private:
	int a;  
};

class Child05:public Parent05
{
public:
	Child05(int a = 0,int b=0):Parent05(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << "Child05" << endl;
	}
protected:
private:
	int b;
};

void Test05(Parent05&p)
{
	p.print();//�ж�̬���� //2 ���ֽ�
	//Ч��:����������� ִ�������print���� ����������� ִ�и����print����
	//C++��������������Ҫ������������� ���Ǹ������
	//���������������ֱ���vptrָ�� ==���麯��==����������ڵ�ַ
	//�ٰ� ���е�ʱ�� C++��������ȥ�ж�
}

int main05()
{
	Parent05 p1(1);//3 ���ֽ� C++���������ڶ��������һ��vptrָ��
	Child05 c1(2, 3);

	Test05(p1);
	Test05(c1);
	system("pause");
	return EXIT_SUCCESS;
}
