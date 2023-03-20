#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class String;
class Date;
class MyVector;
class Record;
class Obj
{
public:
	virtual ~Obj() = 0 {}
	virtual String ToMyString()const = 0;
	virtual Obj* copy() = 0;
	virtual void dispose() = 0;
	virtual int cmp(Obj&) = 0;
	
	friend int operator == (Obj& a, Obj& b);
	friend int operator != (Obj& a, Obj& b);
	friend int operator <(Obj& a, Obj& b);
	friend int operator <= (Obj& a, Obj& b);
	friend int operator > (Obj& a, Obj& b);
	friend int operator >= (Obj& a, Obj& b);
};

