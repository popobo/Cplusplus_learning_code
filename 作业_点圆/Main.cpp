#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"

void main()
{
	Point p1;
	p1.setPoint(10, 20);
	Point p2;
	p2 = p1.getPoint();
	cout << "p2.x=" << p2.getX() << endl;
	p2.setPoint(100, 200);
	Circle c1;
	Circle c2;
	c1.set_circle_center_r(p1, 1);
	c2.set_circle_center_r(p2, 201);
	cout << p1.getDistance(p2) << endl;
	cout << c1.judge_interset(c2) << endl;
	Rectangle r1;
	r1.setRectangle(p1, p2);
	cout << r1.getS() << endl;
	system("pause");
	return;
}
