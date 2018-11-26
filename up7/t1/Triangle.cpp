#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include "Triangle.h"
using namespace std;
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident)
	: v1(_v1), v2(_v2), v3(_v3) {
	char buf[16];
	objID = new char[strlen(ident) + 1];
	strcpy_s(objID, strlen(objID), ident);
	count++;
	sprintf_s(buf, "Треугольник %d", count);
	name = new char[strlen(buf) + 1];
	strcpy_s(name, strlen(name), buf);
	a = v1.DistanceTo(v2);
	b = v2.DistanceTo(v3);
	c = v1.DistanceTo(v3);
	cout << "Constructor_1 for: " << objID << " (" << name << ")\n"; // для отладки
}
Triangle::Triangle(const char* ident) {
	char buf[16];
	objID = new char[strlen(ident) + 1];
	strcpy_s(objID, strlen(objID),ident);
	count++;
	sprintf_s(buf, "Треугольник %d", count);
	name = new char[strlen(buf) + 1];
	strcpy_s(name,strlen(name), buf);
	a = b = c = 0;
	cout << "Constructor_2 for: " << objID << " (" << name << ")\n"; // для отладки
}
Triangle::~Triangle() {
	cout << "Destructor for: " << objID << endl;
	delete[] objID;
	delete[] name;
}
void Triangle::Show() const {
	cout << name << ":";
	v1.Show(); v2.Show(); v3.Show();
	cout << endl;
}
void Triangle::Move(Point dp) {
	v1 += dp; v2 += dp; v3 += dp;
}

double Triangle::Area() const {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
bool Triangle::operator >(const Triangle& tria) const {
	if (Area() > tria.Area()) return true;
	else return false;
}
// Конструктор копирования
Triangle::Triangle(const Triangle& tria) : v1(tria.v1), v2(tria.v2), v3(tria.v3) {
	cout << "Copy constructor for: " << tria.objID << endl; // Отладочный вывод
	objID = new char[strlen(tria.objID) + strlen("(копия)") + 1];
	strcpy_s(objID,strlen(objID) ,tria.objID);
	strcat_s(objID,strlen(objID) ,"(копия)");
	name = new char[strlen(tria.name) + 1];
	strcpy_s(name, strlen(name),tria.name);
	v1 = tria.v1; v2 = tria.v2; v3 = tria.v3;
	a = tria.a; b = tria.b; c = tria.c;
}
// Присвоить значение объекта tria
Triangle& Triangle::operator =(const Triangle& tria) {
	// отладочный вывод:
	cout << "Assign operator: " << objID << " = " << tria.objID << endl;
	if (&tria == this) return *this;
	delete[] name;
	name = new char[strlen(tria.name) + 1];
	strcpy_s(name, strlen(name), tria.name);
	v1 = tria.v1; v2 = tria.v2; v3 = tria.v3;
	a = tria.a; b = tria.b; c = tria.c;
	return *this;
}

double Triangle::Area(Point p1, Point p2, Point p3) const {
	double a1 = p1.DistanceTo(p2);
	double b1 = p2.DistanceTo(p3);
	double c1 = p1.DistanceTo(p3);
	double p = (a1 + b1 + c1) / 2; 
		return sqrt(p * (p - a1) * (p - b1) * (p - c1));
}
bool Triangle::Contains(Point pt) const {
	const double calc_error = 0.001;
	double area1 = Area(pt, v1, v2);
	double area2 = Area(pt, v2, v3);
	double area3 = Area(pt, v3, v1);
	if (fabs(area1 + area2 + area3 - Area()) < calc_error) return true;
	else return false;
}

bool TriaInTria(Triangle tria1, Triangle tria2) {
	Point v1 = tria1.Get_v1();
	Point v2 = tria1.Get_v2();
	Point v3 = tria1.Get_v3();
	return (tria2.Contains(v1) && tria2.Contains(v2) && tria2.Contains(v3));
}