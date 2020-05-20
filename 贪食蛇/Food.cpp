#include "Food.h"

Food::Food(Wall & tempwall):wall(tempwall)
{

}

void Food::set_food()
{
	while (true)
	{
		int food_x = rand() % (Wall::ROW - 2) + 1;
		int food_y = rand() % (Wall::COL - 2) + 1;
		//��������λ������ͷ������ ���������������
		if (wall.getWall(food_x, food_y) == ' ')
		{
			wall.setWall(food_x, food_y, '#');
			gotoxy_real(food_x, food_y, '#');
			break;
		}
	}
}
