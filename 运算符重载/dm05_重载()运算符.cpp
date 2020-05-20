#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class F05
{
public:
	int operator()(int a, int b)
	{
		return a * a + b * b;
	}
	int operator()(int a, int b, int c)
	{
		return a * a + b * b + c * c;
	}
protected:
private:
};

int main()
{
	F05 f;
	cout << f(2, 3, 4) << endl;
	system("pause");
	return EXIT_SUCCESS;
}
