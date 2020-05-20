#include "MyTeacher.h"

void MyTeacher::setAge(int val)
{
	//因为域限制符 相当于直接在类中实现方法
	age = val;
}

int MyTeacher::getAge()
{
	return age;
}

void MyTeacher::setName(char*val)
{
	strcpy(name, val);
}

char*MyTeacher::getName()
{
	return name;
}

