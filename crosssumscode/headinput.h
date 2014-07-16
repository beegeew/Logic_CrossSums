#ifndef HEADINPUT_H
#define HEADINPUT_H

#include <QDialog>
#include <QSpinBox>
#include <QComboBox>
#include <QString>
#include "includes.h"

namespace Ui {
    class headinput;
}

//This class creates the input dialog box which captures information from the
//getValues function which to the calling function the length and direction chosen by
//the user
class headinput : public QDialog
{
    Q_OBJECT

public:
    explicit headinput(QWidget *parent = 0);
    void getValues(int*,int*,QString*);
    ~headinput();

private slots:

private:
    Ui::headinput *ui;

};

#endif // HEADINPUT_H
