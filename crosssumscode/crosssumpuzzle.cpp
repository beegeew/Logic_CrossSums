#include "includes.h"

CrossSumPuzzle::CrossSumPuzzle(int s)
{
    size = s;
    cells = new char*[size];        //All cells are set to blank at the beginning.

    for ( int i = 0; i < size; i++) //initialize pointer n pointer arrays to the size of the
        cells[i] = new char[size];  //board

    for (int i = 0; i < size; i++)  //this loop sets all the cells initial state to a black cell 'b'
         for (int j = 0; j < size; j++)
            cells[i][j] = 'b';


    csHeads = new CrossSumHead[100];    //This can be dynamic but for this case we set it to
                                        //100 as that is the most hints we will handle
    csValues = new CrossSumValue[size*size];    //There will be no more than nxn values possible
                                                //for any one puzzle

    solvable = false;               //Initial state for every puzzle is that it is unsolvable
                                    //Which is most definitely true for a blank puzzle
    numHeads = 0, numValues = 0;    //We start off with no hints and no values
}

CrossSumPuzzle::~CrossSumPuzzle()
//Deconstructor - we ensure that we de-allocate memory for the cells, values and heads
{
    delete [] cells;
    delete [] csValues;
    delete [] csHeads;
}

void CrossSumPuzzle::solve()
//This function simply just runs the solver. Initially it creates the output file using
//the overloaded ostream operator then calls clingo with the logic program and then reads
//in from the output file to the values
{
    std::ofstream out;
    out.open("cpuz.txt");
    out << *this;
    out.close();

    system("clingo crosssumslogic.lp cpuz.txt | mkatoms > out.txt");

    std::ifstream in;
    in.open("out.txt");
    in >> *this;
    in.close();
}

std::istream& CrossSumPuzzle::inputPuzzle(std::istream& in)
//This function lets us read in puzzle heads from a stream provided from the function
//call and passes it back to the calling function.
{
    int curInt, row, col; //these values will hold the current row/column and value from the stream
    char curChar;   //This reads in the current direction found from the stream
    bool test = true;

    if (in.eof())   //I initially check if the file is empty, if so, return the stream.
        return in;

    while (test) {  //Test is initially true but set to false if an eof is reached by the secondary while loop

        while(!in.eof() && in.peek() != 'h') //This loop pulls characters from the stream until we reach 'h' or the end
        {   in.get();}

        if (in.eof())   //If we've hit the end instead of a new head, then the conditions for the while loop are set to false
             test = false;
        else if(in.peek() == 'h'){  //Otherwise we see the beginning of a head, increment the head number and bypass the rule name.
            numHeads++;
            for (int i = 0; i<5;i++)
               in.get();

            //We now read in the head and set all of it's attributes
            in >> curInt;
            csHeads[numHeads].setValue(&curInt);
            in.get();
            in >> curInt;
            row = curInt;
            csHeads[numHeads].setRow(&curInt);
            in.get();
            in >> curInt;
            col = curInt;
            csHeads[numHeads].setColumn(&curInt);
            in.get();
            in >> curInt;
            csHeads[numHeads].setLength(&curInt);
            in.get();
            in >> curChar;
            csHeads[numHeads].setDirection(&curChar);
            csHeads[numHeads].setId(&numHeads);
            cells[row][col] = 'h';

                //This function was to set all of the attributes for the corresponding value range, but
                //it came with unexpected results when drawing the puzzle

            /*qDebug() << csHeads[numHeads].getDirection() << csHeads[numHeads].getLength() << row << col;
            if (csHeads[numHeads].getDirection() == 'r')
                for (int  i= col+1; i < (col + csHeads[numHeads].getLength()); i++)
                    cells[row][i] = 'v';
            else if (csHeads[numHeads].getDirection() == 'c')
                for (int i = col+1; i < (row + csHeads[numHeads].getLength()); i++)
                    cells[i][col] = 'v';*/
            }
    }

    return in;
}

char CrossSumPuzzle::cellType(int* r, int* c)
//this function returns the type of cell that is referenced by the index
//All cells start out as black, but may be set to head or value cell later on
//by the inputHead function. This lets us know whether it is safe to input
//a new head at a specific location or not.
{
    return cells[*r][*c];
}

