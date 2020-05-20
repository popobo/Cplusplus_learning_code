#include "Complex09.h"

//构造函数的实现 写在了类的外部
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

//本质是 模板是两次编译生产的 第一次生成的函数头
//成员函数实现运算符重载
template<typename T>
Complex09<T> Complex09<T>::operator+(Complex09<T>&obj)
{
	Complex09<T> temp(a + obj.a, b + obj.b);//此处加不加<T>均可
	return temp;
}

template<typename T>
ostream&operator<<(ostream&cout, Complex09<T>&obj)
{
	cout << "a:" << obj.a << " b:" << obj.b << endl;
	return cout;
}