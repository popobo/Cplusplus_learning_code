#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Name
{
public:
	Name(const char*p)
	{
		len = strlen(p);
		m_p = (char*)malloc(len + 1);
		strcpy(m_p, p);
	}
	Name(const Name&obj)
	{
		m_p = (char*)malloc(obj.len + 1);
		len = obj.len;
		strcpy(m_p, obj.m_p);
	}
	~Name()
	{
		if (m_p != NULL)
		{
			free(m_p);
			m_p = NULL;
			len = 0;
		}
	}
	void PrintName()
	{
		cout << m_p << endl;
	}
protected:
private:
	char*m_p;
	int len;
};

void objplay07()
{
	Name obj1("aaaaa"); 
	Name obj2 = obj1;
	obj1.PrintName();
	obj2.PrintName();
}

int main7()
{
	objplay07();
	system("pause");
	return EXIT_SUCCESS;
}
