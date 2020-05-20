#include "iostream"
using namespace std;

/*
C++��û�нӿڵĸ���
C++�п���ʹ�ô��麯��ʵ�ֽӿ�
�ӿ�����ֻ�к���ԭ�Ͷ��壬û���κ����ݵĶ��塣
*/

class Interface110
{
public:
	virtual void print() = 0;
	virtual int add(int a, int b) = 0;
};

class Interface210
{
public:
	virtual void print() = 0;
	virtual int add(int a, int b) = 0;
	virtual int minus(int a, int b) = 0;
};

class Parent10
{
public:
	int a;
};
//C++ ��̳�Ҳ����ʵ�ֳ������е����з��� �������� ������ֵ��ͬ���߲����б�ͬ�ķ���
class Child10 : public Parent10, public Interface110, public Interface210
{
public:
	void print()
	{
		cout << "Child10::print" << endl;
	}

	int add(int a, int b)
	{
		return a + b;
	}

	int minus(int a, int b)
	{
		return a - b;
	}
};

int main10()
{
	Child10 c;

	c.print();

	cout << c.add(3, 5) << endl;
	cout << c.minus(4, 6) << endl;

	Interface110* i1 = &c;
	Interface210* i2 = &c;

	cout << i1->add(7, 8) << endl;
	cout << i2->add(7, 8) << endl;
	system("pause");
	return EXIT_SUCCESS;
}
