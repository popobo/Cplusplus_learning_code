#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//注意template<typename T>管辖的范围
template<typename T>
class Complex08
{
public:
	Complex08(T a, T b);
	void print_com();
	Complex08 operator+(Complex08&obj);
	friend ostream&operator<<<T>(ostream&out, Complex08<T>&obj);
	
	friend Complex08 Mysub07(Complex08&c1, Complex08&c2)
	{
		Complex08 temp(c1.a - c2.a, c1.b - c2.b);
		return temp;
	}
protected:
private:
	T a;
	T b;
};

//运算符重载的正规写法
//重载<<>>只能用友元函数 其他运算符重载 都要写成成员函数 不要滥用友元函数
//ostream&operator<<(ostream&out, Complex08&obj)
//{
//	cout << "a:" << obj.a << " b:" << obj.b << endl;
//	return cout;
//}

//构造函数的实现 写在了类的外部
template<typename T>
Complex08<T>::Complex08(T a, T b)
{
	this->a = a;
	this->b = b;
}

template<typename T>
void Complex08<T>::print_com()
{
	cout << "a:" << a << " b:" << b << endl;
}

//本质是 模板是两次编译生产的 第一次生成的函数头
//成员函数实现运算符重载
template<typename T>
Complex08<T> Complex08<T>::operator+(Complex08<T>&obj)
{
	Complex08<T> temp(a + obj.a, b + obj.b);//此处加不加<T>均可
	return temp;
}

template<typename T>
ostream&operator<<(ostream&out, Complex08<T>&obj)
{
	cout << "a:" << obj.a << " b:" << obj.b << endl;
	return cout;
}
//错误	LNK2019	无法解析的外部符号 
//"class std::basic_ostream<char,struct std::char_traits<char> > 
//& __cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> > 
//&,class Complex08<int> &)" (? ? 6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@AAV?$Complex08@H@@@Z)，
//该符号在函数 _main 中被引用	范式编程	D : \Files\Visual Studio 2017\source\repos\Cplusplus\范式编程\dm08_复数类_所有类函数都写在类的外部.obj	1


int main08()
{
	Complex08<int>c1(1, 2);
	cout << c1;
	c1.print_com();
	Complex08<int>c2(3, 4);

	Complex08<int>c3 = c1 + c2;
	cout << c3;

	Complex08<int>c4 = Mysub07(c2, c1);
	c4.print_com();

	system("pause");
	return EXIT_SUCCESS;
}
