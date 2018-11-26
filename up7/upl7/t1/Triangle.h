#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
class Triangle {
public:
	static int count; // Количество созданных объектов
	Triangle(Point, Point, Point, const char*); // Конструктор
	Triangle(const char*); // Конструктор пустого (нулевого) треугольника
	Triangle(const Triangle&); // Конструктор копирования
	
	~Triangle(); // Деструктор
	Point Get_v1() const { return v1; } // Получить значение v1
	Point Get_v2() const { return v2; } // Получить значение v2
	Point Get_v3() const { return v3; } // Получить значение v3
	char* GetName() const { return name; } // Получить имя объекта
	void Show() const; // Показать объект
	void Move(Point);
	double Area() const; // площадь объекта
	bool operator >(const Triangle&) const;
	Triangle& operator =(const Triangle&); // Операция присваивания
	double Area(Point, Point, Point) const; // Площать треугольника, образованного
 // заданными точками
	bool Contains(Point) const; // Определяет, находится ли точка внутри треугольника а также объявление дружественной функции :
	
	friend bool TriaInTria(Triangle, Triangle); // Определяет,
	 // входит ли один треугольник во второй

private:
	char* objID; // Идентификатор объекта
	char* name; // Наименование треугольника
	Point v1, v2, v3; // Вершины
	double a; // Сторона, соединяющая v1 и v2
	double b; // Сторона, соединяющая v2 и v3
	double c; // Сторона, соединяющая v1 и v3
};

#endif /* TRIANGLE_H */