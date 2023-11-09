//Бусыгина Татьяна, ИВТ-22
//Класс движущаяся точка
#include "Class_MovingPoint.h"
#include <iostream>

using namespace std;

int main()
{
	MovingPoint Point; 																//Point экземпляр класса MovingPoint
	double time, StartSpeed, acceleration, speed;
	char check, check1;
	check1 = 'y';
	int i;

	cout << "Define a moving point" << endl << 
	endl << "Enter start speed: "; 													//просим пользователя ввести начальную скорость точки
	cin >> StartSpeed;
	Point.set_StartSpeed(StartSpeed); 												//вызываем метод класса для считывания начальной скорости

	cout << "Enter acceleration: "; 												//просим пользователя ввести ускорение точки
	cin >> acceleration;
	Point.set_acceleration(acceleration);											//вызываем метод класса для считывания ускорения

	while ((check1 == 'y') or (check1 == 'Y'))
	{
	cout << endl << "What do you want?" << endl << "1 - find distance" 				//узнаём, что пользователь хочет сделать
	<< endl << "2 - find instantaneous speed" << endl << "3 - find average speed" << endl
	<< "4 - watch start speed" << endl << "5 - watch acceleration" <<  endl;
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
		cout << "Start speed: " << Point.get_StartSpeed() << endl;					//выводим значение начальной скорости
		cout << "Do you want change start speed? Y/N"<< endl;						//узнаём у пользователя, нужно ли изменить значение
		cin >> check;
		if ((check == 'y') or (check == 'Y'))
		{
			cout << "Enter start speed: ";
			cin >> StartSpeed;
			Point.set_StartSpeed(StartSpeed); 										//изменение начальной скорости
			
		}
		break;

	case 5:
		cout << "Acceleration: " << Point.get_acceleration() << endl; 				//выводим значение ускорения
		cout << "Do you want change acceleration? Y/N"<< endl; 						//узнаём у пользователя, нужно ли изменить значение
		cin >> check;
		if ((check == 'y') or (check == 'Y'))
		{
			cout << "Enter acceleration: ";
			cin >> acceleration;
			Point.set_acceleration(acceleration);									//изменение ускорения
			
		}
		break;

	}
	cout << "Do you want to continue? Y/N" << endl; 								//спрашиваем у пользователя, хочет ли он продолжить программу
	cin >> check1;
}
}
