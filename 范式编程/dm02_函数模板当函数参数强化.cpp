#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//让你对字符数组 int数组进行排序

template<typename T>
void my_sort(T*p, int len)
{
	T temp;
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (p[i] < p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
				
		}
	}
}

int main02()
{
	int array[] = { 1,20,3,55,4,1,9 };
	int len = 0;
	len = sizeof(array) / sizeof(array[0]);
	my_sort(array, len);
	for (int i = 0; i < len; ++i)
	{
		cout << array[i] << endl;
	}
	cout << "排序后" << endl;
	for (int i = 0; i < len; ++i)
	{
		cout << array[i] << endl;
	}
	char c_array[] = { 'a','c','b','j','d' };
	int c_len = 0;
	c_len = sizeof(c_array) / sizeof(c_array[0]);
	my_sort(c_array, c_len);
	for (int i = 0; i < len; ++i)
	{
		cout << c_array[i] << endl;
	}
	cout << "排序后" << endl;
	for (int i = 0; i < len; ++i)
	{
		cout << c_array[i] << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}
