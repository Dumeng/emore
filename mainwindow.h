#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets>
#include <QtCharts>
#include <QtMultimediaWidgets>
#include "affdex.h"

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

	QChart *chartLine;
	QPolarChart *chartRadar;
	QMediaPlayer *player;
	QGraphicsVideoItem *videoItem;
};

#endif // MAINWINDOW_H
