/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QGraphicsView *MediaView;
    QTreeWidget *QuestionsTree;
    QTableWidget *DetailsTable;
    QChartView *ChartViewRadar;
    QChartView *ChartViewLine;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        MainWindow->setFont(font);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 245);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 630, 93, 41));
        pushButton->setFont(font);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QStringLiteral(""));
        pushButton->setFlat(true);
        MediaView = new QGraphicsView(centralWidget);
        MediaView->setObjectName(QStringLiteral("MediaView"));
        MediaView->setGeometry(QRect(609, 9, 661, 491));
        QuestionsTree = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        QuestionsTree->setHeaderItem(__qtreewidgetitem);
        QuestionsTree->setObjectName(QStringLiteral("QuestionsTree"));
        QuestionsTree->setGeometry(QRect(19, 20, 261, 300));
        DetailsTable = new QTableWidget(centralWidget);
        DetailsTable->setObjectName(QStringLiteral("DetailsTable"));
        DetailsTable->setGeometry(QRect(300, 20, 300, 261));
        ChartViewRadar = new QChartView(centralWidget);
        ChartViewRadar->setObjectName(QStringLiteral("ChartViewRadar"));
        ChartViewRadar->setGeometry(QRect(290, 299, 320, 320));
        ChartViewLine = new QChartView(centralWidget);
        ChartViewLine->setObjectName(QStringLiteral("ChartViewLine"));
        ChartViewLine->setGeometry(QRect(610, 500, 660, 200));
        MainWindow->setCentralWidget(centralWidget);
        ChartViewRadar->raise();
        pushButton->raise();
        QuestionsTree->raise();
        DetailsTable->raise();
        ChartViewLine->raise();
        MediaView->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\206\346\236\220", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\210\206\346\236\220", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
