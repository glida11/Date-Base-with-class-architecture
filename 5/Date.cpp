#include "Date.h"

Date::Date() {
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(const Date& D1)
{
	day = D1.day;
	month = D1.month;
	year = D1.year;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

Date::~Date() {}


void Date::copy(const Date& D)
{
	day = D.day;
	month = D.month;
	year = D.year;
}


Obj* Date::copy()
{
	return this;
}

bool verif(int day, int month, int year) {
	if (month < 0 || day < 0 || year < 0)
		return 0;
	int numDaysNoVis[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int numDaysVis[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12)
		return 0;
	if ((year % 4 == 0 && year % 100 != 0 || year % 400) && numDaysVis[month - 1] < day || numDaysNoVis[month - 1] < day)
		return 0;
	return 1;
}

istream& Date::input(istream& CIN)
{
	int d, m, y;
	do{
		cout << "Day: ";
		CIN >> d;
		cout << "Month: ";
		CIN >> m;
		cout << "Year: ";
		CIN >> y;
		if (!verif(d, m, y))
			cout << "Incorrect data entered" << endl << "Try again:" << endl;
	} while (!verif(d, m, y));
	day = d;
	month = m;
	year = y;
	return CIN;
}

int Date::input()
{
	this->input(cin);
	return 0;
}
void Date::output() 
{
	this->output(cout);
}
ostream& Date::output(ostream& COUT)
{
	COUT << day << '.' << month << '.' << year;
	return COUT;
}

int Date::cmp(const Date& D)
{
	if (year < D.year) return -1;
	else
		if (year == D.year)
			if (month < D.month) return -1;
			else
				if (month == D.month)
					if (day < D.day) return -1;
					else 
						if(day == D.day)
							return 0;
	return 1;
}

int Date::cmp(Obj& obj)
{
	return obj.ToMyString().cmp(String("MyDate")) == 0;;
}

String Date::ToMyString()const
{
	
    return String("MyDate");
}

void Date::dispose()
{
	day = 0; month = 0; year = 0;
}
