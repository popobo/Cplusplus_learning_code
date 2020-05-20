#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent06
{
public:
	//���캯���е����麯���ܷ�����̬��
	Parent06(int a = 0)
	{
		this->a = a;
		print();
	}
	virtual void print() 
	{
		cout << "Parent06" << endl;
	}
protected:
private:
	int a;
};

class Child06 :public Parent06
{
public:
	Child06(int a = 0, int b = 0) :Parent06(a)
	{
		this->b = b;
		print();
	}
	void print()
	{
		cout << "Child06" << endl;
	}
protected:
private:
	int b;
};

void Test06(Parent06&p)
{
	p.print();
}

int main06()
{
	Parent06 p1(1);
	Child06 c1(2, 3); //����һ��������� ����������� �ڸ��๹�캯���е����麯��print() �ܷ�����̬��
					  //���� �����vptrָ���Ƿֲ���ʼ����
					  //���ø��๹�캯��ʱ �����vptrָ��ָ������麯����
					  //��������Ĺ��캯��ʱ �����vptrָ���ָ������麯����

	Test06(p1);
	Test06(c1);
	system("pause");
	return EXIT_SUCCESS;
}
