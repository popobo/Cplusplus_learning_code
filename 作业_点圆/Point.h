#define _CRT_SECURE_NO_WARNINGS  
#pragma once
#include<iostream>
#include <math.h>
using namespace std;

class Point
{
public:
	void setPoint(double x = 0, double y = 0);
	void get_x_y(double&x, double&y);
	double getDistance(Point p);
	Point getPoint();
	double getX();
	double getY();
private:
	double m_x;
	double m_y;
};

