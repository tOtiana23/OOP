//Бусыгина Татьяна, ИВТ-22
//Класс движущаяся точка

#define _USE_MATH_DEFINES
#include "Class_MovingPoint.h"
#include <cmath>
	
//конструктор
MovingPoint::MovingPoint()
{
	StartSpeed = 0;
	acceleration = 0;
}

///геттер для начальной скорости, читает значение нач. скорости
double MovingPoint::get_StartSpeed()
{
	return StartSpeed;
}

///геттер для ускорения, читает значение ускорения
double MovingPoint::get_acceleration()
{
	return acceleration;
}

///сеттер для начальной скорости, ввод нач. скорости
void MovingPoint::set_StartSpeed(double StartSpeed1)
{
	StartSpeed = StartSpeed1;
}

///сеттер для ускорения, ввод ускорения
void MovingPoint::set_acceleration(double acceleration1)
{
	acceleration = acceleration1;
}

///нахождение расстояние за определённое время time
double MovingPoint::find_distanceT(double time)
{
	return StartSpeed * time + (acceleration * pow(time, 2)) / 2;
}

///нахождение расстояние с помощью начальной и мгновенной
 скорости
double MovingPoint::find_distanceS(double speed)
{
	return (pow(speed, 2) - pow(StartSpeed, 2)) / 2 * acceleration;
}

///нахождение мгновенной скорости в определённое время time
double MovingPoint::find_speed(double time)
{
	return StartSpeed + acceleration * time;
}

///нахождение средней скорости
double MovingPoint::average_speed(double speed)
{
	return (speed + StartSpeed)/2;
}