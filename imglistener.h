#ifndef IMGLISTENER_H
#define IMGLISTENER_H
#include "affdex.h"
#include <QtCore>

class affdexThread;

class imgListener : public ImageListener
{
public:
	int Fcount,Rcount;

    imgListener(affdexThread *p);
    ~imgListener();
    void onImageCapture(Frame image);
    void onImageResults(std::map< FaceId, Face > faces, Frame image);
	void setParent(affdexThread *parent);
    void reset();
private:
	affdexThread *parentThread;
};

class videoListener : public ProcessStatusListener
{
public:
    videoListener(affdexThread *p);
	~videoListener();
	void onProcessingException(AffdexException ex);
	void onProcessingFinished();
	void setParent(affdexThread *parent);
private:
	affdexThread *parentThread;
};

#endif // IMGLISTENER_H
