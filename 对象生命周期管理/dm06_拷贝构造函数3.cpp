#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;


class Location
{
public:
	Location(int xx = 0, int yy = 0)
	{
		X = xx;
		Y = yy;
		cout << "Constructor Object\n";
	}
	//因为拷贝构造函数是放在本身这个类里的，
	//而类中的函数可以访问这个类的对象的所有成员，当然包括私有成员了
	Location(const Location&obj)
	{
		X = obj.X;
		Y = obj.Y;
		cout << "Copy Constructor Object\n";
	}
	int getX()
	{
		return X;
	}
	int getY()
	{
		return Y;
	}
	~Location()
	{
		cout << X << "," << Y << "Object Destroyed\n" << endl;
	}
private:
	int X, Y;
};

//函数的返回值是一个元素（复杂类型）返回的是一个新的匿名对象 
//所以会调用匿名对象类的拷贝构造函数
//匿名对象的去和留

Location get_anonymous_object()
{
	Location A(10, 20);
	return A;
}

void func(Location p)
{
	cout << p.getX() << endl;
}

void playobj()
{
	Location a(1, 2);
	Location b = a;
	cout << "b对象已经初始化完毕" << endl;
	func(b);//b实参取初始化形参p 会调用copy构造函数
}

void playobj2()
{
	get_anonymous_object();
}


void playobj3()
{
	//用匿名对象初始化m 此时C++编译器直接把匿名转成m 
	//从匿名转成有名字了 就不会再调用构造函数了 
	Location m = get_anonymous_object();
	cout << "匿名对象被扶正 不会被析构" << endl;
	Location m2(2, 3);
	m2 = get_anonymous_object();
	cout << "因为用匿名对象=给m2 匿名对象被析构";
	cout << m2.getX() << endl;
}

void playobj4()
{
	Location m2;
	Location m3(m2);//这样也会调用拷贝构造函数
}
int main6()
{
	//playobj();
	playobj3();
	system("pause");
	return EXIT_SUCCESS;
}
