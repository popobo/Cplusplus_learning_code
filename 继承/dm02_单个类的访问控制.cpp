#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent02
{
public: //����ڲ��ⲿ����ʹ��
	int a;
protected:// ������ڲ�ʹ�� �ڼ̳е������п��� 
	int b;
private://ֻ��������ڲ�ʹ�� 
	int c;
};


//��Ŀ������ һ�����public�̳�
class Child02:public Parent02
{
public:
	void PrintChild02()
	{
		cout << "a:" << this->a << endl;
		cout << "b:" <<this->b << endl;
	}
protected:
private:
};

//�����̳� ������ public protected -> ������ protected protected 
//protected �ؼ��� ���εĳ�Ա�����ͳ�Ա���� ��Ϊ���ڼ�����ʹ��
class Child021:protected Parent02
{
public:
	void PrintChild021()
	{
		cout << "a:" << this->a << endl;
		cout << "b:" << this->b << endl;
	}
protected:
private:
};

//˽�м̳�
class Child022 :private Parent02
{
public:
	void PrintChild022()
	{
		cout << "a:" << this->a << endl;
		cout << "b:" << this->b << endl;
	}
protected:
private:
};

int main02()
{
	
	system("pause");
	return EXIT_SUCCESS;
}
