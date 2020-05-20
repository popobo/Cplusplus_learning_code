#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class MyPrint10
{
public:
	void operator()(int num)
	{
		cout << "num:" << num << endl;
		count++;
	}
	int count = 0;
};

//函数对象作为参数传递
void doprint10(MyPrint10 print,int num)
{
	print(num);
}

void test101()
{
	MyPrint10 myprint;
	doprint10(myprint, 2002);
}

int main10()
{
	MyPrint10 myprint;
	myprint(11);
	MyPrint10()(1000);
	//函数对象超出函数的概念 里面可以保留数据
	myprint(200);
	cout << myprint.count << endl;
	
	test101();

	system("pause");
	return EXIT_SUCCESS;
}
