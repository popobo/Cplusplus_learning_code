#include <cstdlib>
#include <iostream>

using namespace std;

class Parent04
{
public:
	Parent04()
	{
		cout << "Parent04:printf()..do" << endl;
	}
	void printabc()
	{
		cout << "abc" << endl;
	}
public:
	//�������������Ĺ�ϵΪ���� ������ͬһ������
	virtual void func()
	{
		cout << "Parent04:void func()" << endl;
	}

	virtual void func(int i)
	{
		cout << "Parent:void func(int i)" << endl;
	}

	virtual void func(int i, int j)
	{
		cout << "Parent:void func(int i, int j)" << endl;
	}
};

class Child04 : public Parent04
{

public:
	//��д��Ϊ���� �麯����д��������̬ ���麯����д �ض���
	void printabc()
	{
		cout << "abcd" << endl;
	}
	//�˴�2��������������func������ʲô��ϵ �����޷����ظ���ĺ��� �����ͬ�������������Ƹ���
	void func(int i, int j)
	{
		cout << "Child:void func(int i, int j)" << " " << i + j << endl;
	}

	//�˴�3�������ģ�������func������ʲô��ϵ
	void func(int i, int j, int k)
	{
		cout << "Child:void func(int i, int j, int k)" << " " << i + j + k << endl;
	}
};

void run01(Parent04* p)
{
	p->func(1, 2);
}

int main()
{
	Parent04 p;

	p.func();
	p.func(1);
	p.func(1, 2);

	Child04 c;
	//c.func(); //����1
	c.Parent04::func();
	c.func(1, 2);
	c.Parent04::func();
	c.printabc();
	c.Parent04::printabc();
	run01(&p);
	run01(&c);

	system("pause");
	return 0;
}
