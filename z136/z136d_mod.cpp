//Бусыгина Татьяна, ИВТ-22
//Задача 136д: https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <iostream> 	//основная библиотека для ввода/вывода
#include <math.h> 		//математическая бибилотека
#include <fstream> 		//библиотека для работы с файлами   
#include <iomanip>      //библиотека для форматирования вывода
#include <vector>       //библиотека для массивов

using namespace std;    //пространство имён

namespace arrays
{

///Заполнение массива mas случайными числами, up_limit и down_limit - верхняя и нихняя границы массива
void fill_mas(vector<float> &mas, float up_limit, float down_limit)
{
    int range = up_limit - down_limit;                         //диапазон рандома
	for(unsigned i = 0; i < mas.size(); i ++) 
	{		
        mas[i]=(float)rand()/RAND_MAX*range +down_limit;    //RAND_MAX константа для определения диапазона
	}
}


///Сумма квадратов элементов массива mas
float sum_sq(vector<float> &mas)
{
	float res = 0;
	for(unsigned i = 0; i < mas.size(); i ++) 
	{
		res += pow(mas[i], 2); 								     //находим сумму квадратов элементов массива
	}
	return res;
}

///Вывод массива mas в текстовый файл file_name 
void array_to_file(vector<float> &mas, const string &file_name)
{
	ofstream file(file_name); 								     //открытие файла
	if (!file.is_open())                                	     //если файл не открыт, то выводим ошибку
    {
        throw runtime_error("File not found");       
    }
    for (unsigned i=0; i < mas.size(); i++)                     
    {
    	file << mas[i] << endl; 			                     //выводим по одному элементу в строку
    }
}

///Поиск кол-ва элементов массива в файле file_name
unsigned array_size_from_file(const string &file_name)
{
	unsigned res = 0;                                   	     //переменная для счета кол-ва строк
    string line;                                        	     //строка, с помощью которой ищем кол-во строк
    ifstream file(file_name);                           	     //открытие файла 
    if (!file.is_open())                                	     //если файл не открыт, то выводим ошибку
    {
        throw runtime_error("File not found");        		
    }
    while (getline(file, line))                         	     //считаем кол-во строк = кол-ва элементов массива
    {
        res++;                                      	
    }

    file.close();                                       	     //закрываем файл
    return res;
}

///Загружаем массив mas из файла file_name, size_mas размер массива
void array_from_file(vector<float> &mas, unsigned size_mas, const string &file_name)
{
    ifstream file(file_name);                           	     //открытие файла 
    if (!file.is_open())                                	     //если файл не открыт, то выводим ошибку
    {
        throw runtime_error("File not found");     
    }
    for (unsigned i = 0; i < size_mas; i++)                	  //цикл для чтения массива из файла
    {
        file >> mas[i];                                 	     //записываем построчно числа в массив
    }
}

}