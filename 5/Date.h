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

	Obj* copy() override;//Копирование 
	String ToMyString()const override;
	void dispose() override;

	istream& input(istream& CIN = cin)override;//Ввод
	int input()override;
	ostream& output(ostream& COUT = cout)override;//Вывод
	void output()override;
	int cmp(const Date& D);//Сравнение дат
	int cmp(Obj& obj)override;//Сравнение даты с обьектом


};

