#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtCharts>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include "AffdexThread.h"

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

public slots:
    void FrameDataUpdateSlot(Face face, long count);
    void testWSlot();
    void finishedSlot(std::exception e, float t);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_DetailsTable_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;

	QChart *chartLine;
	QPolarChart *chartRadar;
	QMediaPlayer *player;
	QGraphicsVideoItem *videoItem;
    QAreaSeries *seriesArea;
    QLineSeries *seriesRadar;
    QLineSeries *seriesLineAnger;
    QLineSeries *seriesLineDisgust;
    QLineSeries *seriesLineFear;
    QLineSeries *seriesLineJoy;
    QLineSeries *seriesLineSadness;
    QLineSeries *seriesLineSurprise;
    QProgressDialog* pDlg;
    QProgressBar* pPB;

	affdexThread *Taffdex;

    QString currentFile;
    int videoFrames;
    Face *frame;
    Face currentFace;

    void removeLinesData();
    void updateRadar(Face &face);
    void updateDetails(Face &face);

signals:
	void stopProcessSignal();
    void ProcessVideoSignal(QString path);
    void testWSignal();
};

#endif // MAINWINDOW_H
