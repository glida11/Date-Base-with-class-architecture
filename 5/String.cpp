#include "String.h"
#define STR_SIZE 32
String::String()
{
	len = STR_SIZE;
	StrArr = new char[len];
}
String::String( const char* str1)
{
	len = strlen(str1);
	StrArr = new char[len];
	strcpy_s(StrArr, len + 1, str1);
}
String::String(const String& N)
{
	len = N.len;
	StrArr = new char[N.len];
	strcpy_s(StrArr, N.len + 1, N.StrArr);
}
String :: ~String()
{
	//delete[] StrArr;
}

Obj* String::copy()
{
	return this;
}

String String::ToMyString()const
{
	
	return String("MyString");
}

void String::copy(const String& N)
{
	len = N.len;
	StrArr = new char[len];
	strcpy_s(StrArr, len + 1, N.StrArr);
}

void String::copy(const char* string)
{
	len = strlen(string);
	//delete[]StrArr;
	strcpy_s(StrArr, len + 1, string);
}

void String::dispose()
{
	len = 1;
	delete[] StrArr;
	StrArr = new char[1];
}

istream& String::input(istream& CIN)
{
	
	char* str = new char[STR_SIZE];
	CIN.getline(str, STR_SIZE);
	len = strlen(str);
	str[len++] = '\0';
	
	strcpy_s(StrArr, len + 1, str);
	return CIN;
}

int String::input()
{
	this->input(cin);
	return 0;
}

ostream& String::output(ostream& COUT)
{
	COUT << StrArr;
	return COUT;
}

void String::output()
{
	this->output(cout);
}

int String::cmp(const String& s)
{
	return strcmp(StrArr, s.StrArr);
}


int String::cmp(Obj& obj)
{
	return obj.ToMyString().cmp( String("MyString"))==0;
}

String& String::operator =(String S1)
{
	this->copy(S1.StrArr);
	return *this;
}


