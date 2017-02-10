#ifndef DEMO_H
#define DEMO_H

#include <QtWidgets/QDialog>
#include <QPixmap>
#include "ui_demo.h"

#include <memory>
#include "ocr.h"

class demo : public QDialog
{
	Q_OBJECT

public:
	demo(QWidget *parent = 0);
	~demo();

private slots:
	void SelectImage();
	void FetchResult();

private:
	Ui::demoClass ui;

	QPixmap m_img;
	QString m_qstrfilePath;
	QString m_qstrImgFile;
	QString m_qstrResult;
	ocr m_ocr;
};

#endif // DEMO_H
