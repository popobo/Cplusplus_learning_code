#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include<string>
using namespace std;

class MyPrint13 :public binary_function<int, int, void>
{
public:
	void operator()(int v, int start) const
	{
		cout << "v:" << v << "start:" << start << endl;
		cout << v + start << endl;
	}
};

class MyPrint131
{
public:
	MyPrint131(int start)
	{
		this->start = start;
	}
	void operator()(int v, int start) const
	{
		cout << "v:" << v << "start:" << start << endl;
		cout << v + start << endl;
	}
private:
	int start;
};

class test131
{
public:
	test131(int num)
	{
		this->num = num;
	}
	void print()
	{
		cout << num << endl;
	}
protected:
private:
	int num;
};

void test13()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	int num;
	cin >> num;
	
	for_each(v.begin(), v.end(), bind2nd(MyPrint13(), num));
	for_each(v.begin(), v.end(), bind1st(MyPrint13(), num));
	//for_each(v.begin(), v.end(), MyPrint131(100));

}

//第一步 绑定数据 
//第二部 继承类 binary_function<参数类型1, 参数类型2, 返回值类型>
//第三步 加const修饰operator()

//取反适配器
class GreaterThan135 :public unary_function<int, bool>
{
public:
	bool operator()(int val) const
	{
		return val > 5;
	}
};

//取反适配器
void test132()
{
	//一元取反
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	//查找大于5的数据
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThan135());
	if (pos != v.end())
	{
		cout << *pos << endl;
	}
	//给位找小于5的数
	pos = find_if(v.begin(), v.end(),not1(GreaterThan135()));
	if (pos != v.end())
	{
		cout << *pos << endl;
	}
	pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
	if (pos != v.end())
	{
		cout << *pos << endl;
	}
}

//一元取反适配器 not1
//继承 unary_function<参数类型1，参数类型2>
//加const

//指针适配器
void MyPrint132(int v, int start)
{
	cout << v + start << " ";
}

void test133()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	//将函数指针适配为函数对象
	//ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint132), 100));

}

//成员函数适配器
class Person13
{
public:
	Person13(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void my_print_person()
	{
		cout << "name:" << name << " age:" << age << endl;
	}
	void plusage()
	{
		age++;
	}
	string name;
	int age;
};


void test134()
{
	vector<Person13>v;
	Person13 p1("aa", 13);
	Person13 p2("bb", 13);
	Person13 p3("cc", 13);
	Person13 p4("dd", 13);
	Person13 p5("ee", 14);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	//成员函数适配器
	//mem_fun_ref
	for_each(v.begin(), v.end(),mem_fun_ref(&Person13::plusage));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person13::my_print_person));

}

int main13()
{
	test134();
	//int num;
	//cin >> num;
	//test131 t1(num);
	//t1.print();
	system("pause");
	return EXIT_SUCCESS;
}
