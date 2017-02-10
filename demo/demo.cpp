#include "demo.h"
#include <QFileDialog>
#include <QMessageBox>

demo::demo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	connect(ui.selectImg_pushButton, SIGNAL(clicked()), this, SLOT(SelectImage()));
	connect(ui.fetch_pushButton, SIGNAL(released()), this, SLOT(FetchResult()));
}

demo::~demo()
{
	
}

void demo::SelectImage()
{
	m_qstrImgFile = QFileDialog::getOpenFileName(this, tr("Open Image Files"), m_qstrfilePath, tr("Images (*.png *.jpg *.tif *.bmp)"));

	if(!m_qstrImgFile.isNull())
	{
		ui.fetch_pushButton->setEnabled(true);

		QFileInfo fileInfo(m_qstrImgFile);
		m_qstrfilePath = fileInfo.path();
		if (!m_img.load(m_qstrImgFile))
			QMessageBox::critical(this, tr("ERROR!"), tr("Image is not loaded sussessfully!"));
		else
		{
			ui.img_label->setPixmap(m_img);
		}
			
	}
}

void demo::FetchResult()
{
	ui.plainTextEdit->setPlainText(m_ocr.recognize(m_qstrImgFile));
}
