#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <QDialog>

namespace Ui {
    class invalidInput;
}

class invalidInput : public QDialog
//This is Hal 9000, in dialog form (it's just a modal error box)
{
    Q_OBJECT

public:
    explicit invalidInput(QWidget *parent = 0);
    ~invalidInput();

private:
    Ui::invalidInput *ui;
};

#endif // INVALIDINPUT_H
