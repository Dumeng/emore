#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	//Line Chart
	QLineSeries *series = new QLineSeries();
	for (int i = 0; i <= 30; i++)
		series->append(i, i);

	chartLine = new QChart();
	chartLine->legend()->hide();
	chartLine->addSeries(series);

	QValueAxis *axisY = new QValueAxis();
	axisY->setRange(0, 100);
	axisY->setLabelFormat("%d%%");
	axisY->setTickCount(5);
	chartLine->setAxisY(axisY,series);
	
	//Radar Chart
	const qreal angularMin = 0;
	const qreal angularMax = 6;

	const qreal radialMin = 0;
	const qreal radialMax = 100;

	QLineSeries *series3 = new QLineSeries();
	qreal rd = (radialMax - radialMin) / 3 * 1.3;
	series3->append(0, radialMin + rd);
	series3->append(1, radialMax);
	series3->append(2, radialMin + rd);
	series3->append(3, radialMax);
	series3->append(4, radialMin + rd);
	series3->append(5, radialMax);
	series3->append(6, radialMin + rd);
	//series3->hide();

	QAreaSeries *series5 = new QAreaSeries();
	series5->setUpperSeries(series3);
	series5->setOpacity(0.5);


	chartRadar = new QPolarChart();
	chartRadar->addSeries(series3);
	chartRadar->addSeries(series5);
	chartRadar->legend()->setVisible(false);

	//![2]
	QCategoryAxis *angularAxis = new QCategoryAxis();
	angularAxis->setMin(0);
	angularAxis->setStartValue(0);
	angularAxis->setMax(6);
	angularAxis->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
	angularAxis->append(QString::fromLocal8Bit("恐惧"), 1);
	angularAxis->append(QString::fromLocal8Bit("悲伤"), 2);
	angularAxis->append(QString::fromLocal8Bit("惊讶"), 3);
	angularAxis->append(QString::fromLocal8Bit("厌恶"), 4);
	angularAxis->append(QString::fromLocal8Bit("愤怒"), 5);
	angularAxis->append(QString::fromLocal8Bit("愉悦"), 6);

	chartRadar->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);

	QValueAxis *radialAxis = new QValueAxis();
	radialAxis->setTickCount(3);
	radialAxis->setLabelFormat("%d");
	chartRadar->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);
	//![2]

	series3->attachAxis(radialAxis);
	series3->attachAxis(angularAxis);
	series5->attachAxis(radialAxis);
	series5->attachAxis(angularAxis);

	radialAxis->setRange(radialMin, radialMax);
	angularAxis->setRange(angularMin, angularMax);
	
	ui->ChartViewRadar->setChart(chartRadar);
	ui->ChartViewLine->setChart(chartLine);

	//Media View
	player = new QMediaPlayer(ui->MediaView, QMediaPlayer::VideoSurface);

	videoItem = new QGraphicsVideoItem();
	videoItem->setSize(QSizeF(640, 480));
	player->setVideoOutput(videoItem);
	QGraphicsScene *mediaScene = new QGraphicsScene(this);
	mediaScene->addItem(videoItem);
	ui->MediaView->setScene(mediaScene);
	ui->MediaView->show();
	player->setMedia(QUrl("F:/SRTP/enterface database/subject 1/fear/sentence 3/s1_fe_3.avi"));

	//Detail View
	ui->DetailsTable->setColumnCount(2);
	ui->DetailsTable->setRowCount(10);
	char items[][50] = { "愉悦	Joy", "恐惧	Fear", "厌恶	Disgust",
		"悲伤	Sadness", "愤怒	Anger", "惊讶	Surprise",
		"轻视	Contempt", "投入程度	Valence", "效价	Engagement", " " };
	for (int i = 0; i < 9; i++)
	{
		ui->DetailsTable->setItem(i, 1, new QTableWidgetItem(QString("0")));
		ui->DetailsTable->setItem(i, 0, new QTableWidgetItem(QString::fromLocal8Bit(items[i])));
		ui->DetailsTable->setRowHeight(i, 23);
	}
	ui->DetailsTable->setRowHeight(9, 23);
	ui->DetailsTable->verticalHeader()->hide();
	ui->DetailsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->DetailsTable->setColumnWidth(0, 190);
	ui->DetailsTable->setColumnWidth(1, 108);
	QStringList hHeader;
	hHeader << QString::fromLocal8Bit("项目") << QString::fromLocal8Bit("值");
	ui->DetailsTable->setHorizontalHeaderLabels(hHeader);

	//Question Tree
	ui->QuestionsTree->header()->hide();
	ui->QuestionsTree->addTopLevelItem(new QTreeWidgetItem(ui->QuestionsTree, QStringList(QString::fromLocal8Bit("量表I"))));
	ui->QuestionsTree->topLevelItem(0)->addChild(new QTreeWidgetItem(QStringList(QString::fromLocal8Bit("问题1"))));
	ui->QuestionsTree->topLevelItem(0)->addChild(new QTreeWidgetItem(QStringList(QString::fromLocal8Bit("问题2"))));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	player->play();
}
