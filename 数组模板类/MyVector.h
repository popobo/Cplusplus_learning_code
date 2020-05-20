#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

template<typename T>
 class MyVector
 {
 public:
	 MyVector(int size = 0);
	 MyVector(const MyVector &obj);
	 ~MyVector();

	 int get_len();

	 T&operator[](int index);
	 MyVector&operator=(const MyVector&obj);
		
	 friend ostream&operator<<<T>(ostream&out, const MyVector&obj);

 protected:
 private:
	 T*m_space;
	 int m_len;
 };
