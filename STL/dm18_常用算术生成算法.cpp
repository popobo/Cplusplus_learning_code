#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void test181()
{
	vector<int>v;
	for (int i = 0; i <= 100; ++i)
	{
		v.push_back(i);
	}
	//第三个参数 起始累加值
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << sum << endl;
}

void test182()
{
	vector<int>v;
	v.resize(10, 200);
	fill(v.begin(), v.end(), 1000);
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}


int main18()
{
	test182();
	system("pause");
	return EXIT_SUCCESS;
}
