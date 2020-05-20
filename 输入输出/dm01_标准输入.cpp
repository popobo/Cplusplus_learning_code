#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include "string"
using namespace std;

//标准输入流对象cin，重点掌握的函数
//cin.get() //一次只能读取一个字符
//cin.get(一个参数) //读一个字符
//cin.get(三个参数) //可以读字符串
//cin.getline()
//cin.ignore()
//cin.peek()
//cin.putback()


int main01()
{
	char myBuf[1024];
	int myInt;
	long myLong;
	//cin >> myInt;
	//cin >> myLong;
	//cin >> myBuf; //遇见空格停止接收数据
	//cout << "myInt:" << myInt << " myLong:" << myLong << " myBuf:" << myBuf << endl;
	//char ch;
	//while ((ch = cin.get()) != EOF)
	//{
	//	cout << ch << endl;
	//}
	//cout << "cin.get(a)如果缓冲区没有数据 则程序阻塞\n" << endl;
	//char a, b, c;
	//cin.get(a);
	//cin.get(b);
	//cin.get(c);
	//cout << a << b << c << "因为缓冲区有数据所以不阻塞" << endl;
	//cin.get(a).get(b).get(c);
	//cout << a << b << c << endl;
	//char buf1[256];
	//char buf2[256];
	//cin >> buf1;
	//cin.ignore(20);
	//int myint = cin.peek();
	//cout << "myint" << myint << endl;
	//cin.getline(buf2, 256);
	// 
	//cout << "buf1:" << buf1 << endl << "buf2:" << buf2 << endl;
	cout << "Please, enter a number or a word: ";
	char c = std::cin.get();

	if ((c >= '0') && (c <= '9')) //输入的整数和字符串 分开处理
	{
		int n; //整数不可能 中间有空格 使用cin >>n
		cin.putback(c);
		cin >> n;
		cout << "You entered a number: " << n << '\n';
	}
	else
	{
		string str;
		cin.putback(c);
		getline(cin, str); // //字符串 中间可能有空格 使用 cin.getline();
		cout << "You entered a word: " << str << '\n';
	}

	system("pause");
	return EXIT_SUCCESS;
}
