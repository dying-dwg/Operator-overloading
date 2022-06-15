#include "Intnum.h"
using namespace std;

Intnum::Intnum(int data) : data(data) {} // �����������  �  ���������� �� ���������

Intnum::Intnum(const Intnum& other) : data(other.data) {} // ����������� �����������

Intnum::~Intnum() {} // ����������

Intnum& Intnum::operator= (const Intnum& other) // �������� ������������
{
	if (this == &other) //�������� �� ����������������
		return *this;
	this->data = other.data;
	return *this;
}

const Intnum& Intnum::operator++ () // �������, ����� ����������� �������� �� 1
{
	++this->data; // ��������   ��������
	return *this; // ���������� ��������
}

const Intnum& Intnum::operator-- () // �������, ����� ��������� �������� �� 1
{
	--this->data; // ��������   ��������
	return *this; // ���������� ��������
}

const Intnum operator++ (Intnum& intnum, int) // ��������, ��������� ������� ����������� �������� �� 2
{
	Intnum oldValue(intnum.data); // ������� �����
	++intnum.data; // �������� ��������
	++intnum.data; // �������� ��������
	return oldValue; // ���������� �����
}

const Intnum operator-- (Intnum& intnum, int) // ��������, ��������� ������� ��������� �������� �� 2
{
	Intnum oldValue(intnum.data); // ������� �����
	--intnum.data; // �������� ��������
	--intnum.data; // �������� ��������
	return oldValue; // ���������� �����
}

std::ostream& operator<< (std::ostream& out, const Intnum& o) // ��������� ������� ����� �� �����
{
	out << o.data;
	return out;
}