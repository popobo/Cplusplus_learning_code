#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;


class Wall
{
public:
	enum {
		ROW = 26,
		COL = 26
	};
	//初始化墙壁
	void init_wall();
	//画出墙壁
	void draw_wall();
	//根据索引设置 二维数组里的内容
	void setWall(int x, int y, char c);
	//根据索引获取当前外置的符号
	char getWall(int x, int y);
private:
	char game_array[ROW][COL];
};