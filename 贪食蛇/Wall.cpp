#include "Wall.h"
using namespace std;

void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cin_info;



void gotoxy_real(int x, int y, char c)
{
	cin_info.bVisible = false;
	cin_info.dwSize = 1;
	SetConsoleCursorInfo(hOut, &cin_info);
	gotoxy(hOut, y * 2, x);
	cout << c << " ";
}

void Wall::init_wall()
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
			{
				game_array[i][j] = '*';
			}
			else
			{
				game_array[i][j] = ' ';
			}
		}
	}
}

void Wall::draw_wall()
{
	system("cls");
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			cout << game_array[i][j] << " ";
		}
		switch (i)
		{
		case 5:
			cout << "create by z";
			break;
		case 6:
			cout << "a : left";
			break;
		case 7:
			cout << "w : up";
			break;
		case 8:
			cout << "s : down";
			break;
		case 9:
			cout << "d : right";
			break;
		default:
			break;
		}
		//一行一行画
		cout << endl;
	}
}

void Wall::setWall(int x, int y, char c)
{
	game_array[x][y] = c;
}

char Wall::getWall(int x, int y)
{
	return game_array[x][y];
}
