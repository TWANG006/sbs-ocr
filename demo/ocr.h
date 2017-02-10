#ifndef OCR_H
#define OCR_H

#include <QObject>
#include <QString>

#include "allheaders.h"
#include "baseapi.h"

class ocr : public QObject
{
	Q_OBJECT

public:
	ocr();
	~ocr();

	QString recognize(const QString& imgFile);

signals:
	void ocrErrMsg(const QString&);

private:
	tesseract::TessBaseAPI tess;
};

#endif // OCR_H
