#pragma once
#include <iostream>
#include <ctime>

class Double_List
{
private:
	class Node
	{
	public:
		Node* next_ptr;
		Node* prev_ptr;
		int data;
	};

	size_t size;
	Node* first;
	Node* last;

public:
	explicit Double_List(size_t size);		// конструктор, принимает размер очереди
	Double_List(const Double_List& other);	// конструктор копирования
	~Double_List();							// деструктор
	bool empty();

	void push_back(int new_data);
	int pop_front();

	Double_List& operator= (const Double_List& other); // оператор присваивания

	int& operator() (size_t const& i);					// метод сравнивает 2 объекта

	bool operator==(Double_List& other);					// метод сравнивает 2 объекта
	bool operator!=(Double_List& other);					// метод сравнивает 2 объекта
	friend bool operator<(Double_List& A, Double_List& B);	// дружественная функция сравнивает 2 объекта
	friend bool operator>(Double_List& A, Double_List& B);	// дружественная функция сравнивает 2 объекта
	friend std::ostream& operator<< (std::ostream& out, const Double_List& other); // дружеская функция вывод на экран
};