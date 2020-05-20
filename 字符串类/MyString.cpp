#include "MyString.h"

ostream&operator<<(ostream&out, MyString&mystring)
{
	out << mystring.m_p;
	return out;
}

istream&operator>>(istream&in, MyString&mystring)
{
	in >> mystring.m_p;
	return in;
}

//默认参数在定义时无须再写一遍
MyString::MyString(int len)
{
	if (len == 0)
	{
		m_length = 0;
		m_p = new char[m_length + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_length = len;
		m_p = new char[m_length + 1];
		memset(m_p, '\0', m_length + 1);
	}
	
}


MyString::MyString(const char*in_p)
{
	if (in_p == NULL)
	{
		m_length = 0;
		m_p = new char[m_length + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_length = strlen(in_p);
		m_p = new char[m_length + 1];
		strcpy(m_p, in_p);
	}
}

MyString::MyString(const MyString&mystring)
{
	cout << "拷贝构造函数" << endl;
	m_length = mystring.m_length;
	m_p = new char[m_length + 1];
	strcpy(m_p, mystring.m_p);
}

MyString::~MyString()
{
	if (m_p != NULL)
	{
		free(m_p);
		m_p = NULL;
	}
}

void MyString::PrintMyString()
{
	cout << m_p << endl;
}

MyString&MyString::operator=(const char*in_p)
{
	if (m_p != NULL)
	{
		free(m_p);
		m_p = NULL;
	}
	if (in_p == NULL)
	{
		m_length = 0;
		m_p = new char[m_length + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_length = strlen(in_p);
		m_p = new char[m_length + 1];
		strcpy(m_p, in_p);
	}
	return*this;
}
MyString&MyString::operator=(MyString&mystring)
{
	if (m_p != NULL)
	{
		free(m_p);
		m_p = NULL;
	}
	if (mystring.m_p == NULL)
	{
		m_length = 0;
		m_p = new char[m_length + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_length = mystring.m_length;
		m_p = new char[m_length + 1];
		strcpy(m_p, mystring.m_p);
	}
	return*this;
}



char&MyString::operator[](int index)
{
	return m_p[index];
}


bool MyString::operator==(const char*in_p) const
{
	if (in_p == NULL)
	{
		if (m_length == 0)
		{
			return true;
		}
	}
	else
	{
		if (m_length == strlen(in_p))
		{
			return !strcmp(m_p, in_p);
		}
		else
		{
			return false;
		}
	}
}

bool MyString::operator!=(const char*in_p) const
{
	return !(*this == in_p);
}

bool MyString::operator==(MyString&mystring) const
{
	return *this == mystring.m_p;
}

bool MyString::operator!=(MyString&mystring) const
{
	return !(*this == mystring.m_p);
}

bool MyString::operator<(const char*in_p) const
{
	if (strcmp(m_p, in_p) >= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool MyString::operator>(const char*in_p) const
{
	return !(*this < in_p);
}

bool MyString::operator<(MyString&mystring) const
{
	return *this < mystring.m_p;
}

bool MyString::operator>(MyString&mystring) const
{
	return !(*this < mystring);
}

char*MyString::getP()
{
	return m_p;
}

int MyString::getLen()
{
	return m_length;
}