#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>

extern "C"
{
#include "libavformat/avformat.h"
}

long start, finish;

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	Taffdex = new affdexThread();
	Taffdex->init();
	ui->setupUi(this);

	qRegisterMetaType<Face>("Face");
	qRegisterMetaType<std::exception>("std::exception");

	connect(Taffdex, SIGNAL(newDataSignal(Face, long)),
		this, SLOT(FrameDataUpdateSlot(Face, long)));
	connect(this, SIGNAL(stopProcessSignal()),
		Taffdex, SLOT(stopProcessSlot()));
	connect(this, SIGNAL(ProcessVideoSignal(QString)),
		Taffdex, SLOT(ProcessVideoSlot(QString)));
	//connect(this, SIGNAL(testWSignal()),
	//	Taffdex, SLOT(testTSlot()));
	//connect(Taffdex, SIGNAL(testTSignal()),
	//	this, SLOT(testWSlot()));
	connect(Taffdex, SIGNAL(finishedSignal(std::exception, float)),
		this, SLOT(finishedSlot(std::exception, float)));

	//Line Chart
	seriesLineAnger = new QLineSeries();
	seriesLineDisgust = new QLineSeries();
	seriesLineFear = new QLineSeries();
	seriesLineJoy = new QLineSeries();
	seriesLineSadness = new QLineSeries();
	seriesLineSurprise = new QLineSeries();
	/*
	for (int i = 0; i <= 3; i++)
	{
	seriesLineAnger->append(i, i);
	seriesLineDisgust->append(i,i*i);
	seriesLineFear->append(i,i*(30-i));
	seriesLineJoy->append(i,30-i);
	seriesLineSadness->append(i,40);
	seriesLineSurprise->append(i,80);
	}
	*/
	///*
	seriesLineAnger->append(0, 0);
	seriesLineDisgust->append(0, 0);
	seriesLineFear->append(0, 0);
	seriesLineJoy->append(0, 0);
	seriesLineSadness->append(0, 0);
	seriesLineSurprise->append(0, 0);
	//*/

	chartLine = new QChart();
	chartLine->legend()->hide();
	chartLine->addSeries(seriesLineJoy);
	chartLine->addSeries(seriesLineFear);
	chartLine->addSeries(seriesLineDisgust);
	chartLine->addSeries(seriesLineSadness);
	chartLine->addSeries(seriesLineAnger);
	chartLine->addSeries(seriesLineSurprise);
	seriesLineAnger->setColor(QColor::fromHsv(240, 240, 216));
	seriesLineDisgust->setColor(QColor::fromHsv(120, 240, 216));
	seriesLineFear->setColor(QColor::fromHsv(60, 240, 216));
	seriesLineJoy->setColor(QColor::fromHsv(0, 240, 216));
	seriesLineSadness->setColor(QColor::fromHsv(180, 240, 216));
	seriesLineSurprise->setColor(QColor::fromHsv(300, 240, 216));

	QValueAxis *axisY = new QValueAxis();
	QValueAxis *axisX = new QValueAxis();
	axisY->setRange(0, 100);
	axisY->setLabelFormat("%d%%");
	axisY->setTickCount(5);
	axisX->setRange(0, 10);
	axisX->setLabelFormat("%d");
	axisX->setTickCount(2);
	chartLine->setAxisY(axisY, seriesLineAnger);
	chartLine->setAxisY(axisY, seriesLineDisgust);
	chartLine->setAxisY(axisY, seriesLineFear);
	chartLine->setAxisY(axisY, seriesLineJoy);
	chartLine->setAxisY(axisY, seriesLineSadness);
	chartLine->setAxisY(axisY, seriesLineSurprise);
	chartLine->setAxisX(axisX, seriesLineAnger);
	chartLine->setAxisX(axisX, seriesLineDisgust);
	chartLine->setAxisX(axisX, seriesLineFear);
	chartLine->setAxisX(axisX, seriesLineJoy);
	chartLine->setAxisX(axisX, seriesLineSadness);
	chartLine->setAxisX(axisX, seriesLineSurprise);

	//Radar Chart
	const qreal angularMin = 0;
	const qreal angularMax = 6;

	const qreal radialMin = 0;
	const qreal radialMax = 100;

	seriesRadar = new QLineSeries();
	qreal rd = (radialMax - radialMin) / 3 * 1.3;
	for (int i = 0; i < 7; i++)
	{
		seriesRadar->append(i, radialMin + rd);
	}

	seriesArea = new QAreaSeries();
	seriesArea->setUpperSeries(seriesRadar);
	seriesArea->setOpacity(0.5);

	chartRadar = new QPolarChart();
	chartRadar->addSeries(seriesRadar);
	chartRadar->addSeries(seriesArea);
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

	seriesRadar->attachAxis(radialAxis);
	seriesRadar->attachAxis(angularAxis);
	seriesArea->attachAxis(radialAxis);
	seriesArea->attachAxis(angularAxis);

	radialAxis->setRange(radialMin, radialMax);
	angularAxis->setRange(angularMin, angularMax);

	chartBar = new QChart();
	seriesBar = new QBarSeries();
	QBarSet *set = new QBarSet(QString::fromLocal8Bit("数值"));
	for (int i = 0; i < 6; i++)
		set->insert(i, 30);
	seriesBar->append(set);
	chartBar->addSeries(seriesBar);
	chartBar->createDefaultAxes();
	((QBarCategoryAxis*)chartBar->axisX())->clear();
	((QBarCategoryAxis*)chartBar->axisX())->append(QString::fromLocal8Bit("愉悦"));
	((QBarCategoryAxis*)chartBar->axisX())->append(QString::fromLocal8Bit("恐惧"));
	((QBarCategoryAxis*)chartBar->axisX())->append(QString::fromLocal8Bit("厌恶"));
	((QBarCategoryAxis*)chartBar->axisX())->append(QString::fromLocal8Bit("悲伤"));
	((QBarCategoryAxis*)chartBar->axisX())->append(QString::fromLocal8Bit("愤怒"));
	((QBarCategoryAxis*)chartBar->axisX())->append(QString::fromLocal8Bit("惊讶"));
	((QValueAxis*)chartBar->axisY())->setRange(0, 100);
	chartBar->legend()->hide();
	((QValueAxis*)chartBar->axisY())->setLabelFormat("%d%%");
	((QBarCategoryAxis*)chartBar->axisX())->setLabelsAngle(-60);
	QFont font = ((QBarCategoryAxis*)chartBar->axisX())->labelsFont();
	font.setPointSize(6);
	((QBarCategoryAxis*)chartBar->axisX())->setLabelsFont(font);

	//qDebug()<<chartBar->childItems().at(19)->childItems().at(i*2+1);


	ui->ChartViewRadar->setChart(chartRadar);
	ui->ChartViewLine->setChart(chartLine);
	QPen mouseLine(QColor(200, 0, 0));
	mouseLine.setWidth(3);
	trackLine = ui->ChartViewLine->scene()->addLine(-4, 35, -4, 150, mouseLine);
	ui->ChartViewLine->scene()->installEventFilter(this);
	lineTracking = true;
	ui->ChartViewLine->setDisabled(true);

	//Media View
	player = new QMediaPlayer(ui->MediaView, QMediaPlayer::VideoSurface);

	videoItem = new QGraphicsVideoItem();
	videoItem->setSize(QSizeF(640, 480));
	player->setVideoOutput(videoItem);
	QGraphicsScene *mediaScene = new QGraphicsScene(this);
	mediaScene->addItem(videoItem);
	ui->MediaView->setScene(mediaScene);
	ui->MediaView->show();
	ui->PlayProgressBar->hide();
	ui->MediaView->installEventFilter(this);
	ui->MediaView->scene()->installEventFilter(this);
	ui->MediaView->setMouseTracking(true);
	playerSliderTimer = new QTimer(this);
	playerUpdateTimer = new QTimer(this);
	playerUpdateTimer->setInterval(40);

	connect(player, SIGNAL(durationChanged(qint64)),
		this, SLOT(setMediaDuration(qint64)));
	connect(playerSliderTimer, SIGNAL(timeout()),
		this, SLOT(on_timer_timeout()));
	//connect(player,SIGNAL(positionChanged(qint64)),ui->PlayProgressBar,SLOT(setValue(int)));
	connect(player, SIGNAL(positionChanged(qint64)),
		this, SLOT(testWSlot(qint64)));
	connect(playerUpdateTimer, SIGNAL(timeout()),
		this, SLOT(updateProgressBar()));
	//connect(ui->PlayProgressBar,SIGNAL(valueChanged(int)),player,SLOT(setPosition(qint64));

	//Detail View
	ui->DetailsTable->setColumnCount(3);
	ui->DetailsTable->setRowCount(10);
	char items[][50] = { "愉悦	Joy", "恐惧	Fear", "厌恶	Disgust",
		"悲伤	Sadness", "愤怒	Anger", "惊讶	Surprise",
		"轻视	Contempt", "投入程度	Valence", "效价	Engagement", " " };
	for (int i = 0; i < 9; i++)
	{
		ui->DetailsTable->setItem(i, 0, new QTableWidgetItem());
		ui->DetailsTable->setItem(i, 2, new QTableWidgetItem(QString("0")));
		ui->DetailsTable->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit(items[i])));
		if (i < 6)
		{
			ui->DetailsTable->item(i, 0)->setCheckState(Qt::Checked);
			ui->DetailsTable->item(i, 1)->setTextColor(QColor::fromHsv(i * 60, 240, 216));
		}
		ui->DetailsTable->setRowHeight(i, 25);
	}
	ui->DetailsTable->setRowHeight(9, 25);
	ui->DetailsTable->verticalHeader()->hide();
	ui->DetailsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->DetailsTable->setColumnWidth(0, 41);
	ui->DetailsTable->setColumnWidth(1, 205);
	ui->DetailsTable->setColumnWidth(2, 65);
	QStringList hHeader;
	hHeader << QString::fromLocal8Bit("显示") << QString::fromLocal8Bit("项目") << QString::fromLocal8Bit("值");
	ui->DetailsTable->setHorizontalHeaderLabels(hHeader);

	//Question Tree
	ui->QuestionsTree->header()->hide();
	ui->QuestionsTree->addTopLevelItem(new QTreeWidgetItem(ui->QuestionsTree, QStringList(QString::fromLocal8Bit("应激及相关行为"))));
	ui->QuestionsTree->topLevelItem(0)->addChild(new QTreeWidgetItem(QStringList(QString::fromLocal8Bit("你是否没有知心朋友，孤独？"))));
	ui->QuestionsTree->topLevelItem(0)->addChild(new QTreeWidgetItem(QStringList(QString::fromLocal8Bit("你是否担心自己无法承担责任？"))));
	ui->QuestionsTree->addTopLevelItem(new QTreeWidgetItem(ui->QuestionsTree, QStringList(QString::fromLocal8Bit("精神评定"))));
	ui->QuestionsTree->topLevelItem(1)->addChild(new QTreeWidgetItem(QStringList(QString::fromLocal8Bit("有过突然说话严重困难？"))));
	ui->QuestionsTree->topLevelItem(1)->addChild(new QTreeWidgetItem(QStringList(QString::fromLocal8Bit("有过突然记忆力严重下降？"))));
	ui->QuestionsTree->addTopLevelItem(new QTreeWidgetItem(ui->QuestionsTree, QStringList(QString::fromLocal8Bit("家庭与人际关系"))));
	ui->QuestionsTree->topLevelItem(2)->addChild(new QTreeWidgetItem(QStringList(QString::fromLocal8Bit("父母是否过分担心你的健康？ "))));
	ui->QuestionsTree->topLevelItem(2)->addChild(new QTreeWidgetItem(QStringList(QString::fromLocal8Bit("是否觉得父亲难以亲近？"))));
	ui->QuestionsTree->topLevelItem(2)->addChild(new QTreeWidgetItem(QStringList(QString::fromLocal8Bit("父母是否尊重你的观点？"))));

	//Choose rate
	ui->comboBox->addItem("*1");
	ui->comboBox->addItem("*0.75");
	ui->comboBox->addItem("*1.25");
	ui->comboBox->addItem("*1.5");

	//Progress Dialog
	pDlg = new QProgressDialog(this);
	pPB = new QProgressBar(pDlg);
	connect(pDlg, SIGNAL(canceled()),
		Taffdex, SLOT(stopProcessSlot()));
	connect(Taffdex, SIGNAL(finishedSignal(std::exception, float)),
		pDlg, SLOT(cancel()));
	pDlg->setModal(true);
	pDlg->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	pDlg->setCancelButtonText(QString::fromLocal8Bit("取消"));
	pDlg->setLabelText(QString::fromLocal8Bit("分析中..."));
	pDlg->setBar(pPB);
	pDlg->close();

	//Set CSS
	setStyleSheet("QPushButton {border:2px groove grey;border-radius:10px;padding:2px 4px;background-color:rgb(195,224,255)}");
	//setStyleSheet("QComboBox {border:5px groove}");
	//ui->PushButton_7->setStyleSheet("border:2px groove grey;border-radius:4px");
	ui->comboBox->setStyleSheet("border:2px groove grey;border-radius:4px");
	ui->ChartViewRadar->setStyleSheet("border:4px groove grey;border-color: rgb(105, 158, 255);border-radius:10px");
	ui->DetailsTable->setStyleSheet("border:4px groove grey;border-color: rgb(105, 158, 255);border-radius:10px;gridline-color: rgb(105, 158, 255)");
	ui->QuestionsTree->setStyleSheet("border:4px groove grey;border-color: rgb(105, 158, 255);border-radius:10px");
	ui->ChartViewLine->setStyleSheet("border:4px groove grey;border-color: rgb(105, 158, 255);border-radius:10px");
	ui->MediaView->setStyleSheet("border:4px groove grey;border-color: rgb(105, 158, 255);border-radius:10px");

	//Menu
	ui->actionNew->setDisabled(true);
	ui->actionOpen->setDisabled(true);

	av_register_all();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	if (player->state() != QMediaPlayer::PlayingState)
	{
		player->play();
		playerUpdateTimer->start();
		ui->pushButton->setText(QString::fromLocal8Bit("暂 停"));
	}
	else
	{
		player->pause();
		playerUpdateTimer->stop();
		ui->pushButton->setText(QString::fromLocal8Bit("播 放"));
	}
	return;
}

