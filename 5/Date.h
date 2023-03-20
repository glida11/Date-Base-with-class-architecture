#pragma once
#include "String.h"
#include "InObj.h"

class Date :
	public InObj
{
	int day;
	int month;
	int year;
public:
	Date();
	Date(const Date& D1);
	Date(int d, int m, int y);
	~Date()override;
	friend bool verif(int day, int month, int year);
	void copy(const Date& D);

	Obj* copy() override;//����������� 
	String ToMyString()const override;
	void dispose() override;

	istream& input(istream& CIN = cin)override;//����
	int input()override;
	ostream& output(ostream& COUT = cout)override;//�����
	void output()override;
	int cmp(const Date& D);//��������� ���
	int cmp(Obj& obj)override;//��������� ���� � ��������


};

