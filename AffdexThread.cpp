#include "AffdexThread.h"

affdexThread::affdexThread()
{
	m_stopFlag = false;
}

void affdexThread::stop()
{
	QMutexLocker locker(&mutex);
	m_stopFlag = true;
}

void affdexThread::run()
{
	QMutexLocker locker(&mutex);
	m_stopFlag = false;
}