void MainWindow::FrameDataUpdateSlot(Face face, long count)
{
	//seriesLineAnger->replace((int)(count%30),count,face.emotions.anger);
	//seriesLineDisgust->replace((int)(count%30),count,face.emotions.disgust);
	//seriesLineFear->replace((int)(count%30),count,face.emotions.fear);
	//seriesLineJoy->replace((int)(count%30),count,face.emotions.joy);
	//seriesLineSadness->replace((int)(count%30),count,face.emotions.sadness);
	//seriesLineSurprise->replace((int)(count%30),count,face.emotions.surprise);
	seriesLineAnger->append(count, face.emotions.anger);
	seriesLineDisgust->append(count, face.emotions.disgust);
	seriesLineFear->append(count, face.emotions.fear);
	seriesLineJoy->append(count, face.emotions.joy);
	seriesLineSadness->append(count, face.emotions.sadness);
	seriesLineSurprise->append(count, face.emotions.surprise);
	currentFace = face;

	chartLine->axisX()->setMax(count);
	pDlg->setValue(count);
	return;
}

void MainWindow::on_pushButton_2_clicked()
{
	player->stop();
	playerUpdateTimer->stop();
	ui->pushButton->setText(QString::fromLocal8Bit("播 放"));
	return;
}

void MainWindow::on_pushButton_3_clicked()
{
	QFileDialog *fd = new QFileDialog(this, tr("Choose file"));
	QString path;
	fd->setFileMode(QFileDialog::ExistingFile);
	fd->setViewMode(QFileDialog::Detail);
	fd->setOptions(QFileDialog::ReadOnly);
	fd->setNameFilter("Video File (*.MOV *.WMV *.FLV *.AVI *.MP4 *.WEBM)");
	if (fd->exec() == QDialog::Accepted)
	{
		path = fd->selectedFiles()[0];
		AVFormatContext *pFormatCtx;
		pFormatCtx = avformat_alloc_context();
		QByteArray ba = path.toLocal8Bit();
		if (avformat_open_input(&pFormatCtx, ba.data(), NULL, NULL) == 0)
		{
			if (avformat_find_stream_info(pFormatCtx, NULL) >= 0)
			{
				if (pFormatCtx->streams[0]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
				{
					videoFrames = pFormatCtx->streams[0]->nb_frames;
					currentFile = path;
					player->setMedia(QUrl::fromLocalFile(currentFile));
					QMessageBox::information(NULL, tr("Path"), tr("The file selected is:\n") + currentFile);
					return;
				}
			}
		}
		QMessageBox::critical(NULL, tr("Error"), tr("Cannot open the file."));
		return;
	}
	else
	{
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
		return;
	}
}

void MainWindow::on_pushButton_4_clicked()
{
	QFileInfo fi(currentFile);
	if (fi.isFile())
	{
		pDlg->reset();
		pDlg->setRange(0, videoFrames);
		pDlg->show();
		removeLinesData();
		ui->ChartViewLine->setDisabled(false);
		emit ProcessVideoSignal(currentFile);
		return;
	}
	else
		QMessageBox::critical(NULL, tr("Warning"), tr("File don't exist!"));
}

void MainWindow::on_pushButton_5_clicked()
{
	QMessageBox::information(NULL, tr("Media Duration"), QString("%1\n%2").arg(player->position()).arg(player->duration()));
}

void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox::about(this, QString::fromLocal8Bit("关于"), QString::fromLocal8Bit("eMore\tPowered by Affdex(R)\nVer.Alpha5\nEmail:3140103993@zju.edu.cn"));
}

