#include "imglistener.h"
#include "AffdexThread.h"
#include <time.h>

imgListener::imgListener(affdexThread *p)
{
    parentThread =p;
	Rcount = 0;
	Fcount = 0;
}

imgListener::~imgListener()
{

}

void imgListener::setParent(affdexThread *parent)
{
	parentThread = parent;
}

void imgListener::onImageCapture(Frame image)
{
	Fcount++;
	return;
}

void imgListener::onImageResults(std::map<FaceId, Face> faces, Frame image)
{
    {
        QMutexLocker locker(&(parentThread->qFacesLock));
        parentThread->qFaces->enqueue(faces.begin()->second);
    }
	Rcount++;
    emit parentThread->newDataSignal(faces.begin()->second,Rcount);
}

videoListener::videoListener(affdexThread *p)
{
    parentThread=p;
}

videoListener::~videoListener()
{

}

void videoListener::setParent(affdexThread *parent)
{
	parentThread = parent;
}

void videoListener::onProcessingException(AffdexException e)
{
    parentThread->processException(e);
}

void videoListener::onProcessingFinished()
{
    parentThread->processFinished();
}

void imgListener::reset()
{
    Rcount=0;
    Fcount=0;
}
