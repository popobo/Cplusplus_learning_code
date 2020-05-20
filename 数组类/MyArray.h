#define _CRT_SECURE_NO_WARNINGS  
#pragma once
#include<iostream>
using namespace std;

class MyArray
{
public:
	MyArray(int length);
	MyArray(const MyArray&obj);
	~MyArray();
	int&operator[](int i);
	MyArray&operator=(MyArray&obj);
	bool operator==(MyArray&obj);
	bool operator!=(MyArray&obj);
public:
	void setData(int index, int value);
	int getData(int index);
	int length();
private:
	int m_length;
	int*m_array;
};

