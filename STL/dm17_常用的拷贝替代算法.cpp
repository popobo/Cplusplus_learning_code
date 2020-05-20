#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

void test17()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	vector<int>vTarget;
	vTarget.resize(v.size());
	copy(v.begin(), v.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
	copy(vTarget.begin(), vTarget.end(), ostream_iterator<int>(cout, " "));
}

class myCompare17
{
public:
	bool operator()(int val)
	{
		return val > 3;
	}
};
void test171()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	replace(v.begin(), v.end(), 3, 400);
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	replace_if(v.begin(), v.end(), myCompare17(), 300);
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });

}

void test172()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i * 3);
	}
	swap(v, v2);
	cout << "v:";
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << "v2:";
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });

}



int main17()
{
	test172();
	system("pause");
	return EXIT_SUCCESS;
}
