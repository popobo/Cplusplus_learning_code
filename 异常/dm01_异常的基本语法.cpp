#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//1 �����쳣֮�� �ǿ纯����
//2 �����쳣�� ���Բ����� �����׸��ϲ�
//3 catch�쳣ʱ �������ͽ���catch
//4 �쳣��׽�ϸ�������ƥ��
void divide01(int x, int y)
{
	if (y == 0)
	{
		throw x; //�׳�int�����쳣
	}
	cout << "divide01���:" << x / y << endl;
}

void divide011(int x, int y)
{
	try
	{
		divide01(x, y);
	}
	catch (...)
	{
		cout << "�ҽ����� divide���쳣 ������û�д��� �������׳�" << endl;
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
		cout << e << "�����" << endl;
	}
	catch (...)
	{
		cout << "����δ֪�����쳣" << endl;
	}

	try
	{
		throw 'e';
	}
	catch (int e)
	{
		cout << "��׽int�����쳣" << endl;
	}
	catch (char e)
	{
		cout << "��׽char�����쳣" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}
