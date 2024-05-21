//Бусыгина Татьяна, ИВТ-22

import 'package:flutter/material.dart';

///Класс кнопопчки, наследуется от StatelessWidget
class MyButton extends StatelessWidget {

  final child; //финальная переменная для хранения дочернего виджета
  final function; //финальная переменная для хранения функции, которая вызывается при нажатии

  MyButton({this.child, this.function});

  @override
  Widget build(BuildContext context) { //переопределение метода build, который возвращает виджет
    return GestureDetector( //возвращаем виджет GestureDetector для обработки жестов пользователя
      onTap: function, //функция, вызываемая при нажатии - переданный параметр
      child: Padding( //добавляем отступ
        padding: const EdgeInsets.all(4.0), //отступ в 4 пикселя, EdgeInsets.all - задаёт одинаковые отступы со всех сторон
        child: ClipRRect( //скругляем углы
          borderRadius: BorderRadius.circular(10), //скругление радиусом 10 пикселей
          child: Container( //виджет Container - прямоугольная область
            padding: EdgeInsets.all(40),//ещё отступ в 40 пикселей
            color: Colors.grey[900], //красим в серый, Colors.grey[900] обращается к списку оттенков серого цвета и 
            //выбирает оттенок с индексом 900, который является самым темным оттенком серого цвета
            child: Center(child: child) //по центру дочерний виджет
          ),
        ),
      ),
    );
  }
}
