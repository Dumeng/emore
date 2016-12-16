#include <QtCore>
#include "affdex.h"

class affdexThread :public QThread
{
	Q_OBJECT
public:
	affdexThread();
	~affdexThread();
private:
	bool m_stopFlag;
	QMutex mutex;
protected:
	void run();
	void stop();
signals:
	void newDataSignal(struct Emotions emotion);
};