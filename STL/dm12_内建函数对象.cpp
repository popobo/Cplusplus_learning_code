#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<functional>
#include<vector>
#include <algorithm>
using namespace std;

void test120()
{
	negate<int>n;
	cout << n(10) << endl;

	plus<int>p;
	cout << p(1, 3) << endl;
}

void test121()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}


int main12()
{
	test121();
	system("pause");
	return EXIT_SUCCESS;
}
