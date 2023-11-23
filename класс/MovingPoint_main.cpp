//Бусыгина Татьяна, ИВТ-22
//Класс движущаяся точка
#include "Class_MovingPoint.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	MovingPoint Point; 																//Point экземпляр класса MovingPoint
	double time, start_speed, acceleration, speed;
	char check;	
	int i;

	test();																			//тестирование методов

	MovingPoint * Point_din = new MovingPoint;										//динамическое создание объекта
	(*Point_din).set_start_speed(6); 												//работа с его методами первым способом
	Point_din->set_acceleration(7); 												//работа с его методами вторым способом
	cout << "Start speed: " << Point_din->get_start_speed() << ", acceleration: "
	<< Point_din->get_acceleration() << endl;
	delete Point_din; 																//удаление динамического объекта

	MovingPoint Point_arr[10];														//cтатический массив из объектов из 10 объектов
	Point_arr[0].set_start_speed(9);
	Point_arr[1].set_acceleration(10);
	cout << "Start speed: " << Point_arr[0].get_start_speed() <<
	", acceleration: " << Point_arr[1].get_acceleration() << endl;
	MovingPoint Point_mo[2] {MovingPoint(3, 4),
							 MovingPoint(5, 6) };

	MovingPoint *Point_uk[2];														//массив из указателей на объекты
	Point_uk[0] = new MovingPoint();
	Point_uk[1] = new MovingPoint();
	Point_uk[0]->set_start_speed(11);
	Point_uk[1]->set_acceleration(12);
	cout << "Start speed: " << Point_uk[0]->get_start_speed() << ", acceleration: "
	<< Point_uk[1]->get_acceleration() << endl;
	delete Point_uk[0];
	delete Point_uk[1];

 	MovingPoint**Point_din_uk = new MovingPoint*[10];								//динамический массив из указателей на объекты
 	for (int i = 0; i < 10; i++) 
 	{
 		Point_din_uk[i] = new MovingPoint(); 										//создание

 	}
 	Point_din_uk[0]->set_start_speed(13);
	Point_din_uk[1]->set_acceleration(14);
 	cout << "Start speed: " << Point_din_uk[0]->get_start_speed() << ", acceleration: "
	<< Point_din_uk[1]->get_acceleration() << endl;
 	for (int i = 0; i < 10; i++) 
 		delete Point_din_uk[i]; 													//удаление
	delete[] Point_din_uk; 															//удалить весь массив	   

 	vector<MovingPoint> Point_vec(3);												//массив с помощью векторов
 	Point_vec[0].set_start_speed(15);
 	Point_vec[1].set_acceleration(16);
 	cout << "Start speed: " << Point_vec[0].get_start_speed() << ", acceleration: "
	<< Point_vec[1].get_acceleration() << endl;

 	vector<MovingPoint*> Point_vec_uk(3);											//массив с помощью векторов из указателей
 	for (int i = 0; i < Point_vec_uk.size(); i++) 
 		Point_vec_uk[i] = new MovingPoint(); 										//создание
 	Point_vec_uk[0]->set_start_speed(17);
 	Point_vec_uk[1]->set_acceleration(18);
 	cout << "Start speed: " << Point_vec_uk[0]->get_start_speed() << ", acceleration: "
	<< Point_vec_uk[1]->get_acceleration() << endl;

	cout << "Load point? Y/N " << endl; 											//спращиваем у пользователя хочет ли он загрузить поля класса
	cin >> check;
	if ((check =='Y') or (check == 'y'))
	{
		cout << "Enter file name: ";
		string file_name;
		cin >> file_name;
		Point.load_point(Point, file_name); 										//загружаем
		cout << "Start speed: " << Point.get_start_speed() << endl 
		<< "Enter acceleration: " << Point.get_acceleration();
	}

	else
	{
	cout << "Define a moving point" << endl << 
	endl << "Enter start speed: "; 													//просим пользователя ввести начальную скорость точки
	cin >> start_speed;
	Point.set_start_speed(start_speed); 											//вызываем метод класса для считывания начальной скорости

	cout << "Enter acceleration: "; 												//просим пользователя ввести ускорение точки
	cin >> acceleration;
	Point.set_acceleration(acceleration);											//вызываем метод класса для считывания ускорения	
	}										
	check = 'y';
	while ((check == 'y') or (check == 'Y'))
	{
	cout << endl << "What do you want?" << endl << "1 - find distance" 				//узнаём, что пользователь хочет сделать
	<< endl << "2 - find instantaneous speed" << endl << "3 - find average speed" 
	<< endl << "4 - change start speed" << endl << "5 - change acceleration" << endl
	<< "6 - watch start speed and acceleration" << endl << "7 - save"<< endl;
	cin >> i;
	switch(i)	
	{	

	case 1:							
		cout << endl << "How do you want to find the distance?" << endl 
		<< "Using time - T, using speed - S" << endl;
		cin >> check;
		if ((check == 'T') or (check == 't'))
		{
			cout << "Enter time: "; 												//просим пользователя ввести время точки в пути
			cin >> time;
			cout << "Distance: " << Point.find_distanceT(time) << endl;				//вызываем метод класса для рассчёта пути через время
		}
		if ((check == 'S') or (check == 's'))
		{
			cout << "Enter instantaneous speed: "; 									//просим пользователя ввести мгновенную скорость точки
			cin >> speed;
			cout << "Distance: " << Point.find_distanceS(speed) << endl;			//вызываем метод класса для рассчёта пути через скорость
		}
		break;

	case 2:
		cout << "Enter time: "; 													//просим пользователя ввести время точки в пути
		cin >> time;
		cout << "Instantaneous speed: " << Point.find_speed(time) << endl; 			//вызываем метод класса для нахождения мгновенной скорости
		break;

	case 3: 
		cout << "Enter instantaneous speed: "; 										//просим пользователя ввести мгновенную скорость точки
		cin >> speed;
		cout << "Average speed: " << Point.average_speed(speed) << endl;			//вызываем метод класса для нахождения средней скорости
		break;

	case 4:
		cout << "Enter start speed: ";
		cin >> start_speed;
		Point.set_start_speed(start_speed); 										//изменение начальной скорости
		break;

	case 5:
		cout << "Enter acceleration: ";
		cin >> acceleration;
		Point.set_acceleration(acceleration);										//изменение ускорения
		break;

	case 6:
		cout << Point.output_string(); 												//вывод начальной скорости и ускорения
		break;

	case 7:
		cout << "Enter file name: ";
		string file_name;
		cin >> file_name;
		Point.save_point(Point, file_name);

	}
	cout << "Do you want to continue? Y/N" << endl; 								//спрашиваем у пользователя, хочет ли он продолжить программу
	cin >> check;
}
}
