#pragma once
#include <iostream>
#include "Wall.h"
using namespace std;

extern void gotoxy_real(int x, int y, char c);

class Food
{
public:
	Food(Wall&tempwall);
	void set_food();
private:
	Wall&wall;
	int x;
	int y;
};