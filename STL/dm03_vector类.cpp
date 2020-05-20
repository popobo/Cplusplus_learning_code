#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;

void test030()
{
	vector<int>v1;
	cout << v1.size() << endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout << v1.size() << endl;
	cout << v1.front() << endl;
	
	//修改头部元素的值 函数返回值当左值 应该返回一个引用
	v1.front() = 44;
	v1.back() = 55;
	while (v1.size() > 0)
	{
		cout << v1.back() << endl;
		v1.pop_back();
	}
	//cout << v1.front() << endl;
}

//vector的初始化
void test031()
{
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);
	vector<int>v2 = v1;
	vector<int>v3(v1.begin(), v1.end());
	cout << v3.size() << endl;
	
	
}

//vector的遍历
void print_vector(vector<int>&v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void test032()
{
	vector<int>v1(10);//提前把内存准备好
	for (int i = 0; i < 10; ++i)
	{
		v1[i] = i * 66;
	}
	print_vector(v1);
}

void test033()
{
	vector<int>v1(10);
	v1.push_back(111);
	print_vector(v1);
}

//迭代器
//1  3  5 
//▲
//     ▲
//当it = v1.end()的时候 说明这个容器已经遍历完毕了
void test034()
{
	vector<int>v1(10);//提前把内存准备好
	for (int i = 0; i < 10; ++i)
	{
		v1[i] = i * 66;
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << *it << " ";
	}
	//逆序遍历
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;
}

//删除
void test035()
{
	vector<int>v1(10);//提前把内存准备好
	for (int i = 0; i < 10; ++i)
	{
		v1[i] = i * 66;
	}
	//区间删除
	v1.erase(v1.begin(), v1.begin() + 3);
	//指定位置删除
	v1.erase(v1.begin());
	//根据元素的值删除
	v1[1] = 666;
	v1[0] = 666;
	for (vector<int>::iterator it = v1.begin(); it != v1.end();)
	{
		if (*it == 666)
		{
			it = v1.erase(it);//当删除迭代器所指向的元素时 erase会让it自动+1 然后返回+1后的it
		}
		else
		{
			it++;
		}
	} 
	print_vector(v1);
	v1.insert(v1.begin() + 1, 100);
	v1.insert(v1.end() - 1, 200);
	print_vector(v1);
}

void test036()
{
	vector<int>v;
	v.reserve(100000); //预留出空间
	int*p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
	//开辟100000数据 开辟了多少次
}

void test037()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	cout << v.front() << endl;
	cout << v.back() << endl;
	v.insert(v.begin(), 100);
}

int main03()
{
	test037();
	system("pause");
	return EXIT_SUCCESS;
}
