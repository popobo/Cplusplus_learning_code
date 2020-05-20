#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//�����������(����һ��Ԥ�ȶ���õĽӿڱ��)
//����� ģ�͵Ļ��� 
class Figure09
{
public:
	//�ṩһ��ͳһ�Ľӿ� ������ʹ�� ���������ȥʵ��
	virtual void get_area() = 0;
};

class Circle09 :public Figure09
{
public:
	Circle09(double a, double b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void get_area()
	{
		cout << "Circle:" << 3.14*a*a << endl;
	}
protected:
private:
	double a;
	double b;
};

class Tri09 :public Figure09
{
public:
	Tri09(double a, double b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void get_area()
	{
		cout << "Tri:" << 0.5*a*b << endl;
	}
private:
	double a;
	double b;
};


void Test09(Figure09*p)
{
	p->get_area();
}

int main09()
{
	//Figer09 f; �����಻�ܱ�ʵ����
	Figure09*fp = NULL;
	Circle09 c1(1, 2);
	Tri09 t1(2, 3);
	
	Test09(&c1);
	Test09(&t1);
	system("pause");
	return EXIT_SUCCESS;
}
