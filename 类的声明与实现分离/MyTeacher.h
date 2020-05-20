#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

class MyTeacher
{
private:
	int age;
	char name[32];
public:
	void setAge(int val);
	int getAge();
	void setName(char*val);
	char*getName();
};

