#include "Obj.h"

int operator==(Obj& a, Obj& b)
{
	return a.cmp(b)==0;
}

int operator!=( Obj& a, Obj& b)
{
	return a.cmp(b);
}

int operator<( Obj& a, Obj& b)
{
	return a.cmp(b)<0;
}

int operator<=( Obj& a, Obj& b)
{
	return a.cmp(b)<=0;
}

int operator>( Obj& a, Obj& b)
{
	
	return a.cmp(b) > 0;
}

int operator>=(Obj& a, Obj& b)
{
	return a.cmp(b) >= 0;
}


