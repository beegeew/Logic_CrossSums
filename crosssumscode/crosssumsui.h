#ifndef CROSSSUMSUI_H
#define CROSSSUMSUI_H

#include "includes.h"
#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
    class CrossSumsUI;
}

class CrossSumsUI : public QMainWindow
//This is the gui, it has a default constructor and destructor, functions for
//every button and menu item and private functions for inputing heads and values.
//The only public data is the constructor and deconstructor
{
    Q_OBJECT

public:
    explicit CrossSumsUI(QWidget *parent = 0);
    ~CrossSumsUI();

private slots:
    void on_actionWhat_is_Cross_Sums_triggered();
    void on_actionExit_triggered();

    //puzzle loading buttons for examples of puzzles I preloaded
    void on_PuzEasy_clicked();
    void on_PuzMed_clicked();
    void on_PuzHard_clicked();

    //input a value to the board and load a head from saved values
    void input(int,int);
    void loadHeads();

    //clear, save and solve button functions
    void on_Solve_clicked();
    void on_Save_clicked();
    void on_Clear_clicked();

    //menu entries for the same options, show the user so desire to click these instead
    //they just call the button functions
    void on_actionClear_Entries_triggered();
    void on_actionSave_Clues_triggered();
    void on_actionSolve_triggered();

private:
    //private ui and puzzle
    Ui::CrossSumsUI *ui;
    CrossSumPuzzle  *cpuz;
};

#endif // CROSSSUMSUI_H

