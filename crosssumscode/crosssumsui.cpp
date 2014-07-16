#include "crosssumsui.h"
#include "ui_crosssumsui.h"
#include "includes.h"

CrossSumsUI::CrossSumsUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CrossSumsUI)
//the constructor creates a new UI, sets up the signal from the table widget to the input
//function and creates all the table widget items and sets the background to black and
//text to white (this is default for black and head cells)
{
    ui->setupUi(this);

    cpuz = new CrossSumPuzzle(14);
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(input(int,int)));

    int i,j;
    for (i = 0; i <14;i++)
        for(j = 0;j<14;j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem);
            ui->tableWidget->item(i,j)->setBackgroundColor(Qt::black);
            ui->tableWidget->item(i,j)->setForeground(Qt::white);
        }
}

CrossSumsUI::~CrossSumsUI()
{
    delete ui;
    delete cpuz;
}

void CrossSumsUI::input(int r, int c)
//This takes in the input from the UI when a cell is clicked. An error box and headinput
//box are dynamically allocated and destroyed at the end of the function. It checks to see the
//solve state of the puzzle and will pop up the input box only if it's a black or head cell
//otherwise, clicking on a head or black cell in a solved state will bring up Hal 9000.
{
    //Setup our error box, variables and get the current cell type
    invalidInput *ii = new invalidInput();
    int v,l,i,od, oldLength;
    char d = cpuz->cellType(&r,&c),d2;
    QString dir;

    //If the cell is black or a head, and can be solved, we enter the loop
    if ( (d == 'b' || d == 'h') && !cpuz->isSolvable())
    {
        //create an input dialog and open it with .exec()
        headinput *hi = new headinput(this);

        //if the status exited with accepted, we have data to read, otherwise, we leave the function
        if(hi->exec() == QDialog::Accepted)
        {
            //since the dialog is not destroyed yet, the values persist and we can now retrieve them
            hi->getValues(&v,&l,&dir);
            //this sets the direction character
            if (dir == "Row")
                d = 'r';
            else if (dir == "Column")
                d = 'c';

            //Get the existing length for this head if needed, toehrwise it will be 0
            oldLength = (cpuz->getHeadLength(&r,&c,&d));

            //if input failed, we show the error box.
            if(!cpuz->inputHead(&v,&r,&c,&l,&d)){
               ii->exec();
            } else if (d == 'r'){
                //if we have a row our second direction is a column
                d2 = 'c';
                //we retrieve the value of the head in the other direction for display purposes
                od = (cpuz->getHeadValue(&r,&c,&d2));

                if ( od == 0) //If there is no value for the other direction, display N\Value
                    ui->tableWidget->item(r,c)->setText(QString("N\\%1").arg(v));
                else            //Otherwise, display colValue\rowValue
                    ui->tableWidget->item(r,c)->setText(QString("%1\\%2").arg(od).arg(v));

                if (oldLength > l){
                    //if the old length is longer than the current, we reset the colors
                    //having a value id here would be helpful though to avoid resetting
                    //cells which are affected by another head
                    for ( i = (c+l+1); i<=(c+oldLength); i++)
                        ui->tableWidget->item(r,i)->setBackgroundColor(Qt::black);
                        ui->tableWidget->item(r,i)->setForeground(Qt::white);
                } else
                    for(i = c+1; i <= c+l;i++){
                        //value cells are black text on a white background
                    ui->tableWidget->item(r,i)->setBackgroundColor(Qt::white);
                    ui->tableWidget->item(r,i)->setForeground(Qt::black);
                }
            } else if (d == 'c'){
                //Same as row section except the row is the other value we concern ourselves with
                d2 = 'r';
                od = (cpuz->getHeadValue(&r,&c,&d2));

                if ( od == 0)
                    ui->tableWidget->item(r,c)->setText(QString("%1\\N").arg(v));
                else
                    ui->tableWidget->item(r,c)->setText(QString("%1\\%2").arg(v).arg(od));

                if (oldLength > l){
                    for ( i = (r+l+1); i<=(r+oldLength); i++)
                        ui->tableWidget->item(i,c)->setBackgroundColor(Qt::black);
                        ui->tableWidget->item(i,c)->setForeground(Qt::white);
                }

                for(i = r+1; i<= r+l;i++){
                    ui->tableWidget->item(i,c)->setBackgroundColor(Qt::white);
                    ui->tableWidget->item(i,c)->setForeground(Qt::black);
                }
            }
            //cleanup memory from the dialog box
           delete hi;
        }
    } else if (d == 'b' || d == 'h')
        //this is triggered only on a solved puzzle, value cells are the only ones which can be used now.
    {
        ii->exec();
    }
    //clean up memory from error dialog
    delete ii;
}

void CrossSumsUI::on_PuzEasy_clicked()
//This function loads my pre-defined easy puzzle into a stream, inputs the puzzle, closes the
//stream and then loads the heads for display. The function will first run the clear function
//which resets the puzzle state completely.
{
    on_Clear_clicked();

    std::ifstream easyPuz;
    easyPuz.open("crosssumsmidlychallengingpuzzle1.lp");

    cpuz->inputPuzzle(easyPuz);

    easyPuz.close();

    loadHeads();
}

