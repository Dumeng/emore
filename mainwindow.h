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

    void on_actionQuit_triggered();

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
    QGraphicsLineItem *trackLine;
	QProgressDialog* pDlg;
	QProgressBar* pPB;
    BOOL lineTracking;

	affdexThread *Taffdex;

	QString currentFile;
	int videoFrames;
	Face *frame;
	Face currentFace;

	void removeLinesData();
    void updateRadar(const Face face);
    void updateDetails(const Face &face);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

signals:
	void stopProcessSignal();
	void ProcessVideoSignal(QString path);
	void testWSignal();
};

#endif // MAINWINDOW_H
