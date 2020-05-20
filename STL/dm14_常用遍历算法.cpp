#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<algorithm>
#include <vector>
#include <functional>
using namespace std;

class Myprint14
{
public:
	void operator()(int val)
	{
		cout << val << " ";
		m_Count++;
	}
	int m_Count = 0 ;
};

struct Myprint141
{
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class Myprint142 :public binary_function<int, int, void>
{
public:
	void operator()(int val, int start) const
	{
		cout << val + start << " ";
	}
};

void test14()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}

	Myprint14 print2 = for_each(v.begin(), v.end(), Myprint14());
	//for_each可以保存内部记录 有返回值
	cout << print2.m_Count << endl;
}

//for_each可以绑定参数进行输出
void test141()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(Myprint142(), 1000));

}

//transform
class Transform141
{
public:
	int operator()(int val)
	{
		return val + 5;
	}
};
void test142()
{

	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	vector<int>vTarget;//目标容器
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(), Transform141());
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
	
}

//Transform 第二种用法 讲两个容器搬运到目标容器
class Transform142
{
public:
	int operator()(int val,int val2)
	{
		return val + val2;
	}
protected:
private:
};



void test143()
{
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i * 2);
		v1.push_back(i * 3);
	}
	vector<int>vTarget;
	vTarget.resize(v.size());
	transform(v1.begin(), v1.end(), v.begin(), vTarget.begin(), Transform142());
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}
int main14()
{
	test143();
	system("pause");
	return EXIT_SUCCESS;
}
//transform 第二种用法



