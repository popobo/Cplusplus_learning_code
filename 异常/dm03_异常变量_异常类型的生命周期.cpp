#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

int my_strcpy03(char*to, char*from)
{

	if (from == NULL)
	{
		return 1;
	}
	if (to == NULL)
	{
		return 2;
	}
	//copy的场景检查
	if (*from == 'a')
	{
		return 3;
	}
	while (*from != NULL)
	{
		*(to++) = *(from++);
	}
	*to = '\0';
	return 0;
}

void my_strcpy031(char*to, char*from)
{

	if (from == NULL)
	{
		throw "源buf错误";
	}
	if (to == NULL)
	{
		throw "目标buf错误";
	}
	//copy的场景检查
	if (*from == 'a')
	{
		throw "拷贝过程错误";
	}
	while (*from != NULL)
	{
		*(to++) = *(from++);
	}
	*to = '\0';
}

class BadSrcType03 {};
class BadDestType03 {};
class BadProcessType03 
{
public:
	BadProcessType03()
	{
		cout << "BadProcessType03构造函数" << endl;
	}
	~BadProcessType03()
	{
		cout << "BadProcessType03析构函数" << endl;
	}
	BadProcessType03(const BadProcessType03&obj)
	{
		cout << "BadProcessType03拷贝构造函数" << endl;
	}
};
void my_strcpy032(char*to, char*from)
{

	if (from == NULL)
	{
		throw BadSrcType03(); // 
	}
	if (to == NULL)
	{
		throw BadDestType03();
	}
	//copy的场景检查
	if (*from == 'a')
	{
		throw BadProcessType03();
	}
	if (*from == 'b')
	{
		//throw&(BadProcessType03());
		throw new BadProcessType03;
	}
	while (*from != NULL)
	{
		*(to++) = *(from++);
	}
	*to = '\0';
}
//throw类对象类型异常
int main03()
{
	int ret = 0;
	char buf1[] = "hello world!";
	char buf2[1024];
	ret = my_strcpy03(buf2, buf1);
	if (ret != 0)
	{
		switch (ret)
		{
		case  1:
			cout << "源buf出错" << endl;
			break;
		case  2:
			cout << "目的buf出错" << endl;
			break;
		case 3:
			cout << "拷贝过程出错" << endl;
			break;
		default:
			cout << "未知错误" << endl;
			break;
		}
	}
	char buf3[] = "hello universe!";
	char buf4[1024];
	try
	{
		my_strcpy031(buf4, buf3);
	}
	catch (const char*e)
	{
		cout << e << endl;
	}
	catch (int)
	{
		cout << "int 类型错误" << endl;
	}
	catch (...)
	{
		cout << "未知错误" << endl;
	}

	char buf5[] = "bello universe!";
	char buf6[1024];
	try
	{
		my_strcpy032(buf6, buf5);
	}
	catch (const char*e)
	{
		cout << e << endl;
	}
	catch (int)
	{
		cout << "int 类型错误" << endl;
	}
	catch (BadSrcType03 e)
	{
		cout << "BadSrcType03异常" << endl;
	}
	catch (BadDestType03 e)
	{
		cout << "BadDestType03异常" << endl;
	}
	//结论1:如果接受异常时 使用一个异常变量 则copy构造异常变量
	//catch (BadProcessType03 e)
	//{
	//	cout << "BadProcessType03异常" << endl;
	//}
	//结论2：使用引用的话 会使用throw出来的对象
	//所以使用引用比较合适
	catch (BadProcessType03&e)
	{
		cout << "BadProcessType03异常" << endl;
	}
	//结论3:指针可以和引用/元素写在一块 引用和元素不能写在一块
	catch (BadProcessType03*p)
	{
		delete p;
		p = NULL;
		cout << "BadProcessType03指针异常" << endl;
	}
	catch (...)
	{
		cout << "未知错误" << endl;
	}
	//cout << buf5 << endl;
	system("pause");
	return EXIT_SUCCESS;
}
