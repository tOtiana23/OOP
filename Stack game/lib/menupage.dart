//Бусыгина Татьяна, ИВТ-22

import 'package:flutter/material.dart';
import 'homepage.dart';

///Класс MenuPage, который является виджетом с изменяемым состоянием (stateful widget)
class MenuPage extends StatefulWidget {
  @override
  _MenuPageState createState() => _MenuPageState();
}

///Главное меню
class _MenuPageState extends State<MenuPage> {
  int timerInterval = 250;
  @override
  Widget build(BuildContext context) {
    return Scaffold( //виджет для создания базовой структуры экрана
      backgroundColor: Colors.grey[800],
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [

            Text(
              'Stack game',
              style: TextStyle(
                color: Colors.white,
                fontSize: 40,
                fontWeight: FontWeight.bold,
              ),
            ),

            SizedBox(height: 20), //промежуток между заголовком и кнопками

            Image.asset( //картинка
              'assets/icons8-кубики-64.png',
              width: 100,
              height: 100,
              fit: BoxFit.contain, //сохраняет пропорции картинки
            ),

            SizedBox(height: 50), // Промежуток между заголовком и кнопками
            
            ElevatedButton( //кнопка раз
                style: ElevatedButton.styleFrom(
                  foregroundColor: Colors.white,
                  backgroundColor: Colors.grey[900],
                  minimumSize: Size(300, 50),
                ),
                onPressed: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                        builder: (context) =>
                            HomePage(timer: timerInterval)),
                  );
                },
                child: Text(
                  'Start',
                  style: TextStyle(
                    color: Colors.white,
                    fontSize: 20,
                  ),
                ),
              ),

            SizedBox(height: 30), // промежуток между кнопками

            ElevatedButton( //кнопка два
                style: ElevatedButton.styleFrom(
                  foregroundColor: Colors.white,
                  backgroundColor: Colors.grey[900],
                  minimumSize: Size(300, 50),
                ),
                onPressed: () {
                  _showDifficultyDialog(context);
                },
                child: Text(
                  'Game difficulty',
                  style: TextStyle(
                    color: Colors.white,
                    fontSize: 20,
                  ),
                ),
            ),
          ],
        ),
      ),
    );
  }

  ///Окошко для выбора сложности игры
  void _showDifficultyDialog(BuildContext context) {
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          title: Text('Select game difficulty'),
          content: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              TextButton(
                onPressed: () {
                  timerInterval = 450; //Легкий
                  Navigator.of(context).pop();
                },
                child: Text(
                  'Easy',
                  style: TextStyle(
                    color: Colors.black,
                    fontSize: 18, // Размер текста
                  ),
                ),
              ),
              TextButton(
                onPressed: () {
                  timerInterval = 250; //Средний
                  Navigator.of(context).pop();
                },
                child: Text(
                  'Medium',
                  style: TextStyle(
                    color: Colors.black,
                    fontSize: 18, // Размер текста
                  ),
                ),
              ),
              TextButton(
                onPressed: () {
                  timerInterval = 50; //Сложный
                  Navigator.of(context).pop();
                },
                child: Text(
                  'Hard',
                  style: TextStyle(
                    color: Colors.black,
                    fontSize: 18, // Размер текста
                  ),
                ),
              ),
            ],
          ),
        );
      },
    );
  }
}
