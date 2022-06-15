#include "Double_List.h"

Double_List::Double_List(size_t size) : first(nullptr), last(nullptr), size(size)
{
	for (size_t i = 0; i < size; i++)	// � �����
		push_back(rand() % 90 + 10);	// ��������� ������� �� ��������� ��������� �� 10 �� 99
}

Double_List::Double_List(const Double_List& other)
{
	while (!(this->empty())) // ������� ��� ��������
		this->pop_front();
	this->size = other.size; // �������� ������
	Double_List::Node* temp = other.first;	// ������� � �������
	for (size_t i = 0; i < this->size; i++)	// � ����� ��� ������� ��������
	{
		this->push_back(temp->data);		// ��������� � ����� ������� �������
		temp = temp->next_ptr;				// ��������� � ���������� ��������
	}
}

Double_List::~Double_List()
{
	if (!empty()) // ���� �� ����� 
		while (!(empty())) // ������� ��� ��������
			pop_front();
}

bool Double_List::empty() { return !first; }

void Double_List::push_back(int new_data)
{
	if (empty()) // ���� ��������� ���
	{
		first = last = new Node;
		last->data = new_data;
		last->next_ptr = nullptr;
		last->prev_ptr = nullptr;
	}
	else // ���� ���� ������ 1 �������
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
	if (empty()) throw - 1;		// ���� ��������� ���, �������� ����������
	else if (last == first)		// ���� ������� 1
	{
		int temp_data = first->data;
		delete first;
		first = last = nullptr;
		return temp_data;
	}
	else						// ���� ��������� ������ 1
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
	while (!(this->empty())) // ������� ��� ��������
		this->pop_front();
	this->size = other.size; // �������� ������
	Double_List::Node* temp = other.first;	// ������� � �������
	for (size_t i = 0; i < this->size; i++)	// � ����� ��� ������� ��������
	{
		this->push_back(temp->data);		// ��������� � ����� ������� �������
		temp = temp->next_ptr;				// ��������� � ���������� ��������
	}
	return *this;
}

int& Double_List::operator()(size_t const& i)
{
	Double_List::Node* temp = i < size / 2 ? first : last; // ���� ������ ����� � ������� ��������, �� ������� �������� � ����, ����� � ����������
	if (i < size / 2) // ���� ������ ����� � �������
		for (size_t _i = 0; _i < i; ++_i) // ������� � ������� �� i����
			temp = temp->next_ptr; // ������� � ����������
	else // ���� ������ ����� � ����������
		for (size_t _i = size - 1; _i > i; --_i) // ������� � ���������� �� i����
			temp = temp->prev_ptr; // ������� � �����������
	return temp->data;
}

bool Double_List::operator==(Double_List& other)
{
	if (this->size != other.size) return false; // ���� ������� �� ��������� - false
	for (size_t i = 0; i < this->size; ++i) // � ����� ��� �������
		if ((*this)(i) != other(i)) // ���������� ������� ��������
			return false; // ���� �� ����� - false
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

std::ostream& operator<< (std::ostream& out, const Double_List& other) // ��������� ������� ����� �� �����
{
	Double_List A(other); // ������ �����
	while (!(A.empty())) // ���� ����� �� �����
		out << A.pop_front() << " "; // ������ �� ��������
	return out;
}