bool CrossSumPuzzle::inputHead(int* v, int* r, int* c, int* l, char* d)
//this function allows us to input a new head or change an existing head
//It validates that the inputs are permissible then will insert the head
//into the appropriate location or modify an existing head. It will increment
//the number of heads variable if it is appropriate.
{
    //Right now the limit for the number of hints to 100, although you could
    //potentially have it dynamic to the size. Also, if a cell is set to be a value cell
    //then it cannot be a black or head cell since another head has claimed it or a part of another head's value.
    //We also verify that the length selected for the hint is valid, and neither row
    //or column is out of range. It also checks the value selected to ensure it isn't out
    //of range for the length of cells selected, lengths of 2-9 are the only valid
    //lengths
    if (numHeads == 100 || cells[*r][*c] == 'v' || !isValidHead(*v,*l) ||
            (*d == 'r' && *r == 0) || (*d == 'c' && *c == 0))
        return false;
    else if (*d == 'r' && ((*c + *l) >= size || *r < 0 || *l < 2 || *c < 0 || *c > size) )
        return false;
    else if (*d == 'c' && ((*r + *l) >= size || *c < 0 || *l < 2 || *r < 0 || *r > size) )
        return false;
    else if (*d == 'r')
        for (int i = *c+1; i <= (*c + *l); i++)
            if (cells[*r][i] == 'h')
                return false;
    else if (*d == 'c')
        for (int i = *c+1; i <= (*r + *l); i++)
            if (cells[i][*c] == 'h')
                return false;

    int i;
    CrossSumHead *tempHead;     //We initialize a head pointer to allow us to dynamically
                                //allocate then delete a head and save it to the array

    if (cells[*r][*c] == 'b')
        //If the cell we are looking to add a hint to is already black, we then increment the head count
        //create a new head and save it to the array and deallocate the memory from the temporary head.
        //We also mark the cell as a head.
    {
        numHeads++;
        tempHead = new CrossSumHead(v,r,c,l,d, &numHeads);
        csHeads[numHeads] = *tempHead;
        cells[*r][*c] = 'h';
        delete tempHead;
    }
    else if (found(*r,*c,*d,i) && cells[*r][*c] == 'h')
        //If we find that the cell already has a head and it is in the same direction as the one
        //that we are adding, we save it to the array at the found location
    {
        tempHead = new CrossSumHead(v,r,c,l,d,&i);
        csHeads[i] = *tempHead;
        delete tempHead;
    } else if (cells[*r][*c] == 'h')
        //If the cell is a head but the direction doesn't match (which was covered in the previous
        //conditional, then we add a new head and create a new ID by incrementing the number of heads.
    {
        numHeads++;
        tempHead = new CrossSumHead(v,r,c,l,d,&numHeads);
        csHeads[numHeads] = *tempHead;
        delete tempHead;
    }

    //Since the puzzle depends on the value of each cell in our 2d array, we need to ensure that we
    //set any cell in the range of the length to a value cell, this prevents us from setting it as a head
    //by the first rules in the function. We return true to the calling program to let it know it succeeded.
    if (*d == 'r')
        for (int i = *c+1; i <= (*c + *l); i++)
            cells[*r][i] = 'v';
    else if (*d == 'c')
        for (int i = *c+1; i <= (*r + *l); i++)
            cells[i][*c] = 'v';
    return true;
}

bool CrossSumPuzzle::isValidHead(int v, int l)
//Heads must fall into certain ranges to be valid for a cross sums puzzle and this function will allow
//us to check if head selected is valid, otherwise it is false.
{
    if(l == 2 && v >= 3 && v <=17)
        return true;
    if(l == 3 && v >= 6 && v <=24)
        return true;
    if(l == 4 && v >= 10 && v <=30)
        return true;
    if(l == 5 && v >= 15 && v <=35)
        return true;
    if(l == 6 && v >= 21 && v <=39)
        return true;
    if(l == 7 && v >= 28 && v <=42)
        return true;
    if(l == 8 && v >= 36 && v <=44)
        return true;
    if(l == 9 && v >= 45 && v <=45)
        return true;
    return false;
}

bool CrossSumPuzzle::found(int r, int c, char d, int &index)
//This puzzle will attempt to find a head and return true if it does. I modified the
//value of the passed index to return the value of the index to the calling function
{
    for (int i = 0; i < numHeads; i++)
    {
        if (csHeads[i].getRow() == r && csHeads[i].getColumn() == c && csHeads[i].getDirection() == d)
        {
            index = i;
            return true;
        }
    }
    return false;
}

