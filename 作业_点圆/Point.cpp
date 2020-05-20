#include "Point.h"

//默认参数在声明中有即可 定义中无须再写一遍
void Point::setPoint(double x, double y)
{
	m_x = x;
	m_y = y;
}
void Point::get_x_y(double&x, double&y)
{
	x = m_x;
	y = m_y;
}

double Point::getDistance(Point p)
{
	double p_x;
	double p_y;
	p.get_x_y(p_x, p_y);
	double distance = sqrt(pow(m_x - p_x, 2) + pow(m_y - p_y, 2));
	return distance;
}

Point Point::getPoint()
{
	Point p;
	p.setPoint(m_x, m_y);
	return p;
}

double Point::getX()
{
	return m_x;
}

double Point::getY()
{
	return m_y;
}