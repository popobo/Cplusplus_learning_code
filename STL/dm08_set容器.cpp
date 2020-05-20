#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<set>
#include<string>
using namespace std;

void print_set(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test080()
{
	//����ʽ���� ��key���� ��С����
	set<int>s1;
	s1.insert(2);
	s1.insert(4);
	s1.insert(22);
	s1.insert(25);
	s1.insert(21);
	print_set(s1);
	s1.erase(s1.begin());
	s1.erase(4);
	print_set(s1);
}

void test081()
{
	set<int>s1;
	s1.insert(1);
	s1.insert(5);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	//����set û��value ��key����value
	set<int>::iterator pos = s1.find(22);
	if (pos != s1.end())
	{
		cout << "�ҵ�" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
	//count(key)����key��Ԫ�ظ��� ��set���� ���0��1
	cout << s1.count(20) << endl;
	pos = s1.lower_bound(20);
	if (pos != s1.end())
	{
		cout << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
	cout << "equal_range()" << endl;
	//������
	pair<set<int>::iterator, set<int>::iterator> it1 = s1.equal_range(3);
	if (it1.first != s1.end())
	{
		cout << *(it1.first) << endl;
	}
	if (it1.second != s1.end())
	{
		cout << *(it1.second) << endl;
	}
	print_set(s1);
}

//��������
void test082()
{
	//��һ��
	pair<string, int>p(string("Tom"), 100);

	//ȡֵ
	cout << "name:" << p.first << endl;
	cout << "age:" << p.second << endl;
	//�ڶ���
	pair<string, int>p2 = make_pair("je", 200);
	cout << "name:" << p2.first << endl;
	cout << "age:" << p2.second << endl;
}

//set���� ����������ظ��ļ�ֵ
void test083()
{
	set<int>s;
	s.insert(10);
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}
	print_set(s);
}

class myCompare08
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 < v2;
	}
};

//set�������� <>�з��������� Ҫָ�������÷º���
void test084()
{
	set<int,myCompare08>s1;
	s1.insert(1);
	s1.insert(5);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	//�Ӵ�С
	//�ڲ���֮ǰ��ָ���������
	for (set<int, myCompare08>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << endl;
	}
}
class Person08
{
public:
	Person08(string name, int age, int height)
	{
		//cout << "���캯��" << endl;
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	Person08(const Person08&per)
	{
		//cout << "�������캯��" << endl;
		m_name = per.m_name;
		m_age = per.m_age;
		m_height = per.m_height;
	}
	//���� == ��remove����ɾ���Զ������������
	bool operator==(const Person08&per)
	{
		if (m_name == per.m_name && m_age == per.m_age && m_height == per.m_height)
		{
			return true;
		}
		return false;
	}
	string m_name;
	int m_age;
	int m_height;
};

class personCompare08
{
public:
	bool operator()(const Person08&p1, const Person08&p2)
	{
		return p1.m_age > p2.m_age;
	}
};


void test085() 
{
	set<Person08, personCompare08>s;
	Person08 p1("aa", 10, 190);
	Person08 p2("bb", 20, 170);
	Person08 p3("cc", 30, 180);
	Person08 p4("dd", 10, 160);
	Person08 p5("ee", 20, 175);
	Person08 p6("ff", 30, 130);
	//�����Զ����������� ����ָ���������	
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	s.insert(p6);
	for (set<Person08, personCompare08>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << "name:" << it->m_name << " age:" << it->m_age << " height:" << it->m_height << endl;
	}
	
}

int main08()
{
	test085();
	system("pause");
	return EXIT_SUCCESS;
}
