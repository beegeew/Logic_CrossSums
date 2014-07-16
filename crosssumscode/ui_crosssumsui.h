/********************************************************************************
** Form generated from reading UI file 'crosssumsui.ui'
**
** Created: Thu Aug 4 13:09:54 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CROSSSUMSUI_H
#define UI_CROSSSUMSUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CrossSumsUI
{
public:
    QAction *actionClear_Entries;
    QAction *actionSolve;
    QAction *actionWhat_is_Cross_Sums;
    QAction *actionVersion_0_2;
    QAction *actionExit;
    QAction *actionSave_Clues;
    QWidget *centralWidget;
    QPushButton *Clear;
    QPushButton *Solve;
    QPushButton *Save;
    QTableWidget *tableWidget;
    QRadioButton *PuzEasy;
    QRadioButton *PuzMed;
    QRadioButton *PuzHard;
    QMenuBar *menuBar;
    QMenu *menuCross_Sums_Solver;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CrossSumsUI)
    {
        if (CrossSumsUI->objectName().isEmpty())
            CrossSumsUI->setObjectName(QString::fromUtf8("CrossSumsUI"));
        CrossSumsUI->resize(580, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CrossSumsUI->sizePolicy().hasHeightForWidth());
        CrossSumsUI->setSizePolicy(sizePolicy);
        CrossSumsUI->setMinimumSize(QSize(580, 620));
        CrossSumsUI->setMaximumSize(QSize(580, 620));
        QFont font;
        font.setPointSize(8);
        CrossSumsUI->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CrossSumsUI->setWindowIcon(icon);
        actionClear_Entries = new QAction(CrossSumsUI);
        actionClear_Entries->setObjectName(QString::fromUtf8("actionClear_Entries"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../gnome_session_reboot.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear_Entries->setIcon(icon1);
        actionSolve = new QAction(CrossSumsUI);
        actionSolve->setObjectName(QString::fromUtf8("actionSolve"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../gnome_color_chooser.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSolve->setIcon(icon2);
        actionWhat_is_Cross_Sums = new QAction(CrossSumsUI);
        actionWhat_is_Cross_Sums->setObjectName(QString::fromUtf8("actionWhat_is_Cross_Sums"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../help_and_support.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionWhat_is_Cross_Sums->setIcon(icon3);
        actionVersion_0_2 = new QAction(CrossSumsUI);
        actionVersion_0_2->setObjectName(QString::fromUtf8("actionVersion_0_2"));
        actionExit = new QAction(CrossSumsUI);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../gnome_application_exit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionSave_Clues = new QAction(CrossSumsUI);
        actionSave_Clues->setObjectName(QString::fromUtf8("actionSave_Clues"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../1311731968_Gnome-Document-Save-As-64.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Clues->setIcon(icon5);
        centralWidget = new QWidget(CrossSumsUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(580, 560));
        centralWidget->setMaximumSize(QSize(580, 580));
        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(90, 550, 91, 23));
        Clear->setIcon(icon1);
        Solve = new QPushButton(centralWidget);
        Solve->setObjectName(QString::fromUtf8("Solve"));
        Solve->setGeometry(QRect(400, 550, 91, 23));
        Solve->setIcon(icon2);
        Save = new QPushButton(centralWidget);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setGeometry(QRect(250, 550, 91, 23));
        Save->setIcon(icon5);
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 14)
            tableWidget->setColumnCount(14);
        if (tableWidget->rowCount() < 14)
            tableWidget->setRowCount(14);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 40, 562, 492));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ebrima"));
        font1.setPointSize(9);
        tableWidget->setFont(font1);
        tableWidget->setRowCount(14);
        tableWidget->setColumnCount(14);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(40);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(0);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(35);
        tableWidget->verticalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(0);
        PuzEasy = new QRadioButton(centralWidget);
        PuzEasy->setObjectName(QString::fromUtf8("PuzEasy"));
        PuzEasy->setGeometry(QRect(50, 10, 82, 17));
        PuzMed = new QRadioButton(centralWidget);
        PuzMed->setObjectName(QString::fromUtf8("PuzMed"));
        PuzMed->setGeometry(QRect(230, 10, 91, 17));
        PuzHard = new QRadioButton(centralWidget);
        PuzHard->setObjectName(QString::fromUtf8("PuzHard"));
        PuzHard->setGeometry(QRect(440, 10, 82, 17));
        CrossSumsUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CrossSumsUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 580, 19));
        menuCross_Sums_Solver = new QMenu(menuBar);
        menuCross_Sums_Solver->setObjectName(QString::fromUtf8("menuCross_Sums_Solver"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        CrossSumsUI->setMenuBar(menuBar);
        statusBar = new QStatusBar(CrossSumsUI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(false);
        CrossSumsUI->setStatusBar(statusBar);

        menuBar->addAction(menuCross_Sums_Solver->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCross_Sums_Solver->addAction(actionClear_Entries);
        menuCross_Sums_Solver->addAction(actionSave_Clues);
        menuCross_Sums_Solver->addAction(actionSolve);
        menuCross_Sums_Solver->addSeparator();
        menuCross_Sums_Solver->addAction(actionExit);
        menuHelp->addAction(actionWhat_is_Cross_Sums);
        menuHelp->addAction(actionVersion_0_2);

        retranslateUi(CrossSumsUI);
        QObject::connect(PuzEasy, SIGNAL(clicked()), CrossSumsUI, SLOT(setFocus()));
        QObject::connect(PuzMed, SIGNAL(clicked()), CrossSumsUI, SLOT(setFocus()));
        QObject::connect(PuzHard, SIGNAL(clicked()), CrossSumsUI, SLOT(setFocus()));

        QMetaObject::connectSlotsByName(CrossSumsUI);
    } // setupUi

    void retranslateUi(QMainWindow *CrossSumsUI)
    {
        CrossSumsUI->setWindowTitle(QApplication::translate("CrossSumsUI", "Gen's Cross Sums", 0, QApplication::UnicodeUTF8));
        actionClear_Entries->setText(QApplication::translate("CrossSumsUI", "Clear Boxes", 0, QApplication::UnicodeUTF8));
        actionSolve->setText(QApplication::translate("CrossSumsUI", "Solve", 0, QApplication::UnicodeUTF8));
        actionWhat_is_Cross_Sums->setText(QApplication::translate("CrossSumsUI", "What is Cross Sums?", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionWhat_is_Cross_Sums->setToolTip(QApplication::translate("CrossSumsUI", "Need help on how to play? Click me!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionWhat_is_Cross_Sums->setStatusTip(QApplication::translate("CrossSumsUI", "Need help on how to play? Click me!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionWhat_is_Cross_Sums->setShortcut(QApplication::translate("CrossSumsUI", "Help", 0, QApplication::UnicodeUTF8));
        actionVersion_0_2->setText(QApplication::translate("CrossSumsUI", "Version 0.0.01", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("CrossSumsUI", "Exit", 0, QApplication::UnicodeUTF8));
        actionSave_Clues->setText(QApplication::translate("CrossSumsUI", "Save Clues", 0, QApplication::UnicodeUTF8));
        Clear->setText(QApplication::translate("CrossSumsUI", "Clear Boxes", 0, QApplication::UnicodeUTF8));
        Solve->setText(QApplication::translate("CrossSumsUI", "Solve!", 0, QApplication::UnicodeUTF8));
        Save->setText(QApplication::translate("CrossSumsUI", "Save Clues", 0, QApplication::UnicodeUTF8));
        PuzEasy->setText(QApplication::translate("CrossSumsUI", "Easy Puzzle", 0, QApplication::UnicodeUTF8));
        PuzMed->setText(QApplication::translate("CrossSumsUI", "Medium Puzzle", 0, QApplication::UnicodeUTF8));
        PuzHard->setText(QApplication::translate("CrossSumsUI", "Hard Puzzle", 0, QApplication::UnicodeUTF8));
        menuCross_Sums_Solver->setTitle(QApplication::translate("CrossSumsUI", "Cross Sums Solver", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("CrossSumsUI", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CrossSumsUI: public Ui_CrossSumsUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CROSSSUMSUI_H
