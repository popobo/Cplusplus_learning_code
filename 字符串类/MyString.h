#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(int len = 0);
	MyString(const char*in_p);
	~MyString();
	MyString(const MyString&mystring);
	MyString&operator=(const char*int_p);
	MyString&operator=(MyString&mystring);
	char&operator[](int index);
	bool operator==(const char*in_p) const;
	bool operator!=(const char*in_p) const;
	bool operator==(MyString&mystring) const;
	bool operator!=(MyString&mystring) const;
	bool operator>(const char*in_p) const;
	bool operator<(const char*in_p) const;
	bool operator<(MyString&mystring) const;
	bool operator>(MyString&mystring) const;
	//把类的指针露出来
	char*getP();
	int getLen();

	friend ostream&operator<<(ostream&out, MyString&mystring);
	friend istream&operator>>(istream&in, MyString&mystring);
	void PrintMyString();
private:
	char*m_p;
	int m_length;

};

