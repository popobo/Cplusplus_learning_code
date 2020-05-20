#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//迭代器 遍历功能 用指针理解 
//普通指针也算一种迭代器
void test01()
{
	int array[5] = { 1,2,4,3,7 };
	for (int i = 0; i < 5; ++i)
	{
		cout << array[i] << endl;
	}
	int*p = array;//指针指向数组首地址 &array[0]
	for (int i = 0; i < 5; ++i)
	{
		cout << *(p++) << endl;
	}
}

void print_v(int v)
{
	cout << v << " ";
}

void test012()
{
	vector<int>v;//声明一个容器 这个容器存放int类型数据 对象名称v
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	//第一种
	while (itBegin != itEnd)
	{
		cout << *itBegin << " ";
		itBegin++;
	}
	cout << endl;
	//第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//第三种方式 算法
	for_each(v.begin(), v.end(), print_v);
	cout << endl;
}

//操作自定义的数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void test013()
{
	vector<Person>v;
	Person p1("a", 30);
	Person p2("b", 40);
	Person p3("c", 50);
	v.push_back(p1);
	v.push_back(p2);
	for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "name:" << (*it).name << " age:" << it->age << " ";
	}
	cout << endl;
}

void test014()
{
	vector<Person*>v;
	Person p1("a", 30);
	Person p2("b", 40);
	Person p3("c", 50);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)->name << " " << (*it)->age << endl;
	}
	cout << endl;
}

//容器嵌套容器
void test015()
{
	vector<vector<int>>v;
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
		v2.push_back(i * 2);
	}
	v.push_back(v1);
	v.push_back(v2);
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

int main001()
{
	test015();
	system("pause");
	return EXIT_SUCCESS;
}
