/********************************************************************************
** Form generated from reading UI file 'headinput.ui'
**
** Created: Thu Aug 4 18:43:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADINPUT_H
#define UI_HEADINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_headinput
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *direction;
    QSpinBox *value;
    QSpinBox *length;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *headinput)
    {
        if (headinput->objectName().isEmpty())
            headinput->setObjectName(QString::fromUtf8("headinput"));
        headinput->resize(175, 168);
        headinput->setMinimumSize(QSize(175, 168));
        headinput->setMaximumSize(QSize(175, 168));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        headinput->setWindowIcon(icon);
        headinput->setModal(true);
        buttonBox = new QDialogButtonBox(headinput);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 120, 161, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        direction = new QComboBox(headinput);
        direction->setObjectName(QString::fromUtf8("direction"));
        direction->setGeometry(QRect(10, 90, 69, 22));
        value = new QSpinBox(headinput);
        value->setObjectName(QString::fromUtf8("value"));
        value->setGeometry(QRect(30, 10, 42, 22));
        value->setMinimum(3);
        value->setMaximum(45);
        length = new QSpinBox(headinput);
        length->setObjectName(QString::fromUtf8("length"));
        length->setGeometry(QRect(30, 50, 42, 22));
        length->setMinimum(2);
        length->setMaximum(9);
        label = new QLabel(headinput);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 10, 46, 13));
        label_2 = new QLabel(headinput);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 50, 46, 21));

        retranslateUi(headinput);
        QObject::connect(buttonBox, SIGNAL(accepted()), headinput, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), headinput, SLOT(reject()));

        QMetaObject::connectSlotsByName(headinput);
    } // setupUi

    void retranslateUi(QDialog *headinput)
    {
        headinput->setWindowTitle(QApplication::translate("headinput", "Header Input", 0, QApplication::UnicodeUTF8));
        direction->clear();
        direction->insertItems(0, QStringList()
         << QApplication::translate("headinput", "Row", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("headinput", "Column", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("headinput", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Value</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("headinput", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Length</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class headinput: public Ui_headinput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADINPUT_H
