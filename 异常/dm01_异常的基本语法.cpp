#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//1 发生异常之后 是跨函数的
//2 接受异常后 可以不处理 可以抛给上层
//3 catch异常时 按照类型进行catch
//4 异常捕捉严格按照类型匹配
void divide01(int x, int y)
{
	if (y == 0)
	{
		throw x; //抛出int类型异常
	}
	cout << "divide01结果:" << x / y << endl;
}

void divide011(int x, int y)
{
	try
	{
		divide01(x, y);
	}
	catch (...)
	{
		cout << "我接受了 divide的异常 但是我没有处理 我向下抛出" << endl;
		throw;
	}
	divide01(x, y);
}

int main01()
{
	try
	{
		//divide01(10, 2);
		divide011(100, 0);
	}
	catch (int e)
	{
		cout << e << "被零除" << endl;
	}
	catch (...)
	{
		cout << "其他未知类型异常" << endl;
	}

	try
	{
		throw 'e';
	}
	catch (int e)
	{
		cout << "捕捉int类型异常" << endl;
	}
	catch (char e)
	{
		cout << "捕捉char类型异常" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}
