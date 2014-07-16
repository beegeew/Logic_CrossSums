#ifndef CROSSSUMVALUE_H
#define CROSSSUMVALUE_H

#include "includes.h"

using std::istream;

class CrossSumValue
//This class stores a value item - it was operator >> and operator = support
//mutators, accessors and overloaded constructors. All data items are private.
{
    friend istream& operator>>(istream &in, CrossSumValue &cell);

public:
    CrossSumValue();
    CrossSumValue(int*, int*, int*);
    ~CrossSumValue();

    CrossSumValue &operator=(const CrossSumValue& rhs);

    void setValue(int*);
    void setRow(int*);
    void setColumn(int*);

    int getValue();
    int getRow();
    int getColumn();

private:
    int value;
    int row;
    int column;
};

#endif // CROSSSUMVALUE_H
