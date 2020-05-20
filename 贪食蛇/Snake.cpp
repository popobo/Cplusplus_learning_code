#include "Snake.h"

Snake::Snake(Wall & temp_wall, Food & temp_food):wall(temp_wall), food(temp_food)
{
	pHead = NULL;
	is_circle = false;
}

void Snake::init_snake()
{
	destroy_point();
	add_point(5, 3);
	add_point(5, 4);
	add_point(5, 5);
}

void Snake::add_point(int x, int y)
{
	//�����½ڵ�
	Point*new_point = new Point;
	new_point->x = x;
	new_point->y = y;
	new_point->next = NULL;
	//���ԭ��ͷ�ڵ㲻Ϊ�� ��Ϊ����
	if (pHead != NULL)
	{
		wall.setWall(pHead->x, pHead->y, '=');
		gotoxy_real(pHead->x, pHead->y, '=');
	}
	new_point->next = pHead;
	//����ͷ��
	pHead = new_point;
	wall.setWall(pHead->x, pHead->y, '@');
	gotoxy_real(pHead->x, pHead->y, '@');
}

//�������нڵ�
void Snake::destroy_point()
{
	Point*pCur = pHead;
	while (pHead != NULL)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::del_point()
{
	//�����ڵ����� ��ȥ��ɾ������
	if (pHead == NULL || pHead->next == NULL)
	{
		return;
	}
	Point*pCur = pHead->next;
	Point*pPre = pHead;
	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	wall.setWall(pCur->x, pCur->y, ' ');
	gotoxy_real(pCur->x, pCur->y, ' ');
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;
	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}
	//�ж������һ����β��
	Point*pCur = pHead->next;
	Point*pPre = pHead;
	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (x == pCur->x && y == pCur->y)
	{
		is_circle = true;
	}
	else
	{
		//�ж��û�Ҫ����λ���Ƿ�ɹ�
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
		{
			add_point(x, y);
			del_point();
			gotoxy(hOut, wall.COL*x, wall.ROW);
			cout << "Game Over!" << endl;
			return false;
		}
	}
	//�ƶ��ɹ� ������
	//�Ե�ʳ�� δ�ٵ�ʳ��
	if (wall.getWall(x, y) == '#')
	{
		add_point(x, y);
		food.set_food();
	}
	//δ�Ե�ʳ��
	else if (wall.getWall(x, y) == ' ')
	{
		add_point(x, y);
		del_point();
		if (is_circle)
		{
			wall.setWall(x, y, '@');
			gotoxy_real(x, y, '@');
		}	
	}
	return true;
}

int Snake::get_length()
{
	Point*pCur = pHead;
	int length = 0;
	while (pCur != NULL)
	{
		length++;
		pCur = pCur->next;
	}
	return length;
}
