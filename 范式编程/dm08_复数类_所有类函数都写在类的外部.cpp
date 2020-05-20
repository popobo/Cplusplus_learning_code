#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

//ע��template<typename T>��Ͻ�ķ�Χ
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

//��������ص�����д��
//����<<>>ֻ������Ԫ���� ������������� ��Ҫд�ɳ�Ա���� ��Ҫ������Ԫ����
//ostream&operator<<(ostream&out, Complex08&obj)
//{
//	cout << "a:" << obj.a << " b:" << obj.b << endl;
//	return cout;
//}

//���캯����ʵ�� д��������ⲿ
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

//������ ģ�������α��������� ��һ�����ɵĺ���ͷ
//��Ա����ʵ�����������
template<typename T>
Complex08<T> Complex08<T>::operator+(Complex08<T>&obj)
{
	Complex08<T> temp(a + obj.a, b + obj.b);//�˴��Ӳ���<T>����
	return temp;
}

template<typename T>
ostream&operator<<(ostream&out, Complex08<T>&obj)
{
	cout << "a:" << obj.a << " b:" << obj.b << endl;
	return cout;
}
//����	LNK2019	�޷��������ⲿ���� 
//"class std::basic_ostream<char,struct std::char_traits<char> > 
//& __cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> > 
//&,class Complex08<int> &)" (? ? 6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@AAV?$Complex08@H@@@Z)��
//�÷����ں��� _main �б�����	��ʽ���	D : \Files\Visual Studio 2017\source\repos\Cplusplus\��ʽ���\dm08_������_�����ຯ����д������ⲿ.obj	1


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
