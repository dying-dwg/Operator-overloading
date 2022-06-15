#include "Double_List.h"

Double_List::Double_List(size_t size) : first(nullptr), last(nullptr), size(size)
{
	for (size_t i = 0; i < size; i++)	// в цикле
		push_back(rand() % 90 + 10);	// добавл€ем элемент со случайным значением от 10 до 99
}

Double_List::Double_List(const Double_List& other)
{
	while (!(this->empty())) // удал€ем все элементы
		this->pop_front();
	this->size = other.size; // копируем размер
	Double_List::Node* temp = other.first;	// начина€ с первого
	for (size_t i = 0; i < this->size; i++)	// в цикле дл€ каждого элемента
	{
		this->push_back(temp->data);		// добавл€ем в конец текущий элемент
		temp = temp->next_ptr;				// переходим к следующему элементу
	}
}

Double_List::~Double_List()
{
	if (!empty()) // если не пусто 
		while (!(empty())) // удал€ем все элементы
			pop_front();
}

bool Double_List::empty() { return !first; }

void Double_List::push_back(int new_data)
{
	if (empty()) // если элементов нет
	{
		first = last = new Node;
		last->data = new_data;
		last->next_ptr = nullptr;
		last->prev_ptr = nullptr;
	}
	else // если есть хот€бы 1 элемент
	{
		Node* temp = new Node;
		temp->prev_ptr = last;
		temp->next_ptr = nullptr;
		last->next_ptr = temp;
		temp->data = new_data;
		last = temp;
	}
}

int Double_List::pop_front()
{
	if (empty()) throw - 1;		// если элементов нет, вызываем исключени€
	else if (last == first)		// если элемент 1
	{
		int temp_data = first->data;
		delete first;
		first = last = nullptr;
		return temp_data;
	}
	else						// если элементов больше 1
	{
		Node* temp = first->next_ptr;
		int temp_data = first->data;
		delete first;
		temp->prev_ptr = nullptr;
		first = temp;
		return temp_data;
	}
}

Double_List& Double_List::operator=(const Double_List& other)
{
	while (!(this->empty())) // удал€ем все элементы
		this->pop_front();
	this->size = other.size; // копируем размер
	Double_List::Node* temp = other.first;	// начина€ с первого
	for (size_t i = 0; i < this->size; i++)	// в цикле дл€ каждого элемента
	{
		this->push_back(temp->data);		// добавл€ем в конец текущий элемент
		temp = temp->next_ptr;				// переходим к следующему элементу
	}
	return *this;
}

int& Double_List::operator()(size_t const& i)
{
	Double_List::Node* temp = i < size / 2 ? first : last; // если индекс ближе к первому элементу, то перебор начинаем с него, иначе с последнего
	if (i < size / 2) // если индекс ближе к первому
		for (size_t _i = 0; _i < i; ++_i) // перебор с первого до iтого
			temp = temp->next_ptr; // переход к следующему
	else // если индекс ближе к последнему
		for (size_t _i = size - 1; _i > i; --_i) // перебор с последнего до iтого
			temp = temp->prev_ptr; // переход к предыдущему
	return temp->data;
}

bool Double_List::operator==(Double_List& other)
{
	if (this->size != other.size) return false; // если размеры не совпадают - false
	for (size_t i = 0; i < this->size; ++i) // в цикле дл€ каждого
		if ((*this)(i) != other(i)) // сравниваем текущие значени€
			return false; // если не равны - false
	return true;
}

bool Double_List::operator!=(Double_List& other)
{
	return !(*this == other);
}

bool operator<(Double_List& A, Double_List& B)
{
	if (A.size < B.size) return true;
	return false;
}

bool operator>(Double_List& A, Double_List& B)
{
	if (A.size > B.size) return true;
	return false;
}

std::ostream& operator<< (std::ostream& out, const Double_List& other) // дружеска€ функци€ вывод на экран
{
	Double_List A(other); // создаю копию
	while (!(A.empty())) // пока копи€ не пуста
		out << A.pop_front() << " "; // вывожу ее элементы
	return out;
}
