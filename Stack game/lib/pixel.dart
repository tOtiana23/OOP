//Бусыгина Татьяна, ИВТ-22

import 'package:flutter/material.dart'; 

//Класс пиксель, наследуется от StatelessWidget
//В Flutter, StatelessWidget - это один из основных видов виджетов, которые не имеют внутреннего состояния (state).
//Виджеты без состояния являются неизменяемыми и просто отображают пользовательский интерфейс на основе переданных им данных и параметров
class MyPixel extends StatelessWidget {

final color; 

MyPixel({this.color}); //конструктор, который принимает параметр цвета

  @override
  Widget build(BuildContext context) {//переопределение метода build, который возвращает виджет
    return Padding( //виджет Padding добавляет отступы от дочернего виджета
      padding: const EdgeInsets.all(2.0), //отступ 2.0 со всех сторон, измеряется в логических пикселях
      //В Flutter, логические пиксели являются абстрактными единицами измерения, которые масштабируются в соответствии с 
      //разрешением экрана устройства и настройками масштабирования пользователя. Это позволяет обеспечить согласованный и 
      //адаптивный размер элементов интерфейса на разных устройствах.
      //Значение 2.0 в EdgeInsets.all(2.0) означает, что отступ будет равен 2 логическим пикселям со 
      //всех сторон (сверху, снизу, справа и слева) от дочернего виджета ClipRRect.
        child: ClipRRect( //виджет ClipRRect обрезает дочерний элемент по заданной форме
          borderRadius: BorderRadius.circular(6), //скругляем углы радиусом 6 (тоже в логических пикселях)
            child: Container( //виджет Container - прямоугольная область для отображения контента
                      color: color, //цвет передаётся в качестве параметра
                    ),
                  ),
                );
  }
}