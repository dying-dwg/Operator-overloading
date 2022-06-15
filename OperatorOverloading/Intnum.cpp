#include "Intnum.h"
using namespace std;

Intnum::Intnum(int data) : data(data) {} // конструктор  с  параметром по умолчанию

Intnum::Intnum(const Intnum& other) : data(other.data) {} // конструктор копировани€

Intnum::~Intnum() {} // деструктор

Intnum& Intnum::operator= (const Intnum& other) // оператор присваивани€
{
	if (this == &other) //проверка на самоприсваивание
		return *this;
	this->data = other.data;
	return *this;
}

const Intnum& Intnum::operator++ () // ѕрефикс, метод увеличивает значение на 1
{
	++this->data; // измен€ем   оригинал
	return *this; // возвращаем оригинал
}

const Intnum& Intnum::operator-- () // ѕрефикс, метод уменьшает значение на 1
{
	--this->data; // измен€ем   оригинал
	return *this; // возвращаем оригинал
}

const Intnum operator++ (Intnum& intnum, int) // ѕостфикс, дружеска€ функци€ увеличивает значение на 2
{
	Intnum oldValue(intnum.data); // создаем копию
	++intnum.data; // измен€ем оригинал
	++intnum.data; // измен€ем оригинал
	return oldValue; // возвращаем копию
}

const Intnum operator-- (Intnum& intnum, int) // ѕостфикс, дружеска€ функци€ уменьшает значение на 2
{
	Intnum oldValue(intnum.data); // создаем копию
	--intnum.data; // измен€ем оригинал
	--intnum.data; // измен€ем оригинал
	return oldValue; // возвращаем копию
}

std::ostream& operator<< (std::ostream& out, const Intnum& o) // дружеска€ функци€ вывод на экран
{
	out << o.data;
	return out;
}