void MainWindow::testWSlot(qint64 a)
{
	a = 0;
	return;
}

void MainWindow::finishedSlot(std::exception e, float t)
{
	updateDetails(currentFace);
	updateRadar(currentFace);
	videoFrames = Taffdex->getImgCount();
	if (e.what() == std::string("success"))
	{
		QString QStr = QString("Processing successfully finished in %1 s").arg(t);
		QMessageBox::information(NULL, tr("Finished"), QStr);
	}
	else
	{
		QString QStr = QString("Processing except terminated in %1 s\n").arg(t);
		QStr += QString::fromStdString(e.what());
		QMessageBox::information(NULL, tr("Exception"), QStr);
	}
	return;
}

void MainWindow::updateDetails(const Face &face)
{
	ui->DetailsTable->item(0, 2)->setText(QString::number(face.emotions.joy, 'f', 2));
	ui->DetailsTable->item(1, 2)->setText(QString::number(face.emotions.fear, 'f', 2));
	ui->DetailsTable->item(2, 2)->setText(QString::number(face.emotions.disgust, 'f', 2));
	ui->DetailsTable->item(3, 2)->setText(QString::number(face.emotions.sadness, 'f', 2));
	ui->DetailsTable->item(4, 2)->setText(QString::number(face.emotions.anger, 'f', 2));
	ui->DetailsTable->item(5, 2)->setText(QString::number(face.emotions.surprise, 'f', 2));
	ui->DetailsTable->item(6, 2)->setText(QString::number(face.emotions.contempt, 'f', 2));
	ui->DetailsTable->item(7, 2)->setText(QString::number(face.emotions.valence, 'f', 2));
	ui->DetailsTable->item(8, 2)->setText(QString::number(face.emotions.engagement, 'f', 2));
	return;
}

