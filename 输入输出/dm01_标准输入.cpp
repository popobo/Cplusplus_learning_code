#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include "string"
using namespace std;

//��׼����������cin���ص����յĺ���
//cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
//cin.get(һ������) //��һ���ַ�
//cin.get(��������) //���Զ��ַ���
//cin.getline()
//cin.ignore()
//cin.peek()
//cin.putback()


int main01()
{
	char myBuf[1024];
	int myInt;
	long myLong;
	//cin >> myInt;
	//cin >> myLong;
	//cin >> myBuf; //�����ո�ֹͣ��������
	//cout << "myInt:" << myInt << " myLong:" << myLong << " myBuf:" << myBuf << endl;
	//char ch;
	//while ((ch = cin.get()) != EOF)
	//{
	//	cout << ch << endl;
	//}
	//cout << "cin.get(a)���������û������ ���������\n" << endl;
	//char a, b, c;
	//cin.get(a);
	//cin.get(b);
	//cin.get(c);
	//cout << a << b << c << "��Ϊ���������������Բ�����" << endl;
	//cin.get(a).get(b).get(c);
	//cout << a << b << c << endl;
	//char buf1[256];
	//char buf2[256];
	//cin >> buf1;
	//cin.ignore(20);
	//int myint = cin.peek();
	//cout << "myint" << myint << endl;
	//cin.getline(buf2, 256);
	// 
	//cout << "buf1:" << buf1 << endl << "buf2:" << buf2 << endl;
	cout << "Please, enter a number or a word: ";
	char c = std::cin.get();

	if ((c >= '0') && (c <= '9')) //������������ַ��� �ֿ�����
	{
		int n; //���������� �м��пո� ʹ��cin >>n
		cin.putback(c);
		cin >> n;
		cout << "You entered a number: " << n << '\n';
	}
	else
	{
		string str;
		cin.putback(c);
		getline(cin, str); // //�ַ��� �м�����пո� ʹ�� cin.getline();
		cout << "You entered a word: " << str << '\n';
	}

	system("pause");
	return EXIT_SUCCESS;
}
