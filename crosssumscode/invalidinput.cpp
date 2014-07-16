#include "invalidinput.h"
#include "ui_invalidinput.h"

invalidInput::invalidInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::invalidInput)
{
    ui->setupUi(this);
}

invalidInput::~invalidInput()
{
    delete ui;
}

