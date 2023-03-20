#include "Table.h"
#include "Record.h"
Table::Table()
{
	count = 0;
	cur = new T[1];
	buf = new Record();
}
Table::Table(int sz, T* bf)
{
	count = sz;
	delete[] cur;
	cur = new T[sz];
	for (int i = 0; i < sz; i++)
	{
		cur[i] = bf[i];
	}
	buf = new Record();
}
Table::Table(const Table& Tab)
{
	count = Tab.count;
	delete[] cur;
	cur = new T[count];
	for (int i = 0; i < count; i++)
	{
		cur[i] = Tab.cur[i];
	}
	buf = new Record();
}
Table::~Table()
{
	for (int i = 0; i < count; i++)
		cur[i]->~Obj();
}

T* Table::begin() const
{	
	return &cur[0];
}

T* Table::end() const
{
	return &cur[count];
}

int Table::GetSize()
{
	return count;
}

int Table::length()
{
	
	return _msize(this);
}

T* Table::insert(const T& item)
{
	cur[count] = item;
	return cur;
}

T* Table::erase(int pos)
{
	delete[]cur[pos];
	return cur;
}

int Table::equal(const Table& Tab) const
{
	return 0;
}

void Table::clear()
{
	this->~Table();
}

int Table::remove(int pos)
{
	if (pos != -1)
	{
		for (int i = pos; i < count; i++)
		{
			cur[i] = cur[i + 1];
		}
		count--;
		return 1;
	}
	else
		return 0;
}

int Table::find(const T& item)
{
	for (int i = 0; i < count; i++)
	{
		if (*cur[i] == *item)
			return i;
	}
	return -1;
}

int Table::replace(int Old, int New)
{
	if (Old < 0 || Old >= count || New < 0 || New >= count)
	{
		return 0;
	}
	else
	{
		cur[Old] = cur[New];
		return 1;
	}
}


int Table::replace(int Old, const T& New)
{
	if (Old < 0 || Old >= count )
	{
		return 0;
	}
	else
	{
		cur[Old] = New;
		return 1;
	}
}

void Table::sort()
{
	for(int i = 0; i < count - 1; i ++)
		for (int j = 0; j < count - i - 1; j++)
		{
			if (*cur[j]<*cur[j+1])
			{
				T tmp =cur[j];
				this->replace(j, j + 1);
				this->replace(j + 1, tmp);
			}
		}
}

istream& Table::input(istream& Cin)
{
	buf = new Record();
	((InObj*)buf)->input(Cin);
	insert(buf);
	count++;
	cur[count-1];
	cur[0];
	return Cin;
}

ostream& Table::output(ostream& Cout) const
{
	for (T* i = begin(); i != end(); i++)
	{
		((InObj*)(*i))->output(Cout);
		cout << endl;
	}
	return Cout;
}

Table& Table::operator=(Table Tab)
{
	count = Tab.count;
	delete[] cur;
	cur = new T[count];
	for (int i = 0; i < count; i++)
	{
		cur[i] = Tab.cur[i];
	}
	buf = new Record();
	return *this;
}

Obj *Table::at(int a)
{
	return cur[a];
}

ostream& operator<<(ostream& os, const Table& r)
{
	r.output(os);
	return os;
}

istream& operator>>(istream& is, Table& r)
{
	r.input(is);
	return is;
}
