#pragma once
#include <iostream>
#include "Wall.h"
#include "Food.h"
using namespace std;

extern void gotoxy_real(int x, int y, char c);
extern void gotoxy(HANDLE hOut, int x, int y);
extern HANDLE hOut;


class Snake
{
public:
	Snake(Wall&temp_wall, Food&temp_food);
	enum
	{
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd'
	};
	//��ʼ��
	void init_snake();
	//��ӽڵ�
	void add_point(int x, int y);
	//���ٽڵ�
	void destroy_point();
	//ɾ���ڵ�
	void del_point();
	//�ƶ��ߵĲ��� ����ֵ�����ƶ��Ƿ�ɹ�
	bool move(char key);
	//��ȡ�ߵĳ���
	int get_length();
protected:
private:
	//�ڵ�
	typedef struct Point
	{
		//������
		int x;
		int y;

		//ָ����
		Point*next;
	};
	Point*pHead;
	Wall&wall;
	Food&food;
	bool is_circle;
};