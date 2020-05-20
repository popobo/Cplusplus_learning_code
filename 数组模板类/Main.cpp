#include "MyVector.cpp"

class Teacher
{
public:
	Teacher()
	{
		age = 33;
		strcpy(name, "");
	}
	Teacher(const char*name, int age)
	{
		this->age = age;
		strcpy(this->name, name);
	}
	Teacher&operator=(const Teacher&obj)
	{
		age = obj.age;
		strcpy(name, obj.name);
		return*this;
	}
	void print_teacher()
	{
		cout << name << ":" << age << endl;
	}
	friend ostream&operator<<(ostream&out, Teacher&obj);
protected:
private:
	int age;
	char name[32];
};

ostream&operator<<(ostream&out, Teacher&obj)
{
	out << obj.name << ":" << obj.age;
	return out;
}

class Student
{
public:
	Student()
	{
		m_age = 0;
		m_name = new char[1];
		strcpy(m_name, "");
	}
	Student(const char*in_name, int age)
	{
		m_age = age;
		m_name = new char[strlen(in_name)];
		strcpy(m_name, in_name);
	}
	Student(const Student&obj)
	{
		m_age = obj.m_age;
		m_name = new char[strlen(obj.m_name)];
		strcpy(m_name, obj.m_name);
	}
	~Student()
	{
		if (m_name != NULL)
		{
			delete[]m_name;
			m_age = 0;
			m_name = NULL;
		}
	}
	Student&operator=(const Student&obj)
	{
		if (obj.m_name != NULL)
		{
			delete[]m_name;
		}
		m_age = obj.m_age;
		m_name = new char[strlen(obj.m_name)];
		strcpy(m_name, obj.m_name);
		return*this;
	}
	friend ostream&operator<<(ostream&out, Student&obj);
protected:
private:
	int m_age;
	char*m_name;
};

ostream&operator<<(ostream&out, Student&obj)
{
	out << obj.m_name << ":" << obj.m_age << endl;
	return out;
}

int main()
{
	MyVector<int>myv1(10);
	for (int i = 0; i < myv1.get_len(); ++i)
	{
		myv1[i] = i * 5;
		cout << myv1[i] << endl;
	}
	MyVector<int>myv2 = myv1;

	cout << myv2;

	MyVector<char>myv3(10);
	for (int i = 0; i < myv2.get_len(); ++i)
	{
		myv3[i] = i * 5;
		cout << myv3[i] << endl;
	}
	cout << myv3;
	
	Teacher t1("aaa", 13), t2("bbb", 14), t3("ccc", 15);
	MyVector<Teacher>myv4(3);
	myv4[0] = t1;
	myv4[1] = t2;
	myv4[2] = t3;
	cout << myv4 << endl;

	Student s1("aaaa", 13), s2("bbbb", 14), s3("cccc", 15);
	MyVector<Student*>myv5(3);
	myv5[0] = &s1;
	myv5[1] = &s2;
	myv5[2] = &s3;
	cout << myv5 << endl;

	system("pause");
	return EXIT_SUCCESS;
}
