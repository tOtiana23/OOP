//Бусыгина Татьяна, ИВТ-22
//Класс Видео

#include "Video_class.h"
#include <iostream>
#include<vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	Video video;

	int resolution, format, fps;
	double duration;
	int num_people;

	//ввод полей класса Видео
	cout << "Enter resolution" << endl << "1 - SD, 2 - HD, 3 - FullHD, 4 - UHD_4K, 5 - UHD_8K" << endl;
	cin >> resolution;
	video.set_resolution(static_cast<Video::Resolution>(resolution));

	cout << "Enter format" << endl << "1 - AVI, 2 - WMV, 3 - MP4, 4 - MOV" << endl; 
	cin >> format;
	video.set_format(static_cast<Video::Format>(format));

	cout << "Enter duration (seconds): ";
	cin >> duration;
	video.set_duration(duration);

	cout << endl << "Enter fps: ";
	cin >> fps;
	video.set_fps(fps);
	cout << video.output_string();

	//добавление людей
	cout << endl << "How many people do you want to add? ";
	cin >> num_people;
	Person person;
	vector<Person*> people;
	string first_name, middle_name, last_name;
	string job_title;
	for (int i = 0; i < num_people; i++){
		Person* person = new Person();
		cout << endl << "Enter first name " << i+1 << endl;
		cin >> first_name;
		cout << endl << "Enter middle name " << i+1 << endl;
		cin >> middle_name;
		cout << endl << "Enter last name " << i+1 << endl;
		cin >> last_name;
		cout << endl << "Enter job title " << endl;
		cin >> job_title;
		person->set_first_name(first_name);
		person->set_middle_name(middle_name);
		person->set_last_name(last_name);
		person->set_job_title(job_title);
		people.push_back(person);}

	//вывод полученного списка людей
	cout << endl << "List of people" << endl;
	for (const auto &person: people) {
    	cout << endl << person->output_string() << endl; }


	//удаление человека из списка и вывод нового списка
	string name_to_delete;
    cout << "Enter the last name of the person you want to delete: " << endl;
    cin >> name_to_delete;
    person.del_person(people, name_to_delete);
    cout << "Person " << name_to_delete << " has been deleted." << endl;
 	cout << endl << "New list of people" << endl;
  	for (const auto &person: people) {
    	cout << person->output_string() << endl; }


    //изменение данных о человеке и вывод изменённого списка
    cout << "Enter the last name of the person you want to update: ";
    cin >> last_name;

    for (auto &person : people) {
        if (person->get_last_name() == last_name) {
            int choice;
            string new_info;

            cout << "What information would you like to update for " << last_name << "?" << endl;
            cout << "1. First name" << endl;
            cout << "2. Middle name" << endl;
            cout << "3. Last name" << endl;
            cout << "4. Job title" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter new first name: ";
                    cin >> new_info;
                    person->set_first_name(new_info);
                    break;
                case 2:
                    cout << "Enter new middle name: ";
                    cin >> new_info;
                    person->set_middle_name(new_info);
                    break;
                case 3:
                    cout << "Enter new last name: ";
                    cin >> new_info;
                    person->set_last_name(new_info);
                    break;
                case 4:
                    cout << "Enter new job title: ";
                    cin >> new_info;
                    person->set_job_title(new_info);
                    break;
                default:
                    cout << "Invalid choice" << endl;
            }
        }
    }
	for (const auto &person: people) {
    	cout << person->output_string() << endl; }

    for (const auto &person: people) {
    	delete person; }

 	Film film;
 	string called, genre;
    cout << endl << "Enter name of film" << endl;
    cin >> called;
    film.set_called(called);
    cout << endl <<"Enter genre of film" << endl;
    cin >> genre;
    film.set_genre(genre);
    cout << endl << film.output_string() << endl;

 	
 	string called, genre;
 	int number_series, number_episodes;
 	cout << endl <<"Enter name of series " << endl;
 	cin >> called;
 	series.set_called(called);
	cout << endl << "Enter genre of series" << endl;
	cin >> genre;
	series.set_genre(genre);
	cout << endl << "Enter number of seasons" << endl;
	cin >> number_series;
	series.set_seasons(number_series);
	cout << endl << "Enter number of episodes" << endl;
	cin >> number_episodes;
	series.set_episodes(number_episodes);

	cout << endl << series.output_string() << endl;

}


