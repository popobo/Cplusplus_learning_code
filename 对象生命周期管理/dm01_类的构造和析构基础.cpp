#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;


class Test
{
public:
	Test()
	{
		a = 10;
		//p = "aaaaaa"; C++类型检查严格 这样赋值不行
		p = (char*)malloc(100);
		strcpy(p, "aaaaaab");
		cout << "test" << endl;
	}
	void PrintTest()
	{
		cout << p << endl;
		cout << a << endl;
	}
	~Test()
	{
		if (p != NULL)
		{
			free(p);
		}
		p = NULL;
		cout << "~test" << endl;
	}
private:
	int a;
	char*p;
};

void objplay()
{
	Test t1;
	t1.PrintTest();
}

int main1()
{
	objplay();
	system("pause");
	return EXIT_SUCCESS;
}
