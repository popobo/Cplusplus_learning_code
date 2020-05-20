#define _CRT_SECURE_NO_WARNINGS  
#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Complex09
{
public:
	Complex09(T a, T b);
	void print_com();
	Complex09 operator+(Complex09&obj);
	friend ostream&operator<<<T>(ostream&out, Complex09<T>&obj);

	friend Complex09 Mysub07(Complex09&c1, Complex09&c2)
	{
		Complex09 temp(c1.a - c2.a, c1.b - c2.b);
		return temp;
	}
protected:
private:
	T a;
	T b;
};