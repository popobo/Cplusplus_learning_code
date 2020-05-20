#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;

void print_d(const deque<int>&d)
{
	//iterator 普通迭代器 const_iterator 只读迭代器
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
	{
		//*it = 100000;
		cout << *it << " ";
	}
	cout << endl;
}
void test041()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	print_d(d);
	deque<int>d2(d.begin(), d.end());
	d2.push_front(1000);
	d.swap(d2);
	print_d(d);

}

void test042()
{
	vector<deque<int>>v;
	deque<int>d1;
	deque<int>d2;
	deque<int>d3;
	deque<int>d4;
	deque<int>d5;
	d1.push_back(11);
	v.push_back(d1);
	v.push_back(d2);
	v.push_back(d3);
	v.push_back(d4);
	v.push_back(d5);
	srand((unsigned int)time(0));
	for (vector<deque<int>>::iterator vit = v.begin(); vit != v.end(); ++vit)
	{
		int sum = 0;
		static int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			vit->push_back(rand() % 101);
		}
		sort(vit->begin(), vit->end());
		vit->pop_back();
		vit->pop_front();
		for (deque<int>::iterator dit = vit->begin(); dit != vit->end(); ++dit)
		{
			sum += *dit;
		}
		cout << count++ << "号运动员得分为:" << sum / vit->size() << endl;
		cout << &(*vit) << endl;
	}
	

}
int main04()
{
	test042();
	system("pause");
	return EXIT_SUCCESS;
}
