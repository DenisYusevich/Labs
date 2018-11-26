#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
class Triangle {
public:
	static int count; // ���������� ��������� ��������
	Triangle(Point, Point, Point, const char*); // �����������
	Triangle(const char*); // ����������� ������� (��������) ������������
	Triangle(const Triangle&); // ����������� �����������
	
	~Triangle(); // ����������
	Point Get_v1() const { return v1; } // �������� �������� v1
	Point Get_v2() const { return v2; } // �������� �������� v2
	Point Get_v3() const { return v3; } // �������� �������� v3
	char* GetName() const { return name; } // �������� ��� �������
	void Show() const; // �������� ������
	void Move(Point);
	double Area() const; // ������� �������
	bool operator >(const Triangle&) const;
	Triangle& operator =(const Triangle&); // �������� ������������
	double Area(Point, Point, Point) const; // ������� ������������, �������������
 // ��������� �������
	bool Contains(Point) const; // ����������, ��������� �� ����� ������ ������������ � ����� ���������� ������������� ������� :
	
	friend bool TriaInTria(Triangle, Triangle); // ����������,
	 // ������ �� ���� ����������� �� ������

private:
	char* objID; // ������������� �������
	char* name; // ������������ ������������
	Point v1, v2, v3; // �������
	double a; // �������, ����������� v1 � v2
	double b; // �������, ����������� v2 � v3
	double c; // �������, ����������� v1 � v3
};

#endif /* TRIANGLE_H */