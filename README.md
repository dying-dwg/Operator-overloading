# Перегрузка операторов

### Унарная операция
Создать класс целых чисел. Оператор --(префиксная форма, метод) уменьшает
значение на 1, оператор ++(префиксная форма, метод) увеличивает значение на 1,
оператор --(постфиксная форма, дружественная функция) уменьшает значение на 2,
оператор ++(постфиксная форма, дружественная функция) увеличивает значение на 2.

### Бинарная операция
Создать класс «двусвязный линейный список», который хранит числа; размер
списка вводится с клавиатуры, список заполняется случайными числами. Перегрузить
операторы сравнения (, ==, !=) для работы с числами (поэлементно). Половину
операторов перегрузить как дружественные функции, половину как методы.
Перегрузить оператор () для возвращения подсписка


- Создаю класс целых чисел Intnum (разделён на определение Intnum.h и
реализацию функции Intnum.cpp), в котором реализую необходимые операторы, а
также операторы по заданию (присваивания, префиксное увеличение/уменьшение,
постфиксное увеличение/уменьшение).
Используя данные операторы создаю пользовательское меню (Задание 1) с
возможностями:
  1. Уменьшить значение на 1;
  2. Увеличить значение на 1;
  3. Уменьшить значение на 2;
  4. Увеличить значение на 2;

- Создаю двусвязный линейный список Double_List (также разделённый на
определение h и реализацию cpp), в нём реализую операторы сравнения (<, >, =,
≠). Используя данные операторы создаю пользовательское меню (Задание 2) с
возможностями:
   1. ввод размеров списков 1 и 2
   2. различные сравнения (1<2? ; 1>2? ; 1=2? ; 1≠2?)
   3. копирование списка 2 в список 1
   4. вывод элемента списка


Меню основной программы основано на конструкции if-elseif.
В меню реализован выбор задания по варианту (Задание 1, Задание2). 
