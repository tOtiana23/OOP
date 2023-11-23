//Бусыгина Татьяна, ИВТ-22
//Класс движущаяся точка

#ifndef CLASS_MOVINGPOINT_H
#define CLASS_MOVINGPOINT_H
#include <string>


///Движущаяся точка
class MovingPoint {
private:
	//поля класса
	double start_speed, acceleration; //начальная скорость и ускорение

public:
	//конструктор
	MovingPoint();
	
	//конструктор с параметрами
	MovingPoint(double start_speed1, double acceleration);

	//методы класса

	///геттер для начальной скорости, читает значение нач. скорости
	double get_start_speed() const;
	///геттер для ускорения, читает значение ускорения
	double get_acceleration() const;
	///сеттер для начальной скорости, ввод нач. скорости
	void set_start_speed(double start_speed1);
	///сеттер для ускорения, ввод ускорения
	void set_acceleration(double acceleration1);
	///нахождение расстояние за определённое время time
	double find_distanceT(double time) const;
	///нахождение расстояние с помощью начальной и мгновенной скорости speed
	double find_distanceS(double speed) const;
	///нахождение мгновенной скорости в определённое время time
	double find_speed(double time) const;
	///нахождение средней скорости
	double average_speed(double speed) const;
	///вывод начальной скорости и ускорения
	std::string output_string() const;
	///сохранение скорости и ускорения в бинарный файл
	void save_point(MovingPoint& Point, const std::string& filename);
	///загрузка скорости и ускорения из бинарного файла
	void load_point(MovingPoint& Point, const std::string &filename);
};

	///тестирование методов
	void test();
#endif