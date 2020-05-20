#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;


class Base108
{
public:
	Base108(int b1)
	{
		this->b1 = b1;
	}
	void print_Base108()
	{
		cout << b1 << endl;
	}
	int b1;
protected:
private:
	
};

class Base208
{
public:
	Base208(int b2)
	{
		this->b2 = b2;
	}
	void print_Base208()
	{
		cout << b2 << endl;
	}
	int b2;
protected:
private:
	
};

class B08 :public Base108, public Base208
{
public:
	B08(int c) :Base108(c + 1), Base208(c + 2)
	{
		this->c = c;
	}
	void PrintB08()
	{
		cout << c << b1 << b2 << endl;
	}
protected:
private:
	int c;
};




int main08()
{
	B08 b1(1);
	b1.PrintB08();
	b1.print_Base108();
	b1.print_Base208();
	system("pause");
	return EXIT_SUCCESS;
}
