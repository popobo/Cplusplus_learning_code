#include "Circle.h"

void Circle::set_circle_center_r(Point cc, double in_r)
{
	circle_center = cc;
	m_r = in_r;
}

Point Circle::get_circle_center()
{
	return circle_center;
}

double Circle::getR()
{
	return m_r;
}

bool  Circle::judge_interset(Circle circle)
{
	double distance = circle_center.getDistance(circle.get_circle_center());
	if (distance <= m_r + circle.getR())
	{
		return true;
	}
	return false;
}