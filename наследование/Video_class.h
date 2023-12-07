//Бусыгина Татьяна, ИВТ-22
//Класс Видео



//todo: конструкторы с параметрами

#ifndef VIDEO_CLASS_H
#define VIDEO_CLASS_H
#include <string>
#include <vector>

//Видео
class Video{

public:
	enum Format{AVI, WMV, MP4, MOV};
	enum Resolution{SD, HD, FullHD, UHD_4K, UHD_8K};

protected:
	//поля класса
	double duration; //продолжительность
	Format format;
	int fps;//частота кадров в секунду
	Resolution resolution;

public:

	//конструктор
	Video();
	///конструктор с параметрами
	Video(double duration1, int fps1, Format format, Resolution resolution);

	///геттер для продолжительности
	double get_duration() const;
	///геттер для формата
	Format get_format() const;
	///геттер для частоты кадров в секунду
	int get_fps() const;
	///геттер для разрешения
	Resolution get_resolution() const;
	///сеттер для продолжительности
	void set_duration(double duration1);
	///сеттер для формата
	void set_format(Format f);
	///сеттер для частоты кадров в секунду
	void set_fps(int fps1);
	///сеттер для разрешения
	void set_resolution(Resolution r);
	///вывод полей класса видео
	virtual std::string output_string() = 0;
};

//Класс человек
class Person{
protected:
	//поля класса
	std::string job_title; //профессия
	std::string first_name; //имя
	std::string last_name; //фамилия
	std::string middle_name; //отчество

public:
	///конструктор
	Person();
	///конструктор c параметрами
	Person(const std::string &job_title1, const std::string &first_name1, 
	const std::string &middle_name1, const std::string &last_name1);
	///сеттер профессии
	void set_job_title(const std::string &job_title1);
	///сеттер имени
	void set_first_name(const std::string &first_name1);
	///сеттер отчества
	void set_middle_name(const std::string &middle_name1);
	///сеттер фамилии
	void set_last_name(const std::string &last_name1);
	///геттер профессии
	std::string get_job_title() const;
	///геттер имени
	std::string get_first_name() const;
	///геттер отчества
	std::string get_middle_name() const;
	///геттер фамилии
	std::string get_last_name() const;
	///удаление человека из массива
	void del_person(std::vector<Person*>& people, const std::string &name_to_delete);
	///вывод фио и должности
	std::string output_string();


};

//Класс фильмы
class Film: public Video{
protected:
	//поля класса
	std::string called; //название фильма
	std::string genre; //жанр фильма
	Person person; //композиция 
public:
	///конструктор
	Film();
	Film(const std::string &job_title1, const std::string &first_name1, const std::string &middle_name1, 
	const std::string &last_name1, const std::string &called1, const std::string &genre1);
	///сеттер названия
	void set_called(const std::string &called);
	///геттер названия
	std::string get_called() const;
	///сеттер жанра
	void set_genre(const std::string &genre);
	///геттер жанра
	std::string get_genre() const;
	///вывод названия фильма и его жанра
	std::string output_string() override;
	///генерация рейтинга фильма
	double rating();
};

//Класс сериалы
class Series: public Film{
private:
	//поля класса
	int episodes; //кол-во серий в сезоне
	int seasons; //кол-во сезонов
public:
	///конструктор
	Series();
	//конструктор с параметрами
	Series(int seasons1, int episodes1);
	///сеттер кол-ва серий
	void set_seasons(int seasons1);
	///сеттер кол-во сезонов
	void set_episodes(int episodes1);
	///геттер кол-ва серий
	int get_seasons() const;
	///геттер кол-ва эпизодов
	int get_episodes() const;
	///общее кол-во серий
	int total_episodes() const;
	///вывод данных о сериале
	std::string output_string() override;
};
#endif