#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<map>
#include<string>
using namespace std;

void test091()
{
	map<int, int>m;
	//插入值
	//4种方式
	//第一种
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	m[5];
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	if (m.empty())
	{
		cout << "空" << endl;
	}
	else
	{
		cout << "size:" << m.size() << endl;
	}
}

void test092()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m.erase(1);	
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	map<int, int>::iterator pos = m.find(2);
	if (pos != m.end())
	{
		cout << "key:" << pos->first << " value" << pos->second << endl;
	} 
}

class Workers
{
public:
	Workers(string name, int age, string phone, int salary)
	{
		m_name = name;
		m_age = age;
		m_phone = phone;
		m_salary = salary;
	}
	friend ostream&operator<<(ostream&out, Workers&w);
	int get_age()
	{
		return m_age;
	}
private:
	string m_name;
	int m_age;
	string m_phone;
	int m_salary;
};

ostream&operator<<(ostream&out, Workers&w)
{
	out << "name:" << w.m_name << " age:" << w.m_age << " phone:" << w.m_phone << " salary:" << w.m_salary << endl;
	return out;
} 


void test093()
{
	multimap<string, Workers>m;
	Workers w1("a", 10, "123", 100);
	Workers w2("b", 20, "456", 200); 
	Workers w3("c", 30, "789", 300);
	Workers w4("d", 40, "101112", 400);
	Workers w5("e", 50, "131415", 500);
	Workers w6("e", 60, "161718", 600);

	m.insert(make_pair("部门1", w1));
	m.insert(make_pair("部门2", w2));
	m.insert(make_pair("部门3", w3));
	m.insert(make_pair("部门4", w4));
	m.insert(make_pair("部门5", w5));
	m.insert(make_pair("部门5", w6));
	pair < multimap<string, Workers>::iterator, multimap<string, Workers>::iterator>p = m.equal_range("部门5");
	for (multimap<string, Workers>::iterator it = p.first; it != p.second; ++it)
	{
		cout << it->second << endl;
	}	
}

int main09()
{
	test093();
	system("pause");
	return EXIT_SUCCESS;
}
