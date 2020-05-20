#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class  Complex03
{
public:
	friend ostream&operator<<(ostream&out, Complex03&c);
	Complex03(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void PrintCom()
	{
		cout << this->a << endl;
		cout << this->b << endl;
	}
	//��Ա����ʵ��+���������
	Complex03 operator+(Complex03&obj)
	{
		Complex03 temp(this->a + obj.a, this->b + obj.b);
		return temp;
	}
	Complex03 operator-(Complex03&obj)
	{
		Complex03 temp(this->a - obj.a, this->b - obj.b);
		return temp;
	}
	Complex03 operator++()
	{
		this->a++;
		this->b++;
		return*this;
	}
	Complex03 operator++(int)
	{
		Complex03 temp = *this;
		++this->a;
		++this->b;
		return temp;
	}
	Complex03&operator--()
	{
		--this->a;
		--this->b;
		return*this;
	}
	//����--
	Complex03 operator--(int)
	{
		Complex03 temp = *this;
		this->a--;
		this->b--;
		return temp;
	}
	
private:
	int a;
	int b;
};

//Complex03 myAdd(Complex03&c1, Complex03&c2)
//{
//	Complex03 temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}

////ȫ�ֺ��� ʵ�����������
//Complex03 operator+(Complex03&c1, Complex03&c2)
//{
//	Complex03 temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}
//
//Complex03 operator-(Complex03&c1, Complex03&c2)
//{
//	Complex03 temp(c1.a - c2.a, c1.b - c2.b);
//	return temp;
//}
//Complex03&operator++(Complex03&c1)
//{
//	c1.a++;
//	c1.b++;
//	return c1;
//}
////����++ int��ռλ��
//Complex03 operator++(Complex03&c, int)
//{
//	Complex03 temp = c;
//	c.a++;
//	c.b++;
//	return temp;
//}


ostream&operator<<(ostream&out, Complex03&c)
{
	out << c.a << "+" << c.b << endl;
	return out;
}
//���ó�Ա������дcout<< ��Ӧ��iostreamд

int main03()
{
	int a = 0, b = 0;
	int c;
	c = a + b;//������������ �������Ѿ�֪���� �������

	Complex03 c1(1, 2), c2(3, 4);//��Ҳ���������� �û��Զ����������� C++������ �ǲ�֪����ν��������
	Complex03 c3;


	Complex03 c5 = c1 - c2;
	c5.PrintCom();
	++c5;
	c5.PrintCom();
	--c5;
	c5.PrintCom();
	c5++.PrintCom();
	c5.PrintCom();
	c5--.PrintCom();
	c5.PrintCom();
	//��ʽ��� ��������ֵ����ֵ��Ҫ����
	cout << c5 << endl;
	//Complex03 c5 = operator+(c1, c4);
	//c5.PrintCom();

	//Complex03 c6 = c1 + c5;
	//c6.PrintCom();
	//C++���������Ա�ṩһ�ֻ���
	//���Զ�����������Ҳ���Խ��в��������� ->��������ػ���
	system("pause");
	return EXIT_SUCCESS;
}
