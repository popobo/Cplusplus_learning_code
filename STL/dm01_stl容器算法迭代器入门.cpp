#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include "vector"
#include "algorithm"
using namespace std;

class Teacher01
{
public:
	int age;
	char name[64];
	void print_teacher()
	{
		cout << "age:" << age << endl;
	}
protected:
private:
};

int main01()
{
	vector<int>v1; //容器：把你的元素copy到容器中 //容器实现了数据类型和数据类型的
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(-1);
	v1.push_back(3);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << *it << endl;
	}
	//算法 算法与迭代器无缝连接
	int num1 = count(v1.begin(), v1.end(), 3);
	cout << "num1:" << num1 << endl;

	Teacher01 t1, t2, t3;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	vector<Teacher01>v2;
	v2.push_back(t1);
	v2.push_back(t2);
	v2.push_back(t3);
	for (vector<Teacher01>::iterator it = v2.begin(); it != v2.end(); ++it)
	{
		cout << it->age << endl;
	}

	Teacher01*p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	vector<Teacher01*>v3;
	v3.push_back(p1);
	v3.push_back(p2);
	v3.push_back(p3);
	for (vector<Teacher01*>::iterator it = v3.begin(); it != v3.end(); ++it)
	{
		cout << (*it)->age << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}
