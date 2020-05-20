#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//知道语法即可
class A09
{
public:
	A09(int a)
	{
		cout << "A09" << endl;
		this->a = a;
	}
	int a;
protected:
private:
};

class B109:virtual public A09
{
public:
	B109(int b1) :A09(b1 + 1)
	{
		cout << "B109" << endl;
		this->b1 = b1;
	}
	int b1;
protected:
private:
};

class B209:virtual public A09
{
public:
	B209(int b2) :A09(b2 + 2)
	{
		cout << "B209" << endl;
		this->b2 = b2;
	}
	int b2;
protected:
private:
};

class C09 :public B109, public B209
{
public:
	C09(int c) :B109(c * 109), B209(c * 209), A09(c * 9)
	{
		this->c = c;
	}
	int c;
protected:
private:
};

class D109
{
public:
	int k;
protected:
private:
};


class D209
{
public:
	int k;
protected:
private:
};

//虚继承无法解决这种情况
class E09 :public D109, public D209
{
public:
protected:
private:
};
int main()
{
	C09 c1(1);
	cout << c1.b1 << endl;
	cout << c1.b2 << endl;
	cout << c1.a << endl;
	E09 e1;
	e1.D109::k = 100;
	e1.D209::k = 200;

	system("pause");
	return EXIT_SUCCESS;
}
