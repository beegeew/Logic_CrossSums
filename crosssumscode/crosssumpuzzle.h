#ifndef CROSSSUMPUZZLE_H
#define CROSSSUMPUZZLE_H

#include "includes.h"

class CrossSumPuzzle
{
    friend ostream& operator<<(ostream&,const CrossSumPuzzle&);
    friend istream& operator>>(istream&, CrossSumPuzzle&);

public:
    CrossSumPuzzle(int);
    ~CrossSumPuzzle();

    //functions that insert a new head, remove a head, return the solvable state
    //and input in a puzzle from a stream
    bool inputHead(int*,int*,int*,int*,char*);
    bool removeHead(int*,int*,char*);
    bool isSolvable() {return solvable;}
    istream& inputPuzzle(istream&);

    //functions to solve the puzzle, compare input value against stored value and return
    //the type of cell currently being looked at
    void solve();
    bool validValue(int*,int*,int*);
    char cellType(int*,int*);

    //get values for head, value and length of head
    int  getHeadValue(int*,int*,char*);
    int  getValue(int*,int*);
    int getHeadLength(int*,int*,char*);

private:
    //private functions which determine if the head values provided by the user are
    //valid and a function that determines if a head exists and provides it's id if needed.
    bool isValidHead(int,int);
    bool found(int,int,char,int&);

    char** cells;               //Have values of b for blank, h for head, and v for value
    CrossSumValue* csValues;    //Storage of values for the puzzle
    CrossSumHead* csHeads;      //Storage of heads for the puzzle
    int size;                   //Puzzle will be of a size n by n, where n = size
    int numHeads;               //We need to keep track of the # of hints to properly number the hints
    int numValues;              //to help us keep track of the number of values found
    bool solvable;              //If this is set to false by the solve() function, then the user will be notified
};

#endif // CROSSSUMPUZZLE_H
