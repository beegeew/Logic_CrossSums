#ifndef CROSSSUMHEAD_H
#define CROSSSUMHEAD_H

#include "includes.h"

using std::ostream;

class CrossSumHead
//This is where we store heads, aka hints/clues for the cross sums puzzle, it provides
//an ostream operator, overloaded constructors and an assignment operator.
//all data items are private and mutators are provided for every item along with accessors
{
    friend ostream& operator <<(ostream &os,const CrossSumHead &head);
public:
    CrossSumHead();
    CrossSumHead(int*, int*, int*, int*, char*, int*);
    CrossSumHead(const CrossSumHead&);
    ~CrossSumHead();

    //assignment
    CrossSumHead &operator=(const CrossSumHead &rhs);

    //mutators
    void setValue(int*);
    void setRow(int*);
    void setColumn(int*);
    void setLength(int*);
    void setDirection(char*);
    void setId(int*);

    //accessors
    int getValue();
    int getRow();
    int getColumn();
    int getLength();
    char getDirection();
    int getId();

private:
    //all of our data
    int value;
    int row;
    int column;
    int length;
    char direction;
    int id;
};

#endif // CROSSSUMHEAD_H
