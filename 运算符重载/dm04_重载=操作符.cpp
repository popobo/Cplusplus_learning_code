#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Name04
{
public:
	Name04(const char*myp)
	{
		m_len = strlen(myp);
		m_p = (char*)malloc(m_len + 1);
		strcpy(m_p, myp); 
	}
	Name04(const Name04&obj)
	{
		m_len = obj.m_len;
		m_p = (char*)malloc(m_len + 1);
		strcpy(m_p, obj.m_p);
	}
	~Name04()
	{
		if (m_p != NULL)
		{
			free(m_p);
			m_p = NULL;
			m_len = 0;
		}
	}
	Name04&operator=(Name04&obj)
	{
		//要先把旧的内存空间释放掉
		if (m_p != NULL)
		{
			free(m_p);
			m_p = NULL;
		}
		m_len = obj.m_len;
		m_p = new char[m_len + 1];
		strcpy(m_p, obj.m_p);
		//返回本身 实现连等
		return*this;
	}
	void PrintName04()
	{
		cout << m_p << endl;
	}
protected:
private:
	char*m_p;
	int m_len;
};

void objplay04()
{
	Name04 obj1("hello world");
	Name04 obj2("obj2");
	Name04 obj3("obj3");
	obj2 = obj3 = obj1;
	obj2.PrintName04();
	obj3.PrintName04();
}

int main04()
{
	objplay04();
	system("pause");
	return EXIT_SUCCESS;
}
