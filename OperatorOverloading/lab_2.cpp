#include "Double_List.h"
#include "Intnum.h"

#include <iostream>
using namespace std;

void task1(); // Объявлене функции для первого задания
void task2(); // Объявлене функции для второго задания

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int keyMenu;
	do
	{
		cout << "\n~~~~|Пользовательское меню: Вариант 2|~~~~\n"
			<< "\n[1]: Задание 1: Унарная операция;"
			<< "\n[2]: Задание 2: Бинарная операция;"
			<< "\n\n[3]: Выход;"
			<< "\n\n-> "; cin >> keyMenu;

		system("cls");

		// ЗАДАНИЕ 1
		if (keyMenu == 1)
			task1();

		// ЗАДАНИЕ 2
		else if (keyMenu == 2)
			task2();

		else if (keyMenu == 3)
			cout << "Программа остановлена. Закройте окно.\n";

		else if (3 < keyMenu || keyMenu < 1)
		{
			system("cls");
			cout << "Воспользуйтесь одной из команда 1-3!\n";
		}

	} while (keyMenu != 3);

	return 0;
}

void task1()
{
	int keyOne;
	Intnum a;
	do
	{
		cout << "\n~~~~|Задание 1: Унарная операция|~~~~\n"
			<< "\n[1]: Уменьшить значение на 1;" // Оператор -- | Преф.  форма | Метод
			<< "\n[2]: Увеличить значение на 1;" // Оператор ++ | Преф.  форма | Метод
			<< "\n[3]: Уменьшить значение на 2;" // Оператор -- | Постф. форма | Друж. функц.
			<< "\n[4]: Увеличить значение на 2;" // Оператор ++ | Постф. форма | Друж. функц.
			<< "\n[5]: Вывести значение в консоль;" // Оператор ++ | Постф. форма | Друж. функц.
			<< "\n\n[6]: Назад."
			<< "\n\n-> "; cin >> keyOne;

		system("cls");

		if (keyOne == 1)
			cout << --a << endl;

		else if (keyOne == 2)
			cout << ++a << endl;

		else if (keyOne == 3)
			cout << a-- << endl;

		else if (keyOne == 4)
			cout << a++ << endl;

		else if (keyOne == 5)
			cout << a << endl;

		else if (keyOne == 6)
			cout << "Задание закрыто.\n";

		else if (6 < keyOne || keyOne < 1)
		{
			system("cls");
			cout << "Воспользуйтесь одной из команда 1-6!\n";
		}

	} while (keyOne != 6);
}

void task2()
{
	int keyTwo;
	size_t size1, size2;
	cout << "\n> Введится размер списка 1: ";
	cin >> size1;

	cout << "> Введится размер списка 2: ";
	cin >> size2;

	Double_List DL1(size1), DL2(size2);
	do
	{
		cout << "\n~~~~|Задание 2: Бинарная операция|~~~~\n"
			<< "\n[1]: Вывести список в консоль;"
			<< "\n[2]: Сравнение: Первое меньше второго?;"
			<< "\n[3]: Сравнение: Первое больше второго?;"
			<< "\n[4]: Сравнение: Равенство первого и второго;"
			<< "\n[5]: Сравнение: Неравенство первого и второго;"
			<< "\n[6]: Скопировать список 2 в список 1;"
			<< "\n[7]: Вывести элемент списка;"
			<< "\n\n[8]: Назад.\n-> ";
		cin >> keyTwo;
		system("cls");

		if (keyTwo == 1)
			cout << "\nсписок 1: " << DL1 << "\nсписок 2: " << DL2 << endl;

		else if (keyTwo == 2)
			cout << "Первое меньше второго?\n" << (DL1 < DL2 ? " - да" : " - нет") << endl;

		else if (keyTwo == 3)
			cout << "Первое больше второго?\n" << (DL1 > DL2 ? " - да" : " - нет") << endl;

		else if (keyTwo == 4)
			cout << "Первое равно второму?\n" << (DL1 == DL2 ? " - да" : " - нет") << endl;

		else if (keyTwo == 5)
			cout << "Первое не равно второму?\n" << (DL1 != DL2 ? " - да" : " - нет") << endl;

		else if (keyTwo == 6)
			DL1 = DL2;

		else if (keyTwo == 7)
		{
			int i;
			cout << "Введите индекс элемента: ";
			cin >> i;

			cout << "Элемент списка 1 под индексом " << i << " = " << DL1(i) << endl;
			cout << "Элемент списка 2 под индексом " << i << " = " << DL2(i) << endl;
		}
		else if (keyTwo == 8)
			cout << "Задание закрыто.\n";

		else if (8 < keyTwo || keyTwo < 1)
		{
			system("cls");
			cout << "Воспользуйтесь одной из команда 1-8!\n";
		}
	} while (keyTwo != 8);
}