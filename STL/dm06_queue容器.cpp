#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<queue>
using namespace std;

void test06()
{
	queue<int>q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	while (!q.empty())
	{
		cout << "¶ÓÍ·£º" << q.front() << endl;
		cout << "¶ÓÎ²£º" << q.back() << endl;
		q.pop();
	}
	cout << "size:" << q.size() << endl;
}

int main06()
{
	test06();
	system("pause");
	return EXIT_SUCCESS;
}
