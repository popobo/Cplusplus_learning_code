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
	//��Ϊ�������캯���Ƿ��ڱ����������ģ�
	//�����еĺ������Է��������Ķ�������г�Ա����Ȼ����˽�г�Ա��
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

//�����ķ���ֵ��һ��Ԫ�أ��������ͣ����ص���һ���µ��������� 
//���Ի��������������Ŀ������캯��
//���������ȥ����

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
	cout << "b�����Ѿ���ʼ�����" << endl;
	func(b);//bʵ��ȡ��ʼ���β�p �����copy���캯��
}

void playobj2()
{
	get_anonymous_object();
}


void playobj3()
{
	//�����������ʼ��m ��ʱC++������ֱ�Ӱ�����ת��m 
	//������ת���������� �Ͳ����ٵ��ù��캯���� 
	Location m = get_anonymous_object();
	cout << "�������󱻷��� ���ᱻ����" << endl;
	Location m2(2, 3);
	m2 = get_anonymous_object();
	cout << "��Ϊ����������=��m2 ������������";
	cout << m2.getX() << endl;
}

void playobj4()
{
	Location m2;
	Location m3(m2);//����Ҳ����ÿ������캯��
}
int main6()
{
	//playobj();
	playobj3();
	system("pause");
	return EXIT_SUCCESS;
}
