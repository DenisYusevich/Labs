#include <iostream>
//#include <ñmath>
#include "Point.h"
using namespace std;
void Point::Show() const { cout << " (" << x << ", " << y << ")"; }
double Point::DistanceTo(Point sp) const {
	return sqrt((x - sp.x) * (x - sp.x) + (y - sp.y) * (y - sp.y));
}

void Point::operator +=(Point& p) { x += p.x; y += p.y; }
