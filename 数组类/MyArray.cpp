#include "MyArray.h"

MyArray::MyArray(int length)
{
	if (length<0)
	{
		m_length = 0;
		m_array = new int[m_length];
	}
	else
	{
		m_length = length;
		m_array = new int[m_length];
	}
}

//const对象只能调用const成员函数 而不能调用非const成员函数
//因为const MyArray*this 无法转变成 MyArray*this 指针
MyArray::MyArray(const MyArray&obj)
{
	this->m_length = obj.m_length;
	this->m_array = new int[this->m_length];
	for (int i = 0; i < this->m_length; ++i)
	{
		this->m_array[i] = obj.m_array[i];
	}
}

MyArray::~MyArray()
{
	delete[]m_array;
	m_array = NULL;
}

void MyArray::setData(int index, int value)
{
	m_array[index] = value;
}

int MyArray::getData(int index)
{
	return m_array[index];
}

int MyArray::length()
{
	return m_length;
}

int&MyArray::operator[](int i)
{
	//写上int& 下面这句话就代表返回m_array[i]本身
	return m_array[i];
}

MyArray&MyArray::operator=(MyArray&obj)
{
	if (m_array!=NULL)
	{
		delete[]m_array;
		m_array = NULL;
		m_length = 0;
	}
	m_length = obj.m_length;
	m_array = new int[m_length];
	for (int i = 0; i < m_length; ++i)
	{
		m_array[i] = obj[i];
	}
	return*this;
}

bool MyArray::operator==(MyArray&obj)
{
	if (m_length != obj.m_length)
	{
		return false;
	}
	for (int i = 0; i < m_length; ++i)
	{
		if ((*this)[i] != obj[i])
		{
			return false;
		}
	}
	return true;
}

bool MyArray::operator!=(MyArray&obj)
{
	if (m_length != obj.m_length)
	{
		return true;
	}
	for (int i = 0; i < m_length; ++i)
	{
		if ((*this)[i] != obj[i])
		{
			return true;
		}
	}
	return false;
}
