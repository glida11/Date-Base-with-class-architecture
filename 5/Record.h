#pragma once
#include "InObj.h"
#include "String.h"
#include "Date.h"
class Record :
	public InObj
{
private:
	String name;
	String group;
	String NameEx;
	String address;
	double price;
	int mark;
	Date DateAdmiss;
public:
	Record();
	Record(String, String, String, String, double, int, Date);
	Record(const Record& r);
	~Record()override;

	Obj* copy() override;//����������� 
	int cmp(Obj& obj)override;//��������� ������ � ��������
	void dispose() override;
	String ToMyString()const override;

	istream& input(istream& CIN = cin)override;//����
	int input()override;
	ostream& output(ostream& COUT = cout)override;//�����
	void output()override;

	Record& operator =(Record& R);
	friend void Delete(Record*, int);
};

