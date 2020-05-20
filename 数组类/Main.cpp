#include "MyArray.h"

int main()
{
	MyArray a1(10);
	for (int i = 0; i < a1.length(); ++i)
	{
		a1[i] = i * 8;
	}
	for (int i = 0; i < a1.length(); ++i)
	{
		cout << a1[i] << endl;
	}

	MyArray a2 = a1;
	MyArray a3(5);
	a3 = a1;
	for (int i = 0; i < a1.length(); ++i)
	{
		cout << a3[i] << endl;
	}
	if (a1 == a3)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	MyArray a4(20);
	for (int i=0;i<a4.length();++i)
	{
		a4[i] = i * 4;
	}
	if (a3 != a4)
	{
		cout << "a3 != a4" << endl;
	}


	system("pause");
	return EXIT_SUCCESS;
}