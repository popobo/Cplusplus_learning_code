#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include <algorithm>
#include <vector>
#include<functional>
#include<ctime>
using namespace std;

void test16()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}

void test161()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(10 - i);
	}
	sort(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	sort(v1.begin(), v1.end(),greater<int>());
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });

}



void test162()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(10 - i);
	}
	random_shuffle(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
}

int main16()
{
	//提供随机种子
	srand((unsigned int)time(NULL));
	test162();
	system("pause");
	return EXIT_SUCCESS;
}
