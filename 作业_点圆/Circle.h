#define _CRT_SECURE_NO_WARNINGS  
#pragma once
#include<iostream>
#include <math.h>
#include "Point.h"

class Circle
{
public:
	void set_circle_center_r(Point cc, double in_r);
	Point get_circle_center();
	double getR();
	bool judge_interset(Circle incircle);
private:
	Point circle_center;
	double m_r;
};

