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
		cout << "��ͷ��" << q.front() << endl;
		cout << "��β��" << q.back() << endl;
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
