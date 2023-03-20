#include "InObj.h"

ostream& operator<<(ostream& out, InObj& obj) 
{
    obj.output(out);
    return out;
}

istream& operator>>(istream& in, InObj& obj)
{
    obj.input(in);
    return in;
}