bool CrossSumPuzzle::removeHead(int *r, int*c, char *d)
//This function will remove a head if found, and set the cell to black if there is not a head
//found which runs in the opposite direction of the head we are looking at which shares the same
//cell. It decrements the number of heads after moving the highest # head to the old head's position
//and adjusting it's id appropriately as long as there are still heads to remove, if the number
//of heads is zero or the head is not found, the function will be false
{
    int i = 0;
    char f;
    if (*d == 'c')
        f = 'r';
    else
        f = 'c';

    if (found(*r,*c,*d,i))
    {
        if (!found(*r,*c,f,i))
            cells[*r][*c] = 'b';
        if (numHeads > 0)
        {
            csHeads[i] = csHeads[numHeads];
            csHeads[i].setId(&i);
            numHeads--;
            return true;
        }
    }
    return false;
}

bool CrossSumPuzzle::validValue(int *v, int *r, int *c)
//This function is only run after reading in output from the solver - if the user wants to try
//to solve the puzzle themselves, this will provide testing of their input against the actual
//results of solver. If their answer is wrong or their puzzle has no solution, the result is false
//otherwise, it is true.
{
    if (cells[*r][*c] != 'v' || !isSolvable())
        return false;
    else
    {
        for (int i = 0; i <= numValues; i++)
            if (csValues[i].getValue() == *v && csValues[i].getRow() == *r && csValues[i].getColumn() == *c)
                return true;
    }
    return false;
}

int CrossSumPuzzle::getHeadValue(int *r, int *c, char *d)
//This initially finds the head (if one exists) and then retrieves it's value, otherwise it returns 0;
{
    int id =0;

    if(found(*r,*c,*d,id))
        return csHeads[id].getValue();

    return 0;
}

int CrossSumPuzzle::getHeadLength(int *r, int *c, char *d)
//This initially finds the head (if one exists) and then retrieves it's length, otherwise it returns 0;
{
    int id = 0;

    if(found(*r,*c,*d,id))
        return csHeads[id].getLength();

    return 0;
}

int CrossSumPuzzle::getValue(int *r, int *c)
//This function iterates through the cells if the cell referenced is a value and then returns the value to the calling
//function, otherwise it returns a 0
{
    if (cells[*r][*c] == 'v'){
        for(int i = 0; i<=size*size; i++)
            if(*r == csValues[i].getRow() && *c == csValues[i].getColumn())
                return csValues[i].getValue();
    }
    else
        return 0;
    return 0;
}

ostream& operator<< (ostream& out, const CrossSumPuzzle& cpuz)
//overloaded ostream operator to provide output to a stream for the solver to read in.
{
    out << "row(1.." << cpuz.size-1 << ").\n";       //create the row line
    out << "col(1.." << cpuz.size-1 << ").\n";    //create the column line
    out << "num(1..9).\n";                      //create the valid #'s line, this will always be 1-9

    int i;                                      //For every head, output to the stream
    for (i = 1; i <= cpuz.numHeads;i++)
         out << (cpuz.csHeads[i]);

    out << "head(0,0,0,0,0,0).";
    return out;
}

std::istream& operator>> (std::istream& in, CrossSumPuzzle& cpuz)
//We overload the input operator to read in the solution, if one exists and to set the values.
//If the : is found at the beginning of the file, the puzzle is not solvable and not considered
//a valid crosssums puzzle. otherwise, we are able to read in the solution.
{
    int v, r, c;
    CrossSumValue *tempCsValue;
    if (in.peek() == ':' || in.peek() == '*')//if we find this marker at the beginning of the input, the puzzle isn't valid
            //return the stream and solvable is set to false
    {
        cpuz.solvable = false;
        return in;
    }
    else
        while (in.peek() == 'v')
            //While we see a v in the input stream, we see a new value.
        {
            for (int i = 0; i < 6; i++)
                    //this section skips past the value( portion of the file
                in.get();
                    //We read in the value, row and column and skip the separating commas
            in >> v;
            in.get();
            in >> r;
            in.get();
            in >> c;
                    //we create a new temporary value and then save it to the next entry in the array
                    //and then increment the number of values, this is the only function which can
                    //modify the number of values as this is set by the solver
            tempCsValue = new CrossSumValue(&v,&r,&c);
            cpuz.cells[r][c] = 'v';
            cpuz.csValues[cpuz.numValues] = *tempCsValue;
            delete tempCsValue;
            cpuz.numValues++;
                    //While we have not seen the start of the next value or the end of the model,
                    //keep pulling characters from the stream
            while (in.peek() != 'v' && in.peek() != ':')
                in.get();
         }
        //return the stream and set solvable to true
    cpuz.solvable = true;

    return in;
}
