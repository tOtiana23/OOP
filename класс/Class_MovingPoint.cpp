//Бусыгина Татьяна, ИВТ-22
//Класс движущаяся точка

#define _USE_MATH_DEFINES
#include "Class_MovingPoint.h"
#include <cmath>
#include <cassert> //библиотека для assert
#include <string>
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <exception>

	
//конструктор
MovingPoint::MovingPoint()
{
	start_speed = 0;
	acceleration = 0;
}

//конструктор с параметрами
MovingPoint::MovingPoint(double start_speed1, double acceleration1)
{
	set_start_speed(start_speed1);
	set_acceleration(acceleration1);

}

///геттер для начальной скорости, читает значение нач. скорости
double MovingPoint::get_start_speed() const
{
	return start_speed;
}

///геттер для ускорения, читает значение ускорения
double MovingPoint::get_acceleration() const
{
	return acceleration;
}

///сеттер для начальной скорости, ввод нач. скорости
void MovingPoint::set_start_speed(double start_speed1)
{
	start_speed = start_speed1;
}

///сеттер для ускорения, ввод ускорения
void MovingPoint::set_acceleration(double acceleration1)
{
	acceleration = acceleration1;
}

///нахождение расстояние за определённое время time
double MovingPoint::find_distanceT(double time) const
{
	return start_speed * time + (acceleration * pow(time, 2)) / 2;
}

///нахождение расстояние с помощью начальной и мгновенной скорости
double MovingPoint::find_distanceS(double speed) const 
{
	return (pow(speed, 2) - pow(start_speed, 2)) / (2 * acceleration);
}

///нахождение мгновенной скорости в определённое время time
double MovingPoint::find_speed(double time) const
{
	return start_speed + acceleration * time;
}

///нахождение средней скорости
double MovingPoint::average_speed(double speed) const
{
	return (speed + start_speed)/2;
}

///вывод начальной скорости и ускорения
std::string MovingPoint::output_string() const
{
	std::string s = "Start speed: " + std::to_string(get_start_speed()) + "\n" + "Acceleration: " + std::to_string(get_acceleration()) + "\n";
	return s;
}

///сохранение скорости и ускорения в бинарный файл
void MovingPoint::save_point(MovingPoint& Point, const std::string& filename)
{
	std::ofstream file(filename, std::ios::binary);
	if (file.is_open())
	{
		double temp;
		temp = Point.get_acceleration();
		file.write(reinterpret_cast< char*>(&temp), sizeof(temp));
		temp = Point.get_start_speed();
		file.write(reinterpret_cast< char*>(&temp), sizeof(temp));
		file.close();
	}
	else {
        throw std::runtime_error("File_is_not_found_:(");
	}
}

///загрузка скорости и ускорения из бинарного файла
void MovingPoint::load_point(MovingPoint& Point, const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);
	if (file.is_open()) {
 		double temp;
	file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
	Point.set_acceleration(temp);
	file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
	Point.set_start_speed(temp);
	}
 	else {
       throw std::runtime_error("File_is_not_found_:(");
	}
}

///тестирование методов
void test()
{
	MovingPoint Test; 									//Test экземпляр класса MovingPoint
	// MovingPoint(3, 4);
	Test.set_start_speed(3); 							//задаём значение начальной скорости через метод сет
	Test.set_acceleration(4); 							//задаём значение ускорения через метод сет

	assert(Test.average_speed(3) == 3); 				//тест метода нахождения средней скорости
	assert(Test.average_speed(5) == 4); 
	assert(Test.average_speed(10) == 6.5);

	assert(Test.find_speed(6) == 27); 					//тест метода нахождения мгновенной скорости
	assert(Test.find_speed(10) == 43);
	assert(Test.find_speed(2) == 11);

	assert(Test.find_distanceS(9) == 9); 				//тест метода нахождения пути через мгновенную скорость
	assert(Test.find_distanceS(3) == 0);
	assert(Test.find_distanceS(25) == 77);

	assert(Test.find_distanceT(4) == 44); 				//тест метода нахождения пути через время
	assert(Test.find_distanceT(6) == 90);
	assert(Test.find_distanceT(8) == 152);
}