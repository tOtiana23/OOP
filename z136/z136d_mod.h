//Бусыгина Татьяна, ИВТ-22
//Задача 136д: https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#ifndef Z136D_MOD_H
#define Z136D_MOD_H
#include <string>
#include <vector> 	//библиотека для массивов
#include <iomanip> 
using namespace std;//пространство имён

namespace arrays
{


///Заполнение массива mas случайными числами, up_limit и down_limit - верхняя и нихняя границы массива
template < typename El1>
void fill_mas(vector<El1> &mas, float up_limit, float down_limit)
{
    int range = up_limit - down_limit;                         //диапазон рандома
	for(unsigned i = 0; i < mas.size(); i ++) 
	{		
        mas[i]=(float)rand()/RAND_MAX*range +down_limit;    //RAND_MAX константа для определения диапазона
	}
}


///Вывод массива на экран mas - массив
template < typename El>
void print_mas(vector<El> &mas)
{
	for(unsigned i = 0; i < mas.size(); i++)
	{
		cout << setprecision(4) << mas[i] << " "; 				//выводим элементы через пробел
	}
}

///Сумма квадратов элементов массива mas
float sum_sq(vector<float> &mas);

///Вывод массива mas в текстовый файл file_name 
void array_to_file(vector<float> &mas, const string &file_name);

///Поиск кол-ва элементов массива в файле file_name
unsigned array_size_from_file(const string &file_name);

///Загружаем массив mas из файла file_name, size_mas размер массива
void array_from_file(vector<float> &mas, unsigned size_mas, const string &file_name);

///Загружаем массив в бинарный файл
void array_to_bin_file(vector<float> &mas, const string& file_name);

///Загружаем массив из бинарного файла
void array_from_bin_file(vector<float> &mas, unsigned size_mas, const string& file_name);
}

#endif