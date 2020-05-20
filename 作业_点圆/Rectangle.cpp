#include "Rectangle.h"

void Rectangle::setRectangle(Point inlt, Point inrb)
{
	m_left_top = inlt;
	m_right_bottom = inrb;
}

double Rectangle::getS()
{
	return abs(m_left_top.getX() - m_right_bottom.getX())*abs(m_left_top.getY() - m_right_bottom.getY());
}