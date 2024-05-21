//Бусыгина Татьяна, ИВТ-22

import 'package:flutter/material.dart';
import 'menupage.dart';

void main() {
  runApp(MyApp()); //функция, которая запускает приложение и передает экземпляр класса MyApp в качестве корневого виджета
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: MenuPage(), // Указываем, что домашней страницей будет MenuPage
    );
  }
}



