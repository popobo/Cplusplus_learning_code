#include "MyTeacher.h"

void MyTeacher::setAge(int val)
{
	//��Ϊ�����Ʒ� �൱��ֱ��������ʵ�ַ���
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

