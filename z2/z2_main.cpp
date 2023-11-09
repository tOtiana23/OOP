//Бусыгина Татьяна, ИВТ-22
//https://ivtipm.github.io/Programming/Glava01/index01.htm#z2

#include <iostream> //основная библиотека для ввода/вывода
#include <iomanip> //библиотека для форматирования вывода
#include "mod.h" //подключенный модуль с расчетами
#include <cassert> //библиотека для assert
#include <math.h> //математическая бибилотека

using namespace std;

const float EPS = 10e-4; //10^(-4)

int main()
{
	assert(abs(calc_z2(10, 7) - 0.042) < EPS); //проверки исправной работы ф-ции
	assert(abs(calc_z2(25, 4) - 0.208) < EPS);
	assert(abs(calc_z2(6, 57) + 0.149) < EPS);

	float x, y; //описание переменных

	cout << "x = "; //запрашиваем значение x
	cin >> x; //считываем введённое значение х

	cout << "y = "; //запрашиваем значение у
	cin >> y; //считываем введённое значение y

	cout << "Result: " << setprecision(2) << calc_z2(x, y); //выводим полученное значение, с помощью setprecision() оставляем два знака после запятой
}

