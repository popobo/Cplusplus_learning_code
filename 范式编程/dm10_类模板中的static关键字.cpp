#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;
template<typename T>
class A10
{
public:
	static T m_a;

};

template<typename T>
T A10<T>::m_a = 0;

int main()
{
	A10<int>a1, a2;
	a1.m_a = 10;
	a2.m_a = 11;
	cout << A10<int>::m_a << endl;

	//m_a 各自使用类族的m_a
	A10<char>b1, b2;
	b1.m_a++;
	cout << A10<char>::m_a << endl;
	system("pause");
	return EXIT_SUCCESS;
}
