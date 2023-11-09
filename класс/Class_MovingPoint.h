//Бусыгина Татьяна, ИВТ-22
//Класс движущаяся точка

#ifndef CLASS_MOVINGPOINT_H
#define CLASS_MOVINGPOINT_H

#include <cmath>

///Объект - движущаяся точка
class MovingPoint {
private:
	//поля класса
	double StartSpeed, acceleration; //начальная скорость и ускорение

public:
	//конструктор
	MovingPoint();

	//методы класса

	///геттер для начальной скорости, читает значение нач. скорости
	double get_StartSpeed();
	///геттер для ускорения, читает значение ускорения
	double get_acceleration();
	///сеттер для начальной скорости, ввод нач. скорости
	void set_StartSpeed(double StartSpeed1);
	///сеттер для ускорения, ввод ускорения
	void set_acceleration(double acceleration1);
	///нахождение расстояние за определённое время time
	double find_distanceT(double time);
	///нахождение расстояние с помощью начальной и мгновенной скорости speed
	double find_distanceS(double speed);
	///нахождение мгновенной скорости в определённое время time
	double find_speed(double time);
	///нахождение средней скорости
	double average_speed(double speed);

};

#endif