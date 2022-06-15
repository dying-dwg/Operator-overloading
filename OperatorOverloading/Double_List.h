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
	explicit Double_List(size_t size);		// �����������, ��������� ������ �������
	Double_List(const Double_List& other);	// ����������� �����������
	~Double_List();							// ����������
	bool empty();

	void push_back(int new_data);
	int pop_front();

	Double_List& operator= (const Double_List& other); // �������� ������������

	int& operator() (size_t const& i);					// ����� ���������� 2 �������

	bool operator==(Double_List& other);					// ����� ���������� 2 �������
	bool operator!=(Double_List& other);					// ����� ���������� 2 �������
	friend bool operator<(Double_List& A, Double_List& B);	// ������������� ������� ���������� 2 �������
	friend bool operator>(Double_List& A, Double_List& B);	// ������������� ������� ���������� 2 �������
	friend std::ostream& operator<< (std::ostream& out, const Double_List& other); // ��������� ������� ����� �� �����
};