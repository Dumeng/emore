#include "AffdexThread.h"
#include "time.h"

affdexThread::affdexThread()
{
	m_stopFlag = true;
}

void affdexThread::stop()
{
	//QMutexLocker locker(&mutex);
	m_stopFlag = true;
}

void affdexThread::run()
{
	//QMutexLocker locker(&mutex);
	m_stopFlag = false;
}

void affdexThread::init()
{
	qFaces = new QQueue<Face>();
	il = new imgListener(this);
	pl = new videoListener(this);
	vd = new VideoDetector();
	pd = new PhotoDetector();
	cd = new CameraDetector();
	vd->setImageListener(il);
	vd->setProcessStatusListener(pl);
	vd->setClassifierPath(dataDir);
	pd->setImageListener(il);
	pd->setProcessStatusListener(pl);
	cd->setImageListener(il);
	cd->setProcessStatusListener(pl);

	begin = 0;
	finish = 0;
}

void affdexThread::reset()
{
	delete qFaces;
	delete il;
	delete pl;
	delete vd;
	delete pd;
	delete cd;
	init();
}

affdexThread::~affdexThread()
{
	vd->stop();
	pd->stop();
	cd->stop();
	delete il;
	delete pl;
	delete vd;
	delete pd;
	delete cd;
	m_stopFlag = false;
}

void affdexThread::setVideoFile(QString file)
{
	currentFileType = VIDEO;
	currentFile = file.toStdWString();
}

void affdexThread::setPhotoFile(QString file)
{
	currentFileType = PHOTO;
	currentFile = (affdex::path)(file.toStdWString());
}

long affdexThread::getImgCount()
{
	return il->Rcount;
}

void affdexThread::ProcessVideoSlot(QString path)
{
	reset();
	setVideoFile(path);
	vd->setDetectAllEmotions(true);
	if (!vd->isRunning())
		vd->start();
	else
		vd->reset();
	setBeginTime();
	qDebug() << "Processing Begin";
	vd->process(currentFile);
}

void affdexThread::stopProcessSlot()
{
	if (vd->isRunning())
		vd->stop();
}

void affdexThread::SetFrameRateSlot(double fps)
{
	processFps = fps;
	delete vd;
	vd = new VideoDetector(processFps, faceMax, faceCfg);
}

void affdexThread::testTSlot()
{
	emit testTSignal();
}

void affdexThread::processFinished()
{
	setFinishTime();
	AffdexException e = AffdexException(std::string("success"));
	float t = getProcessTime();
	qDebug() << "Processing finished in" << t << "s";
	emit finishedSignal(e, t);
}

void affdexThread::processException(AffdexException e)
{
	setFinishTime();
	float t = getProcessTime();
	qDebug() << "Processing terminated in " << t << "s";
	qDebug() << e.what();
	emit finishedSignal(e, t);
}

void affdexThread::setBeginTime()
{
	begin = clock();
}

void affdexThread::setFinishTime()
{
	finish = clock();
}

long affdexThread::getBeginTime()
{
	return begin;
}

long affdexThread::getFinishTime()
{
	return finish;
}

float affdexThread::getProcessTime()
{
	return (float)(finish - begin) / CLOCKS_PER_SEC;
}
