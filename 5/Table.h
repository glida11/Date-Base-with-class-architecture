#pragma once
#include "Obj.h"
typedef Obj* T;
class Table
{
	T* cur;
	T buf;
	int count;
public:
	Table(int sz, T* bf); 
	Table();
	Table(const Table& T);
	~Table();
	T* begin()const;
	T* end()const;
	int GetSize();
	int length();
	T* insert(const T& item);
	T* erase(int pos); 
	int equal(const Table& Tab)const;
	void clear(); 
	int remove(int pos); 
	int find(const T& item); 
	int replace(int Old, int New); 
	int replace(int Old, const T& New);
	void sort(); 
	istream& input(istream& Cin);
	ostream& output(ostream& Cout)const;
	friend ostream& operator<<(ostream& os, const Table& r);// оператор вывода(заменяет output())       
	friend istream& operator>>(istream& is, Table& r);
	Table& operator =(Table S1);

	Obj *at(int a);
};


