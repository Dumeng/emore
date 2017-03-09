/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QAction *actionQuit;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QGraphicsView *MediaView;
    QTreeWidget *QuestionsTree;
    QTableWidget *DetailsTable;
    QChartView *ChartViewRadar;
    QChartView *ChartViewLine;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSlider *PlayProgressBar;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        QPalette palette;
        QBrush brush(QColor(178, 235, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        MainWindow->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        MainWindow->setFont(font);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 245);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(480, 120, 93, 41));
        QPalette palette1;
        QBrush brush1(QColor(195, 224, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        pushButton->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QStringLiteral("background-color:rgb(195,224,255)"));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        MediaView = new QGraphicsView(centralWidget);
        MediaView->setObjectName(QStringLiteral("MediaView"));
        MediaView->setGeometry(QRect(609, 9, 661, 491));
        QuestionsTree = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        QuestionsTree->setHeaderItem(__qtreewidgetitem);
        QuestionsTree->setObjectName(QStringLiteral("QuestionsTree"));
        QuestionsTree->setEnabled(false);
        QuestionsTree->setGeometry(QRect(340, 340, 261, 351));
        DetailsTable = new QTableWidget(centralWidget);
        DetailsTable->setObjectName(QStringLiteral("DetailsTable"));
        DetailsTable->setGeometry(QRect(10, 340, 321, 351));
        ChartViewRadar = new QChartView(centralWidget);
        ChartViewRadar->setObjectName(QStringLiteral("ChartViewRadar"));
        ChartViewRadar->setGeometry(QRect(10, 10, 320, 320));
        ChartViewRadar->setStyleSheet(QStringLiteral(""));
        ChartViewLine = new QChartView(centralWidget);
        ChartViewLine->setObjectName(QStringLiteral("ChartViewLine"));
        ChartViewLine->setGeometry(QRect(610, 500, 661, 191));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 120, 93, 41));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QStringLiteral("background-color:rgb(195,224,255)"));
        pushButton_2->setFlat(false);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 50, 93, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        pushButton_3->setPalette(palette2);
        pushButton_3->setFont(font1);
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QStringLiteral("background-color:rgb(195,224,255)"));
        pushButton_3->setAutoDefault(false);
        pushButton_3->setFlat(false);
        PlayProgressBar = new QSlider(centralWidget);
        PlayProgressBar->setObjectName(QStringLiteral("PlayProgressBar"));
        PlayProgressBar->setEnabled(true);
        PlayProgressBar->setGeometry(QRect(619, 475, 641, 22));
        PlayProgressBar->setOrientation(Qt::Horizontal);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setGeometry(QRect(480, 260, 93, 41));
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QStringLiteral("border-color: rgb(156, 229, 255);"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(370, 50, 93, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        pushButton_4->setPalette(palette3);
        pushButton_4->setFont(font1);
        pushButton_4->setFocusPolicy(Qt::NoFocus);
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QStringLiteral("background-color:rgb(195,224,255)"));
        pushButton_4->setAutoDefault(false);
        pushButton_4->setFlat(false);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setEnabled(false);
        pushButton_5->setGeometry(QRect(480, 190, 93, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        pushButton_5->setPalette(palette4);
        pushButton_5->setFont(font1);
        pushButton_5->setFocusPolicy(Qt::NoFocus);
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setStyleSheet(QStringLiteral("background-color:rgb(195,224,255)"));
        pushButton_5->setAutoDefault(false);
        pushButton_5->setFlat(false);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(370, 190, 93, 41));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        pushButton_6->setPalette(palette5);
        pushButton_6->setFont(font1);
        pushButton_6->setFocusPolicy(Qt::NoFocus);
        pushButton_6->setAutoFillBackground(false);
        pushButton_6->setStyleSheet(QStringLiteral("background-color:rgb(195,224,255)"));
        pushButton_6->setAutoDefault(false);
        pushButton_6->setFlat(false);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setEnabled(false);
        pushButton_7->setGeometry(QRect(370, 260, 93, 41));
        QPalette palette6;
        QBrush brush2(QColor(255, 255, 245, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_7->setPalette(palette6);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_7->setFont(font2);
        pushButton_7->setFocusPolicy(Qt::NoFocus);
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setStyleSheet(QStringLiteral(""));
        pushButton_7->setAutoDefault(false);
        pushButton_7->setFlat(false);
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setEnabled(true);
        pushButton_8->setGeometry(QRect(290, 20, 30, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font3.setPointSize(18);
        pushButton_8->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        comboBox->raise();
        ChartViewRadar->raise();
        pushButton->raise();
        QuestionsTree->raise();
        DetailsTable->raise();
        ChartViewLine->raise();
        MediaView->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        PlayProgressBar->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_8->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addSeparator();
        menu->addAction(actionQuit);

        retranslateUi(MainWindow);

        pushButton->setDefault(false);
        pushButton_3->setDefault(false);
        pushButton_4->setDefault(false);
        pushButton_5->setDefault(false);
        pushButton_6->setDefault(false);
        pushButton_7->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "eMore", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\206\346\236\220", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\210\206\346\236\220", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\346\222\255 \346\224\276", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\201\234 \346\255\242", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\211\223 \345\274\200", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\210\206 \346\236\220", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Disabled", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "\345\205\263 \344\272\216", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "Disabled", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "\342\207\206", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