void MainWindow::updateRadar(const Face face)
{
	seriesRadar->replace(0, 0, face.emotions.joy);
	seriesRadar->replace(6, 6, face.emotions.joy);
	seriesRadar->replace(1, 1, face.emotions.fear);
	seriesRadar->replace(2, 2, face.emotions.sadness);
	seriesRadar->replace(3, 3, face.emotions.surprise);
	seriesRadar->replace(4, 4, face.emotions.disgust);
	seriesRadar->replace(5, 5, face.emotions.anger);
	seriesBar->barSets().at(0)->remove(0, 6);
	//seriesBar->clear();
	seriesBar->barSets().at(0)->append(face.emotions.joy);
	seriesBar->barSets().at(0)->append(face.emotions.fear);
	seriesBar->barSets().at(0)->append(face.emotions.disgust);
	seriesBar->barSets().at(0)->append(face.emotions.sadness);
	seriesBar->barSets().at(0)->append(face.emotions.anger);
	seriesBar->barSets().at(0)->append(face.emotions.surprise);
	repaintBar();
	return;
}

void MainWindow::removeLinesData()
{
	seriesLineAnger->clear();
	seriesLineDisgust->clear();
	seriesLineFear->clear();
	seriesLineJoy->clear();
	seriesLineSadness->clear();
	seriesLineSurprise->clear();
}


