#include "Complex09.h"

//���캯����ʵ�� д��������ⲿ
template<typename T>
Complex09<T>::Complex09(T a, T b)
{
	this->a = a;
	this->b = b;
}

template<typename T>
void Complex09<T>::print_com()
{
	cout << "a:" << a << " b:" << b << endl;
}

//������ ģ�������α��������� ��һ�����ɵĺ���ͷ
//��Ա����ʵ�����������
template<typename T>
Complex09<T> Complex09<T>::operator+(Complex09<T>&obj)
{
	Complex09<T> temp(a + obj.a, b + obj.b);//�˴��Ӳ���<T>����
	return temp;
}

template<typename T>
ostream&operator<<(ostream&cout, Complex09<T>&obj)
{
	cout << "a:" << obj.a << " b:" << obj.b << endl;
	return cout;
}