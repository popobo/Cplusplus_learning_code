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
	//��ʼ��ǽ��
	void init_wall();
	//����ǽ��
	void draw_wall();
	//������������ ��ά�����������
	void setWall(int x, int y, char c);
	//����������ȡ��ǰ���õķ���
	char getWall(int x, int y);
private:
	char game_array[ROW][COL];
};