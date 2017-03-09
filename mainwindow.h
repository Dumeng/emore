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
	void testWSlot(qint64 a);
	void finishedSlot(std::exception e, float t);

	private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_6_clicked();

	void on_DetailsTable_cellClicked(int row, int column);

	void on_actionQuit_triggered();

	void on_pushButton_5_clicked();

	void setMediaDuration(qint64 t);

	void on_PlayProgressBar_sliderMoved(int position);

	void on_timer_timeout();

	void updateProgressBar();

	void on_pushButton_8_clicked();

private:
	Ui::MainWindow *ui;

	QChart *chartLine;
	QPolarChart *chartRadar;
	QChart *chartBar;
	QMediaPlayer *player;
	QGraphicsVideoItem *videoItem;
	QBarSeries *seriesBar;
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
	BOOL lineTracking = false;

	affdexThread *Taffdex;

	QString currentFile;
	int videoFrames = 0;
	qint64 duration = 0;
	Face *frame;
	Face currentFace;
	QTimer *playerSliderTimer;
	QTimer *playerUpdateTimer;

	void removeLinesData();
	void updateRadar(const Face face);
	void updateDetails(const Face &face);
	void repaintBar();

protected:
	bool eventFilter(QObject *watched, QEvent *event);

signals:
	void stopProcessSignal();
	void ProcessVideoSignal(QString path);
	void testWSignal();
};

#endif // MAINWINDOW_H
