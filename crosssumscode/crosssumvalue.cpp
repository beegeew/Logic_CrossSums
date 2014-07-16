#include "includes.h"

CrossSumValue::CrossSumValue()
//Default constructor just sets all values to zero
{
    value = 0;
    row = 0;
    column = 0;
}

CrossSumValue::CrossSumValue(int *v, int *r, int *c)
//Overloaded constructor if the user decides to provide values
{
    value = *v;
    row = *r;
    column = *c;
}

CrossSumValue::~CrossSumValue()
{}

CrossSumValue& CrossSumValue::operator =(const CrossSumValue &rhs)
//Assignment operator, ensures that it's not self assignment
{
    if (this != &rhs)
    {
        column = rhs.column;
        row = rhs.row;
        value = rhs.value;
    }

    return *this;
}

void CrossSumValue::setValue(int* v)
//Mutator changes the value
{
    value = *v;
}

void CrossSumValue::setRow(int* r)
//mutator to change the row
{
    row = *r;
}

void CrossSumValue::setColumn(int* c)
//mutator to change the column
{
    column = *c;
}

int CrossSumValue::getRow()
//returns the row
{
    return row;
}

int CrossSumValue::getColumn()
//returns the column
{
    return column;
}

int CrossSumValue::getValue()
//returns the value
{
    return value;
}

std::istream& operator>>(std::istream &in, CrossSumValue &cell)
//input stream to read in a new value, it assumes that the value atom is in the proper format
//reported by the solver. value(v,r,c,rid,cid). we ignore rid and cid in this case but they
//might be useful to implement for the hint deletion function if I implement it in the future
//for error checking.
{
    for (int i = 0; i < 6; i++)
        in.get();
    in >> cell.value;
    in.get();
    in >> cell.row;
    in.get();
    in >> cell.column;

    while (in.peek() != 'v')
        in.get();

    return in;
}
