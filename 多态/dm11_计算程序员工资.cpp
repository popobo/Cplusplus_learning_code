#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class Programmer
{
public:
	virtual void get_salary() = 0;
protected:
private:
};

class Junior_Programer:public Programmer
{
public:
	Junior_Programer(char*name, char*job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void get_salary()
	{
		cout << name << " " << job << ":" << sal << endl;
	}
protected:
private:
	char*name;
	char*job;
	int sal;
};

class Middle_Programer :public Programmer
{
public:
	Middle_Programer(char*name, char*job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void get_salary()
	{
		cout << name << " " << job << ":" << sal << endl;
	}
protected:
private:
	char*name;
	char*job;
	int sal;
};

class Advanced_Programer :public Programmer
{
public:
	Advanced_Programer(char*name, char*job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void get_salary()
	{
		cout << name << " " << job << ":" << sal << endl;
	}
protected:
private:
	char*name;
	char*job;
	int sal;
};

void CalProgrSal(Programmer*p)
{
	p->get_salary();
}


int main11()
{
	char name[] = "name";
	char job[] = "job";
	Junior_Programer jp(name, job, 1000);
	Middle_Programer mp(name, job, 10000);
	Advanced_Programer ap(name, job, 100000);
	CalProgrSal(&jp);
	CalProgrSal(&mp);
	CalProgrSal(&ap);
	
	system("pause");
	return EXIT_SUCCESS;
}