void MainWindow::on_DetailsTable_cellClicked(int row, int column)
{
	if (row < 6 && column == 0)
		chartLine->series().at(row)->setVisible(ui->DetailsTable->item(row, column)->checkState() == Qt::Checked);
	return;
}

void MainWindow::on_actionQuit_triggered()
{
	exit(0);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == ui->ChartViewLine->scene())
	{
		if (event->type() == QEvent::GraphicsSceneMouseMove&&lineTracking)
		{
			qreal x = ((QGraphicsSceneMouseEvent*)event)->scenePos().x();
			x = x > 614 ? 614 : x;
			x = x < 70 ? 70 : x;
			trackLine->setLine(x, 35, x, 150);
			int index = floor((x - 70) / 545 * videoFrames);
			updateRadar(Taffdex->qFaces->at(index));
			updateDetails(Taffdex->qFaces->at(index));
			return true;
		}
		else if (event->type() == QEvent::GraphicsSceneMouseRelease)
		{
			lineTracking = !lineTracking;
			qreal x = ((QGraphicsSceneMouseEvent*)event)->scenePos().x();
			x = x > 614 ? 614 : x;
			x = x < 70 ? 70 : x;
			trackLine->setLine(x, 35, x, 150);
			int index = floor((x - 70) / 545 * videoFrames);
			updateRadar(Taffdex->qFaces->at(index));
			updateDetails(Taffdex->qFaces->at(index));
			return true;
		}
		else
			return QMainWindow::eventFilter(watched, event);
	}
	else if (watched == ui->MediaView->scene())
	{
		if (event->type() == QEvent::GraphicsSceneMouseRelease)
		{
			ui->PlayProgressBar->show();
			//QMessageBox::information(this,QString::fromLocal8Bit("Mouse Moved"),QString::fromLocal8Bit("%1").arg(event->type()));
			playerSliderTimer->setSingleShot(true);
			playerSliderTimer->start(2000);
			return true;
		}
		else if (event->type() == QEvent::GraphicsSceneHoverMove)
		{
			ui->PlayProgressBar->show();
			QMessageBox::information(this, QString::fromLocal8Bit("Mouse Moved"), QString::fromLocal8Bit("%1").arg(event->type()));
			playerSliderTimer->setSingleShot(true);
			playerSliderTimer->start(2000);
			return true;
		}
		else
			return QMainWindow::eventFilter(watched, event);
	}
	else
		return QMainWindow::eventFilter(watched, event);
}

