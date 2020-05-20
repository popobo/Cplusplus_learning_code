#include "MyVector.h"

template<typename T>
MyVector<T>::MyVector(int size) 
{
	m_len = size;
	m_space = new T[m_len];
	memset(m_space, 0, m_len);
}
template<typename T>
MyVector<T>::MyVector(const MyVector<T>&obj)
{
	m_len = obj.m_len;
	m_space = new T[m_len];
	for (int i = 0; i < m_len; ++i)
	{
		m_space[i] = obj.m_space[i];
	}
}
template<typename T>
MyVector<T>::~MyVector()
{
	if (m_space != NULL)
	{
		delete[]m_space;
		m_len = 0;
		m_space = NULL;
	}
}

template<typename T>
T&MyVector<T>::operator[](int index)
{
	return m_space[index];
}

template<typename T>
MyVector<T>&MyVector<T>::operator=(const MyVector<T>&obj)
{
	if (m_space != NULL)
	{
		delete[]m_space;
	}
	m_len = obj.m_len;
	m_space = new T[m_len];
	for (int i = 0; i < m_len; ++i)
	{
		m_space[i] = obj.m_space[i];
	}
	return*this;
}

template<typename T>
int MyVector<T>::get_len()
{
	return m_len;
}

template<typename T>
ostream&operator<<(ostream&out, const MyVector<T>&obj)
{
	for (int i = 0; i < obj.m_len; ++i)
	{
		out << obj.m_space[i] << ",";
	}
	out << endl;
	return out;
}