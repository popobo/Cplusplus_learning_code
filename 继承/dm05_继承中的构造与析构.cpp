#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent05
{
public:
	void PrintP()
	{
		cout << "father:" << a << endl;;
	}
	Parent05(int in_a)
	{
		a = in_a;
		cout << "Parent05" << endl;
	}
	void set_a(int in_a)
	{
		a = in_a;
	}
	~Parent05()
	{
		cout << "~Parent050()" << endl;
	}
private:
	int a;
};

class Child050 :public Parent05
{
public:
	void PrintC()
	{
		cout << "child:" << c << endl;
	}
	void set_c(int in_c)
	{
		c = in_c;
	}
	Child050(int in_c, int in_a) :Parent05(in_a)
	{
		c = in_c;
		cout << "Child050" << endl;
	}
	~Child050()
	{
		cout << "~Child050" << endl;
	}
protected:
private:
	int c;
};


void Test050()
{
	Child050 c1(2, 3);
}

int main05()
{
	Test050();

	system("pause");
	return EXIT_SUCCESS;
}