void MainWindow::setMediaDuration(qint64 t)
{
	duration = t;
	ui->PlayProgressBar->setMaximum(t);
	return;
}

void MainWindow::on_PlayProgressBar_sliderMoved(int position)
{
	if (player->isVideoAvailable())
		player->setPosition(position);
	return;
}

void MainWindow::on_timer_timeout()
{
	ui->PlayProgressBar->hide();
	return;
}

void MainWindow::updateProgressBar()
{
	if (player->isVideoAvailable())
		ui->PlayProgressBar->setValue(player->position());
	return;
}

void MainWindow::repaintBar()
{
	int i = 0;
	int j = 0;
	while (i < 6)
	{
		if (chartBar->childItems().at(19)->childItems().at(j)->type() == 3)
		{
			((QGraphicsRectItem*)chartBar->childItems().at(19)->childItems().at(i))->setBrush(QColor::fromHsv(i * 60, 240, 216));
			((QGraphicsRectItem*)chartBar->childItems().at(19)->childItems().at(0))->setPen(QColor::fromHsv(i * 60, 240, 216));
			i++;
		}
		j++;
	}
}

void MainWindow::on_pushButton_8_clicked()
{
	if (ui->ChartViewRadar->chart() == chartRadar)
	{
		ui->ChartViewRadar->setChart(chartBar);
		repaintBar();
	}
	else
		ui->ChartViewRadar->setChart(chartRadar);
	return;
}
