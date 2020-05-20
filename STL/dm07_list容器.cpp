#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<list>
#include<string>
using namespace std;

//list是双向链表
void test07()
{
	//list<int> myList;
	//for (int i = 0; i < 10; i++) {
	//	myList.push_back(i);
	//}

	//list<int>::_Nodeptr node = myList._Myhead->_Next;

	//for (int i = 0; i < myList._Mysize * 2; i++) {
	//	cout << "Node:" << node->_Myval << endl;
	//	node = node->_Next;
	//	if (node == myList._Myhead) {
	//		node = node->_Next;
	//	}
	//}

}
void print_list(list<int>&l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test071()
{
	//常用api
	list<int>l(10, 10);
	list<int>l2(l.begin(), l.end());
	print_list(l);
	l2.push_back(100);
	print_list(l2);
	for (list<int>::reverse_iterator it = l2.rbegin(); it != l2.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	l2.push_front(200);
	print_list(l2);
	//删除两端的数据
	l2.pop_back();
	l2.pop_front();
	print_list(l2);
	l2.insert(l2.begin(), 5, 1000);
	print_list(l2);
	l2.remove(10);
	print_list(l2);
}
bool my_compare(int a,int b)
{
	return a > b;
}

void test072()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(40);
	l.push_back(50);
	l.reverse();
	print_list(l);
	//所有不支持随机访问的迭代器 不可以使用系统提供的算法
	//则类内部会提供
	//sort(l.begin(), l.end());
	l.sort(my_compare);
	print_list(l);
}
//自定义数据类型


class Person07
{
public:
	Person07(string name, int age, int height)
	{
		//cout << "构造函数" << endl;
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	Person07(const Person07&per)
	{
		//cout << "拷贝构造函数" << endl;
		m_name = per.m_name;
		m_age = per.m_age;
		m_height = per.m_height;
	}
	//重载 == 让remove可以删除自定义的数据类型
	bool operator==(const Person07&per)
	{
		if (m_name == per.m_name && m_age == per.m_age && m_height == per.m_height)
		{
			return true;
		}
		return false;
	}
	string m_name;
	int m_age;
	int m_height;
};

bool my_compare_person(Person07&p1, Person07&p2)
{
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height < p2.m_height;
	}
	else
	{
		return p1.m_age > p2.m_age;
	}
}
void test073()
{
	list<Person07>l;
	Person07 p1("aa", 10, 190);
	Person07 p2("bb", 20, 170);
	Person07 p3("cc", 30, 180);
	Person07 p4("dd", 10, 160);
	Person07 p5("ee", 20, 175);
	Person07 p6("ff", 30, 130);
	Person07 p7(p6);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);
	//cout << p1.m_height << endl;
	
	//需求 打印数据的时候 按年龄的降序输出
	l.sort(my_compare_person);
	for (list<Person07>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << "name:" << it->m_name << " age:" << it->m_age << " height:" << it->m_height << endl;
	}
	l.remove(p6);
	cout << endl;
	for (list<Person07>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << "name:" << it->m_name << " age:" << it->m_age << " height:" << it->m_height << endl;
	}
}
int main07()
{
	test073();
	system("pause");
	return EXIT_SUCCESS;
}
