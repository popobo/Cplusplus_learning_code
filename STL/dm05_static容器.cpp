#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<stack>
using namespace std;

void test05()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	while (s.size() != 0)
	{
		cout << "top:" << s.top() << endl;
		s.pop();
	}
	cout << "size:" << s.size() << endl;
}

int main05()
{
	test05();
	system("pause");
	return EXIT_SUCCESS;
}