#include "Double_List.h"
#include "Intnum.h"

#include <iostream>
using namespace std;

void task1(); // ��������� ������� ��� ������� �������
void task2(); // ��������� ������� ��� ������� �������

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int keyMenu;
	do
	{
		cout << "\n~~~~|���������������� ����: ������� 2|~~~~\n"
			<< "\n[1]: ������� 1: ������� ��������;"
			<< "\n[2]: ������� 2: �������� ��������;"
			<< "\n\n[3]: �����;"
			<< "\n\n-> "; cin >> keyMenu;

		system("cls");

		// ������� 1
		if (keyMenu == 1)
			task1();

		// ������� 2
		else if (keyMenu == 2)
			task2();

		else if (keyMenu == 3)
			cout << "��������� �����������. �������� ����.\n";

		else if (3 < keyMenu || keyMenu < 1)
		{
			system("cls");
			cout << "�������������� ����� �� ������� 1-3!\n";
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
		cout << "\n~~~~|������� 1: ������� ��������|~~~~\n"
			<< "\n[1]: ��������� �������� �� 1;" // �������� -- | ����.  ����� | �����
			<< "\n[2]: ��������� �������� �� 1;" // �������� ++ | ����.  ����� | �����
			<< "\n[3]: ��������� �������� �� 2;" // �������� -- | �����. ����� | ����. �����.
			<< "\n[4]: ��������� �������� �� 2;" // �������� ++ | �����. ����� | ����. �����.
			<< "\n[5]: ������� �������� � �������;" // �������� ++ | �����. ����� | ����. �����.
			<< "\n\n[6]: �����."
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
			cout << "������� �������.\n";

		else if (6 < keyOne || keyOne < 1)
		{
			system("cls");
			cout << "�������������� ����� �� ������� 1-6!\n";
		}

	} while (keyOne != 6);
}

void task2()
{
	int keyTwo;
	size_t size1, size2;
	cout << "\n> �������� ������ ������ 1: ";
	cin >> size1;

	cout << "> �������� ������ ������ 2: ";
	cin >> size2;

	Double_List DL1(size1), DL2(size2);
	do
	{
		cout << "\n~~~~|������� 2: �������� ��������|~~~~\n"
			<< "\n[1]: ������� ������ � �������;"
			<< "\n[2]: ���������: ������ ������ �������?;"
			<< "\n[3]: ���������: ������ ������ �������?;"
			<< "\n[4]: ���������: ��������� ������� � �������;"
			<< "\n[5]: ���������: ����������� ������� � �������;"
			<< "\n[6]: ����������� ������ 2 � ������ 1;"
			<< "\n[7]: ������� ������� ������;"
			<< "\n\n[8]: �����.\n-> ";
		cin >> keyTwo;
		system("cls");

		if (keyTwo == 1)
			cout << "\n������ 1: " << DL1 << "\n������ 2: " << DL2 << endl;

		else if (keyTwo == 2)
			cout << "������ ������ �������?\n" << (DL1 < DL2 ? " - ��" : " - ���") << endl;

		else if (keyTwo == 3)
			cout << "������ ������ �������?\n" << (DL1 > DL2 ? " - ��" : " - ���") << endl;

		else if (keyTwo == 4)
			cout << "������ ����� �������?\n" << (DL1 == DL2 ? " - ��" : " - ���") << endl;

		else if (keyTwo == 5)
			cout << "������ �� ����� �������?\n" << (DL1 != DL2 ? " - ��" : " - ���") << endl;

		else if (keyTwo == 6)
			DL1 = DL2;

		else if (keyTwo == 7)
		{
			int i;
			cout << "������� ������ ��������: ";
			cin >> i;

			cout << "������� ������ 1 ��� �������� " << i << " = " << DL1(i) << endl;
			cout << "������� ������ 2 ��� �������� " << i << " = " << DL2(i) << endl;
		}
		else if (keyTwo == 8)
			cout << "������� �������.\n";

		else if (8 < keyTwo || keyTwo < 1)
		{
			system("cls");
			cout << "�������������� ����� �� ������� 1-8!\n";
		}
	} while (keyTwo != 8);
}