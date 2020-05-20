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
	//copy�ĳ������
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
		throw "Դbuf����";
	}
	if (to == NULL)
	{
		throw "Ŀ��buf����";
	}
	//copy�ĳ������
	if (*from == 'a')
	{
		throw "�������̴���";
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
		cout << "BadProcessType03���캯��" << endl;
	}
	~BadProcessType03()
	{
		cout << "BadProcessType03��������" << endl;
	}
	BadProcessType03(const BadProcessType03&obj)
	{
		cout << "BadProcessType03�������캯��" << endl;
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
	//copy�ĳ������
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
//throw����������쳣
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
			cout << "Դbuf����" << endl;
			break;
		case  2:
			cout << "Ŀ��buf����" << endl;
			break;
		case 3:
			cout << "�������̳���" << endl;
			break;
		default:
			cout << "δ֪����" << endl;
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
		cout << "int ���ʹ���" << endl;
	}
	catch (...)
	{
		cout << "δ֪����" << endl;
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
		cout << "int ���ʹ���" << endl;
	}
	catch (BadSrcType03 e)
	{
		cout << "BadSrcType03�쳣" << endl;
	}
	catch (BadDestType03 e)
	{
		cout << "BadDestType03�쳣" << endl;
	}
	//����1:��������쳣ʱ ʹ��һ���쳣���� ��copy�����쳣����
	//catch (BadProcessType03 e)
	//{
	//	cout << "BadProcessType03�쳣" << endl;
	//}
	//����2��ʹ�����õĻ� ��ʹ��throw�����Ķ���
	//����ʹ�����ñȽϺ���
	catch (BadProcessType03&e)
	{
		cout << "BadProcessType03�쳣" << endl;
	}
	//����3:ָ����Ժ�����/Ԫ��д��һ�� ���ú�Ԫ�ز���д��һ��
	catch (BadProcessType03*p)
	{
		delete p;
		p = NULL;
		cout << "BadProcessType03ָ���쳣" << endl;
	}
	catch (...)
	{
		cout << "δ֪����" << endl;
	}
	//cout << buf5 << endl;
	system("pause");
	return EXIT_SUCCESS;
}
