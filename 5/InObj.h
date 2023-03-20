#pragma once
#include "Obj.h"
class InObj :
    public Obj
{
public:
    virtual istream& input(istream& f) = 0;
    virtual int input() = 0;
    virtual ostream& output(ostream& f) = 0;
    virtual void output() = 0;

    friend ostream& operator<<(ostream& out, InObj& obj);   // оператор вывода (заменяет output())                                     
    friend istream& operator>>(istream& in, InObj & obj);// операторввода (заменяет input())  
};

