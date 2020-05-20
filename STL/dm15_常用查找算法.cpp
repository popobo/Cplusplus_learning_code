#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;

void test15()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << *pos << endl;
	}
}


//利用find查找自定义数据类型
class Person15
{
public:
	Person15(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(const Person15&p)
	{
		if (m_name == p.m_name&&m_age == p.m_age)
		{
			return true;
		}
		return false;
	}
	friend ostream&operator<<(ostream&out, Person15&per);
protected:
private:
	string m_name;
	int m_age;
};

ostream&operator<<(ostream&out, Person15&per)
{
	cout << "name:" << per.m_name << " age:" << per.m_age << endl;
	return out;
}

void test151()
{
	vector<Person15>v;
	Person15 p1("aa", 13);
	Person15 p2("dd", 13);
	Person15 p3("cc", 13);
	Person15 p4("bb", 13);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person15>::iterator pos = find(v.begin(), v.end(), p2);
	if (pos != v.end())
	{
		cout << *pos << endl;
	}
}
class MyCompare15 :public binary_function<Person15*, Person15*, bool>
{
public:
	bool operator()(Person15*per, Person15*p) const
	{
		if (*per == *p)
		{
			return true;
		}
		return false;
	}
};

void test152()
{
	vector<Person15*>v;
	Person15 p1("aa", 13);
	Person15 p2("dd", 13);
	Person15 p3("cc", 13);
	Person15 p4("bb", 13);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	Person15*p = new Person15("bb", 103);
	vector<Person15*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare15(), p));
	if (pos != v.end())
	{
		cout << *(*pos);
	}
}

void test153()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		if (i == 5)
		{
			v.push_back(i);
		}
	}
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos != v.end())
	{
		cout << *pos << endl;
	}
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

void test154()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 4);
	if (ret == true)
	{
		cout << "找到了" << endl;
	}
}

class GreaterThanNum :public binary_function<int, int, bool>
{
public:
	bool operator()(int val1, int val2) const
	{
		return val1 > val2;
	}
};

void test155()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		if (i == 5)
		{
			v.push_back(i);
			v.push_back(i);
		}
		
	}
	int num = count(v.begin(), v.end(), 5);
	cout << "5的个数" << num << endl;
	int num2 = count_if(v.begin(), v.end(), bind2nd(GreaterThanNum(), num));
	cout << "大于" << num << "个数" << num2 << endl;
}
int main15()
{
	test155();
	system("pause");
	return EXIT_SUCCESS;
}
