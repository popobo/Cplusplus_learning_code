#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Test15
{
public:
	int a;
	int b;
public:
	Test15(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	//成员函数 少了一个参数
	Test15 Test15Add(Test15&t2)
	{
		Test15 temp(this->a + t2.a, this->b + t2.b);
		return temp;
	}
	//返回一个引用 相当于返回自身
	//返回t1这个元素 &t1=this  
	Test15&Test15Add1(Test15&t2)
	{
		this->a = this->a + t2.a;
		this->b = this->b + t2.b;
		return*this;
	}
	~Test15()
	{
		cout << "~Test15" << endl;
	}
	void PrintTest15()
	{
		cout << "a:" << this->a << endl << "b:" << b << endl;
	}
private:
	
};

//全局函数的方法
Test15 Test15Add(Test15&t1, Test15&t2)
{
	Test15 temp(t1.a + t2.a, t1.b + t2.b);
	return temp;
}

int main15()
{
	Test15 t1(1, 2);
	Test15 t2(3, 4);
	Test15 t3;
	t3 = Test15Add(t1, t2);
	t3.PrintTest15();
	Test15 t4 = t1.Test15Add(t2); // 匿名对象直接转换成t4
	t4.PrintTest15();
	Test15 t5;
	t5 = t1.Test15Add(t2); // 匿名对象赋值给t5
	t5.PrintTest15();



	t1.Test15Add1(t3).PrintTest15();
	
	system("pause");
	return EXIT_SUCCESS;
}
