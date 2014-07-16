#include "includes.h"

using std::ostream;

CrossSumHead::CrossSumHead()
//Default constructor, sets all values to invalid items
{
    value = -1;
    row = -1;
    column = -1;
    length = -1;
    direction = 'n';
    id = -1;
}

CrossSumHead::CrossSumHead(int * val, int * r, int * c, int * len,
                           char * dir, int * idIn)
//constructor that will initiate every item to user-supplied values
{
    value = *val;
    row = *r;
    column = *c;
    length = *len;
    direction = *dir;
    id = *idIn;
}

CrossSumHead::CrossSumHead(const CrossSumHead &rhs):
    value(rhs.value), row(rhs.row), column(rhs.column), length(rhs.length), direction(rhs.direction),
    id(rhs.id)
//copy constructor
{}

CrossSumHead::~CrossSumHead() {}

void CrossSumHead::setValue(int *v)
//sets the value
{
    value = *v;
}

void CrossSumHead::setRow(int *r)
//sets the row
{
    row = *r;
}

void CrossSumHead::setColumn(int *c)
//sets the column
{
    column = *c;
}

void CrossSumHead::setLength(int *l)
//sets the length
{
    length = *l;
}

void CrossSumHead::setDirection(char *d)
//sets direction
{
    direction = *d;
}

void CrossSumHead::setId(int *i)
//sets id
{
    id = *i;
}

int CrossSumHead::getValue()
//returns the value
{
    return value;
}

int CrossSumHead::getRow()
//returns row
{
    return row;
}

int CrossSumHead::getColumn()
//returns the column
{
    return column;
}

int CrossSumHead::getLength()
//returns the length
{
    return length;
}

char CrossSumHead::getDirection()
//returns the direction
{
    return direction;
}

int CrossSumHead::getId()
//returns the id
{
    return id;
}

ostream& operator <<(ostream &out, const CrossSumHead &head)
//output to a stream, creates an atom in the form of "head(v,r,c,l,d,id)." then pushes
//a newline (although this step isn't necessary, it helps readability if you decide
//to view the generated file/use the information on a console.
{
    out <<"head(" << head.value << ',' << head.row << ','
        << head.column << ',' << head.length << ',' << head.direction
        << ',' << head.id << ").\n";

    return out;
}

CrossSumHead& CrossSumHead::operator =(const CrossSumHead &rhs)
//assignment operator, first ensures it isn't attempting to self assign then copies all the
//values
{
    if (this != &rhs)
    {   value = rhs.value;
        row = rhs.row;
        column = rhs.column;
        length = rhs.length;
        direction = rhs.direction;
        id = rhs.id;
    }

    return *this;
}
