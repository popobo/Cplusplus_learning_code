#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Parent
{
public:
	void print_parent()
	{
		cout << "a:" << a << endl;
		cout << "b:" << b << endl;
	}
	int a;
	int b;
protected:
private:
};

class Child: public Parent
{
public:
protected:
private:
};

int main01()
{
	Child c;
	c.print_parent();
	system("pause");
	return EXIT_SUCCESS;
}
