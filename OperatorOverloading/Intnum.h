#pragma once
#include <iostream>

class Intnum
{
private:
	int data; // ��������

public:
	//Intnum();	// ����������� ��� ��������� - ����� ��� ������, �� ���������� �����������  �  ���������� �� ���������

	Intnum(int data = 0);			// �����������  �  ���������� �� ���������
	Intnum(const Intnum& other);	// ����������� �����������
	~Intnum();						// ����������

	Intnum& operator= (const Intnum& other); // �������� ������������

	const Intnum& operator++ (); // �������, ����� ����������� �������� �� 1
	const Intnum& operator-- (); // �������, ����� ���������   �������� �� 1


	friend const Intnum operator++ (Intnum& intnum, int); // ��������, ��������� ������� ����������� �������� �� 2
	friend const Intnum operator-- (Intnum& intnum, int); // ��������, ��������� ������� ���������   �������� �� 2

	friend std::ostream& operator<< (std::ostream& out, const Intnum& other); // ��������� ������� ����� �� �����
};