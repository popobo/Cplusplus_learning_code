#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class A16
{
public:
	friend void modifyA16(A16*pA); //������λ����public��pravite���޹�
	friend class B16;
	A16(int a = 0, int b = 0)
	{
		this->m_a = a;
		this->m_b = b;
	}
	void PrintA16()
	{
		cout << "a:" << this->m_a << endl;
	}
protected:
private:
	int m_a;
	int m_b;
};

void modifyA16(A16*pA)
{
	pA->m_a = 100;
}

class B16
{
public:
	void setA16()
	{
		a1.m_a = 100;
	}
	void PrintB16()
	{
		cout << "A16:a1.a:" << a1.m_a << endl;
	}
protected:
private:
	A16 a1;
};

//Ϊʲô�����Ԫ�ຯ��
//1.java->1.class(�ֽ���)->������Ʒ���1.class�ҵ������ ֱ���޸����˽������
//������� ��Ϊһ�ֱ�׼ jdk sun���ɱ�׼ jdk��api������������
//AOP
//2.cpp->
//Ԥ���� ���� ���� ����  gcc -E gcc -g
//gcc -o 1.exe 1.c
//��������� ����
//���Կ��˸����� ����Ԫ���� ��Ԫ�� 
int main16()
{
	A16 a1(1, 3);
	modifyA16(&a1);
	a1.PrintA16();
	B16 b1;
	b1.setA16();
	b1.PrintB16();
	system("pause");
	return EXIT_SUCCESS;
}
