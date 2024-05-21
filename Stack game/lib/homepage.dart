//Бусыгина Татьяна, ИВТ-22

import 'package:flutter/material.dart'; //импорт библиотеки Material Design из пакета Flutter. 
//Эта строка кода необходима для использования виджетов и других компонентов библиотеки Material Design в приложении Flutter
import 'menupage.dart';
import 'button.dart';
import 'game_controller.dart';
import 'pixel.dart';

///Класс HomePage, который является виджетом с изменяемым состоянием (stateful widget)
class HomePage extends StatefulWidget {

  final int timer; //final используется для объявления финальных (неизменяемых) переменных или свойств

  HomePage({ //конструктор
    super.key, //вызов конструктора родительского класса (если он существует) и передача ему параметра key. В данном случае, если родительский класс 
    //не определен явно, то вызывается конструктор по умолчанию базового класса StatefulWidget.
    required this.timer, //параметр, отвечающий за время обновления таймера
  });

  @override
  _HomePageState createState() => _HomePageState(); //createState() - метод, который создает и возвращает объект состояния для данного виджета
  //стрелочная нотация используется для возврата нового экземпляра класса _HomePageState
}

//Интерфейс игры
//Эта строка определяет класс _HomePageState, который расширяет класс State и связан с классом HomePage.
//Класс _HomePageState представляет состояние виджета HomePage
class _HomePageState extends State<HomePage> {

  late GameController stackGame; //late означает, что нужно инициализировать эту переменную до того, как она будет использована, 
  //но можно это сделать позже, после объявления переменной

  //Метод initState() является одним из методов жизненного цикла виджета во фреймворке Flutter. Когда виджет создается, 
  //Flutter вызывает метод createState() для создания объекта состояния виджета, и затем вызывает метод initState() на этом объекте состояния.
  //В методе initState() обычно выполняются операции инициализации, которые требуются для начального состояния виджета. 
  //Этот метод вызывается только один раз при создании состояния виджета
  @override
  void initState() {
    //Вызов super.initState() позволяет фреймворку Flutter выполнить все необходимые действия инициализации для 
    //родительского класса State, прежде добавления собственной логику инициализации. Также обеспечивает корректное 
    //наследование и цепочку вызовов методов инициализации в дереве виджетов
    super.initState();
    stackGame = GameController( //создаём экземпляр класса
        difficulty: widget.timer,
        numberOfSquares: 160,
        setStateFunction: () { //функция обновления состояния виджета, которая вызывается при необходимости обновления 
        //пользовательского интерфейса. В данном случае, она вызывает метод setState(() {}), что приводит к перерисовке виджета
          setState(() {}); //setState - это метод, который используется для уведомления фреймворка об изменениях внутреннего состояния 
          //(state) виджета и перерисовки виджета с обновленным состоянием
        },
        gameoverCallback: _showDialog); //функция обратного вызова, которая будет вызвана в случае окончания игры
  }

