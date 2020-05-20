#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<string>
using namespace std;

void test002()
{
	string str;//Ä¬ÈÏ¹¹Ôì
	string str1("abcd");
	string str2 = "tuyi";
	string str3(10, 'a');
	cout << str << endl;
	cout << str1 << endl;
	cout << str2 << endl;
}

int main002()
{
	test002();
	system("pause");
	return EXIT_SUCCESS;
}
