#include <QtCore>
#include "imglistener.h"

class affdexThread :public QThread
{
	Q_OBJECT
public:
	affdexThread();
	~affdexThread();
	void init();
	void reset();
	long getImgCount();
	void setVideoFile(QString file);
	void setPhotoFile(QString file);
	void processFinished();
	void setBeginTime();
	void setFinishTime();
	long getBeginTime();
	long getFinishTime();
	float getProcessTime();
	void processException(AffdexException e);

    QList<Face> *qFaces;
	QMutex qFacesLock;

private:
	bool m_stopFlag;
	affdex::path currentFile;
	long begin, finish;
    //const affdex::path dataDir = L"D:/Affectiva/Affdex SDK/data";
    const affdex::path dataDir = L"./data";

	imgListener *il;
	videoListener *pl;
	VideoDetector *vd;
	PhotoDetector *pd;
	FrameDetector *fd;
	CameraDetector *cd;
	enum mediaType{
		VIDEO,
		PHOTO,
		CAMERA,
		UNKNOWN
	}currentFileType;

	double processFps = DEFAULT_PROCESSING_FRAMERATE;
	//unsigned int faceMax = DEFAULT_MAX_NUM_FACES;
	unsigned int faceMax = 1;
	FaceDetectorMode faceCfg = FaceDetectorMode::LARGE_FACES;

public slots:
	void SetFrameRateSlot(double fps);
	void ProcessVideoSlot(QString path);
	void stopProcessSlot();
	void testTSlot();

protected:
	void run();
	void stop();
signals:
	void newDataSignal(Face cFace, long count);
	void testTSignal();
	void finishedSignal(std::exception e, float time);
};
