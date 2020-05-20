#include "MyString.h"
#include<list>

int main()
{
	MyString s1(NULL);
	MyString s2 = NULL;
	MyString s3 = "hello world!";
	MyString s100 = s1;
	list<MyString>l;
	l.push_back(s1);
	cout << s3 << endl;
	s3[0] = 'p';
	cout << s3 << endl;

	s2 = s3;
	if (s2 == "pello world!")
	{
		cout << "s2 == " << "pello world" << endl;
	}
	if (s2 == s3)
	{
		cout << "s2 == s3" << endl;
	}
	s2[0] = 'l';
	if (s2 == s3)
	{
		cout << "s2 == s3" << endl;
	}
	if (s2 == "pello world!")
	{
		cout << "s2 == " << "pello world" << endl;
	}
	if (s2 != s3)
	{
		cout << "s2 != s3" << endl;
	}
	if (s2 != "pello world!")
	{
		cout << "s2 != " << "pello world" << endl;
	}
	s2 = "b";
	if (s2 < "hello real world!")
	{
		cout << "s2 < \"hello real world!\"" << endl;
	}
	if (s2 > s3)
	{
		cout << "s2 < s3" << endl;
	}
	if (s2 > "a")
	{
		cout << "s2 < \"a\"" << endl;
	}

	MyString s4(100);
	cin >> s4;
	cout << s4 << endl;
	system("pause");
	return EXIT_SUCCESS;
}
