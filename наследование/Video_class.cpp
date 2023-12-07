//Бусыгина Татьяна, ИВТ-22
//Класс Видео

#define _USE_MATH_DEFINES
#include "Video_class.h"
#include <vector>
#include <iostream>
#include <ctime>

///конструктор
Video::Video(){
	duration = 0;
	Format f;
	fps = 0;
	Resolution r;}

///конструктор с параметрами
Video::Video(double duration1, int fps1, Format format, Resolution resolution){
	set_duration(duration1); set_fps(fps1); set_format(format); set_resolution(resolution);}

///геттер для продолжительности
double Video::get_duration() const{
	return duration;}

///геттер для формата
Video::Format Video::get_format() const{
	return format;}

///геттер для частоты кадров в секунду
int Video::get_fps() const{
	return fps;}

///геттер для разрешения
Video::Resolution Video::get_resolution() const{
	return resolution;}

///сеттер для продолжительности
void Video::set_duration(double duration1){
	duration = duration1;}

///сеттер для формата
void Video::set_format(Format f){
	format =  f;}

///сеттер для частоты кадров в секунду
void Video::set_fps(int fps1){
	fps = fps1;}

///сеттер для разрешения
void Video::set_resolution(Resolution r){
	resolution = r;}

///вывод полей класса видео
std::string Video::output_string(){
	std::string rr = " ";
	const int num_res = 5;
	const std::string res[num_res] = {"SD", "HD", "FullHD", "UHD_4K", "UHD_8K"};
	const int input_r[num_res] = {1, 2, 3, 4, 5};
	for (int i = 0; i < num_res; i++){
		if (get_resolution() == input_r[i]){
			rr = res[i];}}

	std::string ff = " ";
	const int num_format = 4;
	const std::string form[num_format] = {"AVI", "WMV", "MP4", "MOV"};
	const int input_f[num_res] = {1, 2, 3, 4};
	for (int i = 0; i < num_format; i++){
		if (get_format() == input_f[i]){
			ff = form[i];}}

	std::string s = "Duration: " + std::to_string(get_duration()) + "\n" + "Fps: " + std::to_string(get_fps()) 
	+ "\n" + "Resolution: " + rr + "\n" + "Format: " + ff; //вывод всех полей
	return s;}


///конструктор
Person::Person(){
	job_title = ' ';
	first_name = ' ' ;
	middle_name = ' ';
	last_name = ' ';}

///конструктор c параметрами
Person::Person(const std::string &job_title1, const std::string &first_name1, const std::string &middle_name1, const std::string &last_name1){
	set_job_title(job_title1); set_first_name(first_name1), set_middle_name(middle_name1), set_last_name(last_name1);}

///сеттер профессии
void Person::set_job_title(const std::string &job_title1){
	job_title = job_title1;}

///сеттер имени
void Person::set_first_name(const std::string &first_name1){
	first_name = first_name1;}

///сеттер имени
void Person::set_middle_name(const std::string &middle_name1){
	middle_name = middle_name1;}

///сеттер имени
void Person::set_last_name(const std::string &last_name1){
	last_name = last_name1;}

///геттер профессии
std::string Person::get_job_title() const{
	return job_title;}

///геттер имени
std::string Person::get_first_name() const{
	return first_name;}

///геттер отчества
std::string Person::get_middle_name() const{
	return middle_name;}

///геттер фамилии
std::string Person::get_last_name() const{
	return last_name;}

///удаление человека из массива
void Person::del_person(std::vector<Person*>& people, const std::string &name_to_delete){
	for (int i = 0; i < people.size(); i++) {
        if (people[i]->get_last_name() == name_to_delete) {
            delete people[i];
            people.erase(people.begin() + i);}}}

///вывод фио и должности
std::string Person::output_string(){
	std::string s = get_job_title() + " " + get_first_name() + " " + get_middle_name() + " " + get_last_name();
	return s;}


///конструктор
Film::Film(){
	genre = ' ';
	called = ' ';}

///конструктор с параметрами
Film::Film(const std::string &job_title1, const std::string &first_name1, const std::string &middle_name1, 
	const std::string &last_name1, const std::string &called1, const std::string &genre1):
	person(job_title1, first_name1, middle_name1, last_name1){
	set_called(called1); set_genre(genre1);}


///сеттер названия
void Film::set_called(const std::string &called1){
	called = called1;}

///геттер названия
std::string Film::get_called() const{
	return called;}

///сеттер жанра
void Film::set_genre(const std::string &genre1){
	genre = genre1;}

///геттер жанра
std::string Film::get_genre() const{
	return genre;}

///вывод названия фильма и его жанра
std::string Film::output_string(){
	std::string s = "Film " + get_called() + " in the genre of " + get_genre();
	return s;}

///генерация рейтинга фильма
double Film::rating(){
	srand(time(0));
	return ((double)rand() / RAND_MAX * 100)/10;}


//конструктор
Series::Series(){
	seasons = 0;
	episodes = 0;}

//конструктор с параметрами
Series::Series(int seasons1, int episodes1){
	set_seasons(seasons1); set_episodes(episodes1);}

///сеттер кол-ва серий
void Series::set_seasons(int seasons1){
	seasons = seasons1;}

///сеттер кол-во сезонов
void Series::set_episodes(int episodes1){
	episodes = episodes1;}

///геттер кол-ва серий в сезоне
int Series::get_seasons() const{
	return seasons;}

///геттер кол-ва эпизодов
int Series::get_episodes() const{
	return episodes;}

///общее кол-во серий
int Series::total_episodes() const
{
	return get_episodes()*get_seasons();
}

///вывод данных о сериале
std::string Series::output_string(){
	std::string s = "Series '" + get_called() + "' in the genre of " + get_genre() + " have a " + std::to_string(get_seasons()) 
	+ " seasons and " + std::to_string(get_episodes()) + " episodes." + "Total episodes: " + std::to_string(total_episodes()) + "\nRating of this series: " +
	std::to_string(rating());
	return s;}

