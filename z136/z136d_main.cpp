//Бусыгина Татьяна, ИВТ-22
//Задача 136д: https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <iostream> 	//основная библиотека для ввода/вывода
#include <time.h> 		//время для рандомных элементов массива
#include <math.h> 		//математическая бибилотека
#include <fstream> 		//библиотека для работы с файлами   
#include <cassert>		//библиотека для assert
#include <exception>	//библиотека для обработки исключений
#include "z136d_mod.h" 	//подключенный модуль
#include <vector> 		//библиотека для массивов

using namespace std; 	//пространство

using namespace arrays;


int main(int argc, char *argv[])
{
	string carg, file_name; 											//имя файла

	srand(time(0)); 													//устанавливает в качестве базы текущее время для того, чтобы при разных запусках у генератора псевдослучайных чисел была разная база

	int size_mas; 														//переменная для хранения размера массива
	float up_limit, down_limit;											//переменные для хранения вверхней и нижней границы массива	
	char check;															//переменная для считывания ответа пользователя							

	unsigned size_test = 3;												//размер массивов для проверки

	vector<float> test = {5, 5, 6};										//создаем массив
	assert(sum_sq(test) == 86);											//проводим проверку
	test.clear();														//очищаем массив

	test = {4, 8, 9};													//задаём массиву новые значения
	assert(sum_sq(test) == 161);										//проводим проверку
	test.clear();														//очищаем массив

	test = {6, 2, 3};													//задаём массиву новые значения
	assert(sum_sq(test) == 49);											//проводим проверку
	test.clear();


	if (argc > 1) 														//если в командной строке есть какие-то аргументы
	{
		carg = argv[1];
		if (carg == "load") 											//если пользователь хочет загрузить массив из файла
		{
			file_name = argv[2]; 										//считываем имя файла в переменную file_name
			cout << "Entered name of file: " << file_name << endl;
			size_mas = array_size_from_file(file_name); 				//узнаём размера массива в файле
			try
			{
				unsigned size = array_size_from_file(file_name); 		//ошибка, если такого файла нет
			}
			catch(const exception& error)
			{
				cout << error.what();
			}
			vector<float> mass; 										//дин массив, пустой							
			mass.resize(size_mas);										//выделяем память под заданное кол-во элементов
			array_from_file(mass, size_mas, file_name);					//считываем массив из файла
			print_mas(mass); 											//ф-ция вывода массива на экран
			cout << endl << "Result: " << sum_sq(mass);					//выводим результат
			mass.clear();												//очищаем массив			
		}

		if (carg == "create") 											//если пользователь хочет создать новый массив
		{
			size_mas = stoul(argv[2]); 									//считываем размер массива в переменную size_mas									
			up_limit = stoul(argv[3]);									//считываем верхнюю границу массива в переменную up_limit
            down_limit = stoul(argv[4]);								//считываем нижнюю границу массива в переменную down_limit

            cout << "Entered size of array: "<< size_mas <<endl; 		//выводим значения, которые пользователь ввёл в командную строку
            cout << "Entered up limit: " << up_limit << endl;
            cout << "Entered down limit: " << down_limit << endl;

            vector<float> mass; 										//дин массив, пустой
			mass.resize(size_mas);										//выделяем память под заданное кол-во элементов
			fill_mas(mass, up_limit, down_limit);						//ф-ция заполнения массива случайными числами
			cout << "Array: ";
			print_mas <float> (mass); 									//ф-ция вывода массива на экран
			cout << endl<< "Result: " << sum_sq(mass) << endl;	
			if (argc == 6) 												//если аргументов в строке 6, значит польователь ввёл название файла и хочет сохранить массив
			{
            	file_name = argv[5];									//считываем имя файла в переменную file_name
            	array_to_file(mass, file_name); 						//вывод массива в текстовый файл
				cout << "Array saved" << endl;
			}
			mass.clear();												//очищаем массив
		}
	}
	else
	{
		cout << "Create a new array?" << endl;							//запрашиваем у пользователя нужно ли создавать новый массив
		cin >> check;
		if ((check == 'Y') or (check == 'y'))
		{
			cout << "Print size mas" << endl;							//запрашиваем у пользователя размер массива
			cin >> size_mas;
			while (size_mas < 0)										//проверяем, что размер массива больше 0
			{
				cout << "Print size array > 0 "<< endl; 				//если размер массива меньше 0, то выводим ошибку
				cin >> size_mas;										//просим ввести значение заново
			}
			cout << "Print up limit: " << endl;							//запрашиваем у пользователя верхнюю границу массива
			cin >> up_limit;
			cout << "Print down limit: " << endl;						//запрашиваем у пользователя нижнюю границу массива
			cin >> down_limit;
			vector<float> mass; 										//дин массив, пустой
			mass.resize(size_mas);										//выделяем память под заданное кол-во элементов
			fill_mas(mass, up_limit, down_limit);						//ф-ция заполнения массива случайными числами
			cout << "Array: ";
			print_mas <float> (mass); 									//ф-ция вывода массива на экран
			cout << endl<< "Result: " << sum_sq(mass) << endl;			//выводим результат
			cout << "Save array?" << endl;								//запрашиваем у пользователя нужно ли сохранить массив
			cin >> check;
			if ((check == 'Y') or (check == 'y'))
			{
				cout << "Print name file" << endl; 						//запрашиваем у пользователя имя файла
				cin >> file_name;
				array_to_file(mass, file_name); 						//вывод массива в текстовый файл
				cout << "Array saved" << endl;	
			}
			mass.clear();												//очищаем память
		}									
		else
		{
			cout << "Print name file" << endl; 							//запрашиваем у пользователя имя файла
			cin >> file_name;
			size_mas = array_size_from_file(file_name); 				//узнаём размера массива в файле
			try
			{
				unsigned size = array_size_from_file(file_name);
			}
			catch(const exception& error)
			{
				cout << error.what();
			}
			vector<float> mass; 										//дин массив, пустой							
			mass.resize(size_mas);										//выделяем память под заданное кол-во элементов
			array_from_file(mass, size_mas, file_name);					//считываем массив из файла
			print_mas(mass); 											//ф-ция вывода массива на экран
			cout << endl << "Result: " << sum_sq(mass);					//выводим результат
			mass.clear();												//очищаем память
		}
	}
}