void CrossSumsUI::on_PuzMed_clicked() //same as easy
{
    on_Clear_clicked();

    std::ifstream medPuz;
    medPuz.open("crosssumsmoderatelychallenging50.lp");

    cpuz->inputPuzzle(medPuz);

    medPuz.close();

    loadHeads();
}

void CrossSumsUI::on_PuzHard_clicked() //same as easy
{
    on_Clear_clicked();

    std::ifstream hardPuz;
    hardPuz.open("crosssumsinsanepuzzle99.lp");

    cpuz->inputPuzzle(hardPuz);

    hardPuz.close();

    loadHeads();
}

void CrossSumsUI::loadHeads()
//This function iterates through the cells 1 by 1 and sets the color and data up in the cell
//it gets the values for heads in both directions at the same time to facilitate easy display
//It also sets the color of the corresponding value cells accordingly.
{
    //setup all of our variables and direction chars
    int i,j,k,vr,vc,lr,lc;
    char dr = 'r',dc = 'c';

    //iterate through the entire nxn table
    for (i = 0; i<14;i++)
        for(j = 0; j<14;j++)
        {
            //if we see a head, get the value and length (remember in a direction for which there is
            //no head, the result is 0.
            if((cpuz->cellType(&i,&j)) == 'h'){
                vr = (cpuz->getHeadValue(&i,&j,&dr));
                lr = (cpuz->getHeadLength(&i,&j,&dr));
                vc = (cpuz->getHeadValue(&i,&j,&dc));
                lc = (cpuz->getHeadLength(&i,&j,&dc));

                //Display the value according to which is a valid head.
                if(vr != 0 && vc != 0)
                    ui->tableWidget->item(i,j)->setText(QString("%1\\%2").arg(vc).arg(vr));
                else if (vr == 0 && vc != 0)
                    ui->tableWidget->item(i,j)->setText(QString("%1\\N").arg(vc));
                else if (vr != 0 && vc == 0)
                    ui->tableWidget->item(i,j)->setText(QString("N\\%1").arg(vr));
                if (vr != 0)
                    //Setup the colors for values for a row head
                    for(k = j+1; k<= j+lr; k++){
                        ui->tableWidget->item(i,k)->setBackgroundColor(Qt::white);
                        ui->tableWidget->item(i,k)->setForeground(Qt::black);
                } else if (vc != 0)
                    //SEtup the colors for values for a column head
                    for(k = i+1; k<= i+lc; k++){
                        ui->tableWidget->item(k,j)->setBackgroundColor(Qt::white);
                        ui->tableWidget->item(k,j)->setForeground(Qt::black);
                    }
            }
        }
}

void CrossSumsUI::on_Solve_clicked()
//If solve is clicked, check to see if the solver was successful, if not, display an error.
//Since the save button does the actual solving, this will already be set. The show the value
//for every value cell.
{
    if (!cpuz->isSolvable()){
        invalidInput *ii = new invalidInput();
        ii->exec();
        delete ii;
    } else
    {   int i,j,v;
        //We iterate through the cells and get the values for any value cell and then display
        //it in the appropriate tablewidgetitem.
        for (i = 0;i<14;i++)
            for (j = 0; j<14;j++)
                if((cpuz->cellType(&i,&j)) == 'v'){
                    v = cpuz->getValue(&i,&j);
                    ui->tableWidget->item(i,j)->setText(QString("%1").arg(v));
                    ui->tableWidget->item(i,j)->setForeground(Qt::black);
                }
    }
}

void CrossSumsUI::on_Save_clicked()
//This runs the solver and will put the puzzle into an uneditable state (As far as heads go).
//It checks to see if it was able to solve, if not, Hal 9000 will inform you that it did not
//go as you had planned.
{
    cpuz->solve();
    if(!cpuz->isSolvable())
    {
        invalidInput *ii = new invalidInput();
        ii->exec();
        delete ii;
    }
}

void CrossSumsUI::on_Clear_clicked()
//Clear deletes the cpuz and sets it back up in a clean state as the constructor initially did.
{
    delete cpuz;
    cpuz = new CrossSumPuzzle(14);

    int i,j;
    for (i = 0; i <14;i++)
        for(j = 0;j<14;j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem);
            ui->tableWidget->item(i,j)->setBackgroundColor(Qt::black);
            ui->tableWidget->item(i,j)->setForeground(Qt::white);
        }
}

void CrossSumsUI::on_actionClear_Entries_triggered()
//runs the clear function - this is for the menu item
{
    on_Clear_clicked();
}


void CrossSumsUI::on_actionSave_Clues_triggered()
//runs save function - this is the menu item
{
    on_Save_clicked();
}

void CrossSumsUI::on_actionSolve_triggered()
//runs solve function - this is the menu item
{
    on_Solve_clicked();
}

void CrossSumsUI::on_actionWhat_is_Cross_Sums_triggered()
//Menu item which opens up a website to read about how to play.
{
    QDesktopServices::openUrl(QUrl("http://www.kakuro.com/howtoplay.php"));
}

void CrossSumsUI::on_actionExit_triggered()
//Leaves the game.
{
    QApplication::exit();
}
