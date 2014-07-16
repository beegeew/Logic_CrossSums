#include "headinput.h"
#include "ui_headinput.h"

headinput::headinput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::headinput)
  //constructor for the dialog
{
    ui->setupUi(this);
}

headinput::~headinput()
{
    delete ui;
}

void headinput::getValues(int *v, int *l, QString *d)
//this function records the user input and allows it to be passed back to the calling function
{
    *v = ui->value->value();
    *l = ui->length->value();
    *d = ui->direction->currentText();
}

