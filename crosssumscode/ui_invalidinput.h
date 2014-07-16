/********************************************************************************
** Form generated from reading UI file 'invalidinput.ui'
**
** Created: Thu Aug 4 19:04:53 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVALIDINPUT_H
#define UI_INVALIDINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_invalidInput
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *invalidInput)
    {
        if (invalidInput->objectName().isEmpty())
            invalidInput->setObjectName(QString::fromUtf8("invalidInput"));
        invalidInput->resize(138, 100);
        invalidInput->setMinimumSize(QSize(138, 100));
        invalidInput->setMaximumSize(QSize(138, 100));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../DANGER.ico"), QSize(), QIcon::Normal, QIcon::Off);
        invalidInput->setWindowIcon(icon);
        invalidInput->setModal(true);
        label = new QLabel(invalidInput);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(5, 10, 121, 41));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        pushButton = new QPushButton(invalidInput);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 60, 51, 23));

        retranslateUi(invalidInput);
        QObject::connect(pushButton, SIGNAL(clicked()), invalidInput, SLOT(accept()));

        QMetaObject::connectSlotsByName(invalidInput);
    } // setupUi

    void retranslateUi(QDialog *invalidInput)
    {
        invalidInput->setWindowTitle(QApplication::translate("invalidInput", "INVALID HEAD INPUT", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("invalidInput", "I'm sorry, Dave, I'm afraid I can't do that.", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("invalidInput", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class invalidInput: public Ui_invalidInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVALIDINPUT_H
