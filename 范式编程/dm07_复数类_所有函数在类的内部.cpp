#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

template<typename T>
class Complex07
{
public:
	Complex07(T a, T b)
	{
		this->a = a;
		this->b = b;
	}
	void print_com()
	{
		cout << "a:" << a << " b:" << b << endl;
	}
	Complex07 operator+(Complex07&obj)
	{
		Complex07 temp(a + obj.a, b + obj.b);
		return temp;
	}
	friend ostream&operator<<(ostream&out, Complex07&obj)
	{
		cout << "a:" << obj.a << " b:" << obj.b << endl;
		return cout;
	}
	friend Complex07 Mysub07(Complex07&c1, Complex07&c2)
	{
		Complex07 temp(c1.a - c2.a, c1.b - c2.b);
		return temp;
	}
protected:
private:
	T a;
	T b;
};

//运算符重载的正规写法
//重载<<>>只能用友元函数 其他运算符重载 都要写成成员函数 不要滥用友元函数
//ostream&operator<<(ostream&out, Complex07&obj)
//{
//	cout << "a:" << obj.a << " b:" << obj.b << endl;
//	return cout;
//}



int main07()
{
	Complex07<int>c1(1, 2);
	cout << c1;
	c1.print_com();
	Complex07<int>c2(3, 4);

	Complex07<int>c3 = c1 + c2;
	cout << c3;

	Complex07<int>c4 = Mysub07(c2, c1);
	c4.print_com();

	system("pause");
	return EXIT_SUCCESS;
}
