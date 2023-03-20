#pragma once
#include "InObj.h"
class String :
    public InObj
{
private:
    int len;
    char* StrArr;
public:
    String();
    String(const char* string);
    String(const String&);
    void copy(const char* string);
    void copy(const String& N);

    void dispose() override;
    ~String()override;
    Obj* copy() override;//����������� 
    String ToMyString()const override;
    int cmp(Obj& obj)override;

    istream& input(istream& CIN = cin)override;//����
    int input()override;
    ostream& output(ostream& COUT = cout)override;//�����
    void output()override;
    int cmp(const String& s);
    
    String& operator =(String S1);
};

