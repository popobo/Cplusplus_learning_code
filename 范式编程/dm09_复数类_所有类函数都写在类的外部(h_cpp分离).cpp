#include "Complex09.hpp" //��������Ԫ���� ��������.cpp

int main09()
{
	Complex09<int>c1(1, 2);
	cout << c1;
	c1.print_com();
	Complex09<int>c2(3, 4);

	Complex09<int>c3 = c1 + c2;
	cout << c3;

	system("pause");
	return EXIT_SUCCESS;
}
