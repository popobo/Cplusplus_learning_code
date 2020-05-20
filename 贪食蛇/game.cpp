#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include "Wall.h"
#include "Snake.h"
#include "Food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

int get_frequence(Snake&snake)
{
	int frequence = 0;
	if (snake.get_length() < 5)
	{
		frequence = 300;
	}
	else if (snake.get_length() < 10)
	{
		frequence = 200;
	}
	else if (snake.get_length() < 15)
	{
		frequence = 100;
	}
	return frequence;
}


int main()
{

	srand((unsigned int)time(NULL));
	//是否死亡表示
	bool is_dead = false;
	Wall wall;
	wall.init_wall();
	wall.draw_wall();
	Food food(wall);
	Snake snake(wall,food);
	snake.init_snake();
	food.set_food();
	//接收用户的输入
	char key_input = '\0';
	char key_saved = '\0';
	int period = 0;

	while (!is_dead)
	{
		
		key_input = _getch();
		if (key_input != '\0' && (key_input == snake.UP || key_input == snake.DOWN || key_input == snake.LEFT || key_input == snake.RIGHT) )
		{
			key_saved = key_input;
		}
		if (key_saved == '\0')
		{
			continue;
		}
		do 
		{
			if (snake.move(key_saved) == true)
			{
				Sleep(get_frequence(snake));
			}
			else
			{
				is_dead = true;
				break;
			}
		} while (!_kbhit());//当没有键盘输入的时候 返回0
	}
	system("pause");
	return EXIT_SUCCESS;
}
