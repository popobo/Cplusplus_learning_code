#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<fstream>
using namespace std;

class Teacher
{
public:
	Teacher()
	{
		age = 33;
		strcpy(name, "hello");
	}
	Teacher(int _age, const char*_name)
	{
		age = _age;
		strcpy(name, _name);
	}
	void print_t()
	{
		cout << "name:" << name << " age:" << age << endl;
	}
private:
	int age;
	char name[32];
};


int main()
{
	//const char*fname = "./b.txt";
	//ofstream fout(fname, ios::app);//����� ��һ�������������ļ�����
	//if (!fout)
	//{
	//	cout << "���ļ�ʧ��" << endl;
	//	return 1;
	//}
	//fout << "hello1" << endl;
	//fout << "world1" << endl;
	//fout.close();
	//
	////���ļ�
	//ifstream fin(fname, ios::in);//����һ��������������ļ�����
	//char ch;
	//while (fin.get(ch))
	//{
	//	cout << ch;
	//}
	//fin.close();

	const char*fname = "a.dat";
	ofstream fout(fname, ios::binary);
	if (!fout)
	{
		cout << "���ļ�ʧ��" << endl;
	}
	Teacher t1(10, "abc"), t2(20, "def"), t3; 
	fout.write((char*)&t1, sizeof(Teacher));
	fout.write((char*)&t2, sizeof(Teacher));
	fout.write((char*)&t3, sizeof(Teacher));
	//�ļ��رպ����ݲ�д��
	fout.close();

	ifstream fin(fname);
	Teacher temp;
	fin.read((char*)&temp, sizeof(Teacher));
	temp.print_t();
	fin.read((char*)&temp, sizeof(Teacher));
	temp.print_t();
	fin.read((char*)&temp, sizeof(Teacher));
	temp.print_t();
	fin.close();
	system("pause");
	return EXIT_SUCCESS;
}
