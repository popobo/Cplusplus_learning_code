#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

struct Teacher
{
	char name[64];
	int age;
};

void getTeacher(Teacher**pT)
{
	Teacher*temp = (Teacher*)malloc(sizeof(Teacher));	
	temp->age = 34;
	strcpy(temp->name, "zhang");
	*pT = temp;
}

void getTeacher2(Teacher*&myp)
{
	Teacher*temp = (Teacher*)malloc(sizeof(Teacher));
	temp->age = 345;
	strcpy(temp->name, "zhang");
	myp = temp;
}

void FreeMem(Teacher*&myp)
{
	free(myp);
	myp = NULL;
}
int main()
{
	Teacher*pT = NULL;
	getTeacher(&pT);
	cout << pT->name << endl;
	
	//c++中的引用
	getTeacher2(pT);
	cout << pT->age << endl;

	FreeMem(pT);

	system("pause");
	return EXIT_SUCCESS;
}


