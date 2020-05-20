#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<iomanip>
using namespace std;


int main02()
{
	cout << "hello" << endl;
	cout.put('h').put('e');
	cout << endl;
	const char*p = "hello world";
	cout.write(p, strlen(p));
	cout << endl;
	cout.write(p, strlen(p) - 4);
	cout << endl;

	cout << "<start>";
	cout.width(30);
	cout.fill('*');
	cout.setf(ios::showbase);
	cout.setf(ios::internal);
	cout << hex << 123 << "<end>\n";
	
	cout << "<start>"
		<< setw(30)
		<< setfill('*')
		<< setiosflags(ios::showbase) //»ùÊý
		<< setiosflags(ios::internal)
		<< hex
		<< 123
		<< "<end>\n";

	system("pause");
	return EXIT_SUCCESS;
}