  ///Показываем окошко, когда проиграли или выйграли, title - то, что будет написано в окошке (заголовок)
  void _showDialog(String title) {
  showDialog( //showDialog является функцией, которая отображает диалоговое окно
    context: context, //контекст, в котором будет отображаться диалоговое окно
    barrierDismissible: false, //чтоб окошко не закрывалось при нажатии на экран
    builder: (BuildContext context) { 
      return AlertDialog( //создание виджета AlertDialog (диалогового окна)
        title: Center( //по центру заголовок, который передаётся как параметр
          child: Text(
            title,
            style: TextStyle(fontSize: 35),
          ),
        ),
        actions: [ //actions принимает список виджетов, которые будут отображаться в нижней части диалогового окна
          Row( //кнопочки буду располагаться горизонтально
            mainAxisAlignment: MainAxisAlignment.center, //выравнивание кнопок по центру
            children: [
              TextButton( //кнопка раз
                style: TextButton.styleFrom(
                  foregroundColor: Colors.black,
                  textStyle: TextStyle(fontSize: 18),
                ),
                onPressed: () {
                  Navigator.of(context).pop(); //закрытие диалогового окна
                  stackGame.startGame(); //запуск игры заново
                },
                child: Text('Restart'),
              ),

              SizedBox(width: 20), // Промежуток между кнопками

              TextButton( //кнопка два
                style: TextButton.styleFrom(
                  foregroundColor: Colors.black,
                  textStyle: TextStyle(fontSize: 18),
                ),
                onPressed: () {
                  Navigator.of(context).pop(); 
                  Navigator.push(
                    context,
                    MaterialPageRoute(builder: (context) => MenuPage()), //переходим на страничку главного меню
                  );
                },
                child: Text('Main menu'),
              ),
            ],
          ),
        ],
      );
    },
  );
}

List<Color> pixelColors = List.filled(10 * 16, Colors.transparent);
///Градиентно красим пиксели
Color getPixelColor(int index) {
  //сначала красим в прозрачный
  if (pixelColors[index] != Colors.transparent) {
    return pixelColors[index];
  }

  int col = 137;

  //теперь каждый уровень красим в цвет от синего к розовому
  if (stackGame.landed.contains(index)) {
    for (int i = 0; i < stackGame.level; i++) {
      col = (255 * (stackGame.level - 1) / 15).floor();
    }
    pixelColors[index] = Color.fromARGB(255, col, 50, 183);
    return pixelColors[index];
  }
  return Colors.transparent;
}

//переопределение метода build для построения виджета
@override
Widget build(BuildContext context) {
  return Scaffold( //создание основного виджета Scaffold
  //Виджет Scaffold в Flutter представляет собой основной структурный виджет для построения мобильных приложений. 
  //Он обеспечивает основной каркас приложения, включая апп-бар, боковое меню (если необходимо), нижнюю панель навигации
  //и другие элементы интерфейса
    backgroundColor: Colors.grey[800], //цвет
    //создание столбца виджетов
    body: Column(
      children: [   
        //виджет Expanded используется для расширения дочернего виджета настолько, насколько это возможно в соответствии с 
        //родительским виджетом
        Expanded(
          //Свойство flex в виджете Expanded определяет, какую часть доступного пространства должен занимать дочерний виджет по 
          //сравнению с другими дочерними виджетами в родительском виджете. flex: 5, что означает, что этот дочерний виджет будет 
          //занимать больше доступного пространства по сравнению с другими дочерними виджетами с меньшим значением flex
          flex: 5,     
          //cоздание сетки с указанным количеством квадратов, приставка builder обозначает то что GridView создаётся динамически
          child: GridView.builder(
              itemCount: stackGame.numberOfSquares,  //itemCount указывает количество элементов, которые должны быть отображены в 
              //GridView.builder. В данном случае, stackGame.numberOfSquares определяет общее количество квадратов в игре, которые 
              //необходимо отобразить
              
              //gridDelegate определяет, как должны располагаться элементы в сетке GridView.builder. В этом случае используется 
              //SliverGridDelegateWithFixedCrossAxisCount, который создает сетку с фиксированным количеством элементов в каждой строке.
              //crossAxisCount: 10 означает, что в каждой строке сетки будет расположено 10 элементов (квадратов)
              gridDelegate: SliverGridDelegateWithFixedCrossAxisCount( 
                  crossAxisCount: GameController.row),
              itemBuilder: (BuildContext context, int index) { //itemBuilder колбэк-функция, которая вызывается для построения каждого элемента сетки
              //параметры функции BuildContext предоставляет информацию о местоположении виджета в дереве виджетов, а index - индекс 
              //текущего элемента, который нужно построить
              
              //здесь определяется внешний вид каждой ячейки 

              //проверяем, содержит ли piece индекс
                if (stackGame.piece.contains(index)) {
                  //если да, то это наша штучка, которая бегает, красим её в белый
                  return MyPixel(
                    color: Colors.white,
                  );

                  //если это кусочек, который приземлился, то он цветной
                } else if (stackGame.landed.contains(index)) {
                  return MyPixel(
                    color:  getPixelColor(index), //задаём цвет в зависимости от индекса, делаем градиент
                  );

                  //иначе это поле игры, оно чёрное
                } else {
                  return MyPixel(
                    color: Colors.black,
                  );
                }
              }),
        ),

        //виджет для расположения кнопочек
        Expanded(
          //контейнер для кнопок
          child: Container(     
            //создание строки с кнопками
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                //кнопка "PLAY" для запуска игры
                MyButton(
                 function: stackGame.startGame, //ф-ция, которая будет вызываться при нажатии
                  child: Text(
                    'P L A Y',
                    style: TextStyle(color: Colors.white, fontSize: 30),
                  ),
                ),
                //кнопка "STOP" для создания стопки
                MyButton(
                  function: stackGame.stack, //ф-ция, которая будет вызываться при нажатии
                  child: Text(
                    'S T O P',
                    style: TextStyle(color: Colors.white, fontSize: 30),
                  ),
                )
              ],
            ),
          ),
        )
      ],
    ),
  );
}
}
