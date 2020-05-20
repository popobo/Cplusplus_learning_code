#define _CRT_SECURE_NO_WARNINGS  
#pragma once
#include<iostream>
#include <math.h>
#include "Point.h"
using namespace std;

class Rectangle
{
public:
	void setRectangle(Point inlt, Point inrb);
	double getS();
private:
	Point m_left_top;
	Point m_right_bottom;
};

