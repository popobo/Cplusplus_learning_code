#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include "string"
#include "algorithm"
using namespace std;

//�ַ����ĳ�ʼ��
void test02()
{
	string s1 = "aaaaa";
	string s2("bbbbb");
	string s3 = s2;//ͨ���������캯��
	string s4(10, 'c');
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
}

void test021()
{
	string s1 = "hello world";
	for (int i = 0; i < s1.length(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	for (string::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	try
	{
		for (int i = 0; i < s1.length()+1; ++i)
		{
			cout << s1.at(i) << " "; //out of range ���׳��쳣
		}
	}
	catch (...)
	{
		cout << "�����쳣" << endl;
	}
	
	cout << "\n---------------------" << endl;
	try
	{
		for (int i = 0; i < s1.length(); ++i)//���ִ��� �������׳��쳣 ��������ж�
		{
			cout << s1[i] << " ";
		}
	}
	catch (...)
	{
		cout << "�����쳣" << endl;
	}
}

//�ַ�ָ���string��ת��
void test022()
{
	string s1 = "hello";
	//s1==>char*
	cout << s1.c_str() << endl;
	//s1��copy��buf��
	char buf[128] = { '\0' };
	s1.copy(buf, 3, 0);
	cout << buf << endl;
}


//string�ַ�������
void test023()
{
	string s1 = "hello";
	string s2 = "world";
	s1 = s1 + s2;
	cout << s1 << endl;

	string s3 = "13";
	string s4 = "34";
	s3.append(s4);
	cout << s3 << endl;
}

//�ַ����Ĳ��Һ��滻
void test024()
{
	string s1 = "aaa abc ddd eeef oo ppp 9890";
	int index = s1.find("abc", 0);
	cout << index << endl;
	int offindex = s1.find("a", 0);
	
	while (offindex != string::npos)
	{
		cout << "offindex:" << offindex << endl;
		++offindex;
		offindex = s1.find("a", offindex);
	}

	offindex = s1.find("a", 0);
	while (offindex != string::npos)
	{
		cout << "offindex:" << offindex << endl;
		s1.replace(offindex, 1, "A");
		++offindex;
		offindex = s1.find("a", offindex);
	}
	cout << s1 << endl;


}


//�ضϣ�����ɾ�����Ͳ���
void test025()
{
	string s1 = "hello1 hello2 hello1";
	string::iterator it = find(s1.begin(), s1.end(), '1');
	if (it != s1.end())
	{
		s1.erase(it);
	}
	cout << "s1ɾ��1�Ժ�Ľ��:" << s1 << endl;
	
	s1.erase(s1.begin(), s1.end());
	cout << s1 << endl;
	cout << s1.length() << endl;

	string s2 = "bbb";
	s2.insert(0, "aaa");//ͷ�巨
	s2.insert(s2.length(), "ccc");
	cout << s2 << endl;
}

void test026()
{
	string s1 = "Hello world!";
	//��������ڵ�ַ 2�������� 3Ԥ����ĺ�����toupper
	transform(s1.begin(), s1.end(), s1.begin(), toupper);
	cout << s1 << endl;

	string s2 = "hELLO WORLD!";
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	cout << s2 << endl;

}

int mai02()
{
	test026();
	system("pause");
	return EXIT_SUCCESS;
}
