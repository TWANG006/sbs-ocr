#include "ocr.h"
#include <memory>
#include <QDebug>
#include <iostream>

ocr::ocr()
{

}

ocr::~ocr()
{

}

QString ocr::recognize(const QString& imgFile)
{
	if (tess.Init("./tessdata", "eng"))
	{
		emit ocrErrMsg(QString("[OCRTesseract]: Could not initialize tesseract."));
		return QString();
	}

	// Auto segmentation of the image
	tess.SetPageSegMode(tesseract::PageSegMode::PSM_AUTO);
	tess.SetVariable("save_best_choices", "T");

	// read image
	auto pixs = pixRead(imgFile.toStdString().c_str());

	if (!pixs)
	{
		emit ocrErrMsg(QString("Cannot open input file: ") + imgFile);
		return QString();
	}

	// recognize
	tess.SetImage(pixs);
	tess.Recognize(0);

	// Get the results
	QString qstrResult = QString::fromStdString(std::string(std::unique_ptr<char[]>(tess.GetUTF8Text()).get()));

	// Cleanup and return values
	tess.Clear();
	pixDestroy(&pixs);

	return qstrResult;
}