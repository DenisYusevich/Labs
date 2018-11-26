#pragma once

#ifndef POINT_H
#define POINT_H
class Point {
public:
	double x, y;
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {} // Конструктор
	// Другие методы
	void Show() const;
	double DistanceTo(Point) const; // Расстояние до другой точки
	void operator +=(Point&);
};
#endif /* POINT_H */
