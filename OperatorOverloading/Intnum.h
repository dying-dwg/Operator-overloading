#pragma once
#include <iostream>

class Intnum
{
private:
	int data; // значение

public:
	//Intnum();	// конструктор без параметра - здесь так нельзя, тк существует конструктор  с  параметром по умолчанию

	Intnum(int data = 0);			// конструктор  с  параметром по умолчанию
	Intnum(const Intnum& other);	// конструктор копирования
	~Intnum();						// деструктор

	Intnum& operator= (const Intnum& other); // оператор присваивания

	const Intnum& operator++ (); // Префикс, метод увеличивает значение на 1
	const Intnum& operator-- (); // Префикс, метод уменьшает   значение на 1


	friend const Intnum operator++ (Intnum& intnum, int); // Постфикс, дружеская функция увеличивает значение на 2
	friend const Intnum operator-- (Intnum& intnum, int); // Постфикс, дружеская функция уменьшает   значение на 2

	friend std::ostream& operator<< (std::ostream& out, const Intnum& other); // дружеская функция вывод на экран
};