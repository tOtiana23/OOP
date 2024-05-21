//Бусыгина Татьяна, ИВТ-22

import 'dart:async'; //предоставляет классы и функции для работы с асинхронным программированием

///Класс контролер игры
class GameController {
  //хранятся номера ячеек
  List<int> piece = []; //движущиеся кусочки
  List<int> landed = [10000]; //приземлённые кусочки

  // _ перед именем переменной означает, что переменная является приватной и доступна только внутри файла
  var _direction = "left"; //направление
  int level = 0; //уровень
  int _removedSqr = 0; //кол-во удалённых квадратиков
  int difficulty = 250;
  int numberOfSquares = 160;
  static const int row = 10; //Объявление статической константы
   //- static const переменная является статической, то есть принадлежит классу, а не отдельным экземплярам
   //- const означает, что значение этой переменной должно быть известно во время компиляции и будет неизменным
   //- Статические константы могут быть полезны для хранения общих значений, которые не должны изменяться для всего класса

  //Callback function (функция обратного вызова) - это функция, которая передается в качестве аргумента в другую функцию 
  //и вызывается внутри этой функции в определенный момент времени или при наступлении определенного события

  ///CallBack функции первая для обновления состояния виджета
  Function setStateFunction;

  ///Вторая для показа окна о проигрыше
  void Function(String) gameoverCallback;

  ///Конструктор с параметрами
  GameController({
    required this.difficulty,
    required this.setStateFunction, //required используется для указания того, что параметр должен быть обязательно передан при создании экземпляра класса
    required this.gameoverCallback,
    required this.numberOfSquares,
  });

  void startGame() {
    //задаём значения переменным
    landed = [10000];
    _removedSqr = 0;
    level = 0;
    _direction = "left";

    //на нулевом уровне 3 кусочка бегают
    if (level == 0) {
      piece = [
        numberOfSquares - 3 - level * row,
        numberOfSquares - 2 - level * row,
        numberOfSquares - 1 - level * row
      ];
    }

    //таймер, котой проверяет код ниже каждые сколько-то милесекунд
    Timer.periodic(Duration(milliseconds: difficulty), (timer) {

      //если выйграли, то показываем соответствующее окно и останавливаем таймер
      if (_checkWinner()) {
        gameoverCallback.call('Winner');
        timer.cancel();
      }

      //если проиграли, то показываем соответствующее окно и останавливаем таймер
      if (_checkLoser()) {
        gameoverCallback.call('Loser');
        timer.cancel();
      }

      _determineDirection(); //определяем направление движения

      _movePieces(); //двигаем кусочки 

      setStateFunction();
    });
  }

 ///Определяем направление движения
  void _determineDirection() {
    if (piece.first % row == 0) {
      _direction = "right";
    } else if (piece.last % row == 9) {
      _direction = "left";
    }
  }

  ///В зависимости от направления двигаем кусочки влево или вправо
  void _movePieces() {
    if (_direction == "right") {
      for (int i = 0; i < piece.length; i++) {
        piece[i]++;
      }
    } else {
      for (int i = 0; i < piece.length; i++) {
        piece[i]--;
      }
    }
  }

  ///Проверка на победителя. Победил, если дошёл до верха
  bool _checkWinner() {
    if (landed.last < 10) {
      return true;
    } else {
      return false;
    }
  }

  ///Проверка на проигравшего. Проиграл, если удалены все 3 кусочка
  bool _checkLoser() {
    if (_removedSqr == 3) {
      return true;
    } else {
      return false;
    }
  }

  ///Стопка - то, что поставили
  void stack() {
    level++; //увеличиваем уровень, чтоб быть всё выше и выше
    for (int i = 0; i < piece.length; i++) {
      landed.add(piece[i]); //добавляем в приземлённые кусочки новые кусочки
    }

    _checkStack(); //удаляет непреземленные кусочки

    //смотрим сколько удалилось, в зависимости от количества делаем кусочки для нового уровня
    switch (_removedSqr) {
      case 2:
        piece = [numberOfSquares - 1 - level * row];
      case 1:
        piece = [
          numberOfSquares - 2 - level * row,
          numberOfSquares - 1 - level * row
        ];
      case 0:
        piece = [
          numberOfSquares - 3 - level * row,
          numberOfSquares - 2 - level * row,
          numberOfSquares - 1 - level * row
        ];
    }
  }

  ///Удаляем кусочки, которые не попали в стопку
  void _checkStack() {

    //Два отдельных цикла нужны потому что при удалении элемента из списка landed в 
    //первом цикле, индексы остальных элементов сдвигаются, что может привести к некорректной обработке элементов в последующих
    //итерациях первого цикла.
    //Второй цикл гарантирует, что все элементы, которые должны быть удалены, будут удалены корректно

    //проверка есть ли в списке landed элемент на 10 единиц больше, чем текущий
    for (int i = 0; i < landed.length; i++) {
      if (!landed.contains(landed[i] + row) &&
          (landed[i] + row < numberOfSquares - 1)) { //проверка, что это не первый ряд
        landed.remove(landed[i]);
        _removedSqr++;
      }
    }

    for (int i = 0; i < landed.length; i++) {
      if (!landed.contains(landed[i] + row) &&
          (landed[i] + row < numberOfSquares - 1)) {
        landed.remove(landed[i]);
        _removedSqr++;
      }
    }
  }


}
