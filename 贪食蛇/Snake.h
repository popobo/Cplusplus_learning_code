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
	//初始化
	void init_snake();
	//添加节点
	void add_point(int x, int y);
	//销毁节点
	void destroy_point();
	//删除节点
	void del_point();
	//移动蛇的操作 返回值代表移动是否成功
	bool move(char key);
	//获取蛇的长度
	int get_length();
protected:
private:
	//节点
	typedef struct Point
	{
		//数据域
		int x;
		int y;

		//指针域
		Point*next;
	};
	Point*pHead;
	Wall&wall;
	Food&food;
	bool is_circle;
};