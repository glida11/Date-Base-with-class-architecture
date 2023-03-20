#define _CRT_SECURE_NO_WARNINGS
#include "Record.h"
#define SIZE 10
#define SSTR 256

Record::Record()
{
    name = "";
    group = "";
    NameEx = "";
    address = "";
    price = 0;
    mark = 0;
    DateAdmiss = { 0,0,0 };
}
Record::Record(String name1, String group1, String NameEx1, String address1, double price1 , int mark1, Date DateAdmiss1)
{
    setlocale(LC_ALL, "Russian");
    mark = mark1;
    price = price1;
    DateAdmiss = DateAdmiss1;
    name = name1;
    group = group1;
    NameEx = NameEx1;
    address = address1;
}
Record::Record(const Record& T)
{
    setlocale(LC_ALL, "Russian");

    mark = T.mark;
    DateAdmiss = T.DateAdmiss;
    name = T.name;
    group = T.group;
    NameEx = T.NameEx;
    address = T.address;
    price = T.price;
}
Record::~Record()
{
    name.~String();
    group.~String();
    NameEx.~String();
    address.~String();
}
String Record::ToMyString()const
{
    return String("MyRecord");
}
Obj* Record::copy()
{
    return this;
}

int Record::cmp(Obj& obj)
{
    Record tmp;
    tmp = ((Record&)obj);
    return tmp.name.cmp(this->name);
}

void Record::dispose()
{
    name.copy("");
    group.copy("");
    NameEx.copy("");
    address.copy("");
    mark = 0;
    price = 0;
    DateAdmiss = { 0,0,0 };
}


istream& Record::input(istream& CIN)
{
    getchar();
    String buf;
    cout << "Name: " << endl;
    CIN >> buf;
    name = buf;
    cout << "Number group: " << endl;
    CIN >> buf;
    group = buf;
    cout << "Name of the exam: " << endl;
    CIN >> buf;
    NameEx = buf;
    cout << "Address: " << endl;
    CIN >> buf;
    address = buf;
    cout << "Price: " << endl;
    CIN >> price;
    cout << "Mark: " << endl;
    CIN >> mark;
    cout << "Date of admission: " << endl;
    CIN >> DateAdmiss;
    return CIN;
}

int Record::input()
{
    this->input(cin);
    return 0;
}

ostream& Record::output(ostream& COUT)
{
    COUT.width(6);
    COUT << name << " | ";
    COUT.width(15);
    COUT << group << " | ";
    COUT.width(16);
    COUT << NameEx << " | ";
    COUT.width(15);
    COUT << address << " | ";
    COUT.width(10);
    COUT << price << " | ";
    COUT.width(6);
    COUT << mark << " | ";
    COUT << DateAdmiss;
    return COUT;
}

void Record::output()
{
    this->output(cout);
}



Record& Record::operator=(Record& R)
{
    mark = R.mark;
    DateAdmiss = R.DateAdmiss;
    name = R.name;
    group = R.group;
    NameEx = R.NameEx;
    address = R.address;
    price = R.price;
    return *this;
}



void Delete(Record* t, int index) {
    t[index].dispose();
    for (int i = index; i < SIZE - 1; i++) {
        t[i] = t[i + 1];
    }
    
}

