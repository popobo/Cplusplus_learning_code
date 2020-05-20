#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Object06
{
public:
	Object06(int in_a, int in_b)
	{
		m_a = in_a;
		m_b = in_b;
		cout << "Object06" << endl;
	}
	~Object06()
	{
		cout << "~Object06" << endl;
	}
protected:
private:
	int m_a;
	int m_b;
};

class Parent06:public Object06
{
public:
	void PrintP()
	{
		cout << "father:" << m_p << endl;;
	}
	Parent06(char*in_p, int in_a, int in_b) :Object06(in_a, in_b)
	{
		m_p = in_p;
		cout << "Parent06" << endl;
	}
	~Parent06()
	{
		cout << "~Parent060()" << endl;
	}
protected:
	char*m_p;
};

class Child060 :public Parent06
{
public:
	void PrintC()
	{
		cout << "child:mcp:" << mcp << endl;
		cout << "Parent::m_p:" << Parent06::m_p << endl;
		cout << "Child::m_p:" << m_p << endl;
	}

	Child060(char*in_p1, int in_a, int in_b) :Parent06(in_p1, in_a, in_b), obj1(in_a, in_b)
	{
		mcp = in_p1;
		m_p = new char[20];
		strcpy(m_p, "fuck world!");
		cout << "Child060" << endl;
	}
	~Child060()
	{
		cout << "~Child060" << endl;
	}
	void PrintP()
	{
		cout << "child:" << m_p << endl;
	}
protected:
	char*mcp;
	char*m_p;
	Object06 obj1;
};


void Test060()
{
	char*p1 = NULL;
	p1 = new char[sizeof("hello")];
	strcpy(p1, "hello");
	char*p2 = NULL;
	char arr[] = "hello world!";
	p2 = arr;

	Child060 c1(p2, 1, 2);
	c1.PrintC();
	c1.PrintP();
	c1.Parent06::PrintP();
}

int main06()
{
	Test060();
	system("pause");
	return EXIT_SUCCESS;
}
