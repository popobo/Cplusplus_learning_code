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
//	//��Ϊ�������캯���Ƿ��ڱ����������ģ�
//	//�����еĺ������Է��������Ķ�������г�Ա����Ȼ����˽�г�Ա��
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
//	cout << "b�����Ѿ���ʼ�����" << endl;
//	func(b);//bʵ��ȡ��ʼ���β�p �����copy���캯��
//}
//int main5()
//{
//	playobj();
//	system("pause");
//	return EXIT_SUCCESS;
//}
