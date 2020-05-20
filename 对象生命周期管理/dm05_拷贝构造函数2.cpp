//#define _CRT_SECURE_NO_WARNINGS  
//#include<iostream>
//using namespace std;
//
//
//class Location
//{
//public:
//	Location(int xx = 0, int yy = 0)
//	{
//		X = xx;
//		Y = yy;
//		cout << "Constructor Object\n";
//	}
//	//因为拷贝构造函数是放在本身这个类里的，
//	//而类中的函数可以访问这个类的对象的所有成员，当然包括私有成员了
//	Location(const Location&obj)
//	{
//		X = obj.X;
//		Y = obj.Y;
//		cout << "Copy Constructor Object\n";
//	}
//	int getX()
//	{
//		return X;
//	}
//	int getY()
//	{
//		return Y;
//	}
//	~Location()
//	{
//		cout << X << "," << Y << "Object Destroyed\n" << endl;
//	}
//private:
//	int X, Y;
//};
//
//void func(Location p)
//{
//	cout << p.getX() << endl;
//}
//
//void playobj()
//{
//	Location a(1, 2);
//	Location b = a;
//	cout << "b对象已经初始化完毕" << endl;
//	func(b);//b实参取初始化形参p 会调用copy构造函数
//}
//int main5()
//{
//	playobj();
//	system("pause");
//	return EXIT_SUCCESS;
//}
