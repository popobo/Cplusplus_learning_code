#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class GreaterThan20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void test11()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	//������������������ ��������
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThan20());
	if (pos != v.end())
	{
		cout << *pos << endl;
	}
}

//��Ԫν��
class MyCompare11
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 < v2;
	}
};

void test111()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	sort(v.begin(), v.end(), MyCompare11());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	//�������� lambda���ʽ [](){};
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}


int main11()
{
	test111();
	system("pause");
	return EXIT_SUCCESS;
}
