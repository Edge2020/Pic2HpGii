#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <math.h>
#include <Windows.h>
#include <QMessageBox>
#include <QFileDialog>
#include <cstdio>
#include <stdlib.h>
#include <chrono>
#include <QGraphicsSimpleTextItem>
//#include <QDebug>

using std::ofstream;
using std::ifstream;
using std::ios;
using namespace cv;



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private slots:
	void on_pushButton_clicked();

	void on_choose_in_clicked();

	void on_choose_out_clicked();

	inline void addinfo(QString s);

	void on_outinfo_textChanged();

private:
	Ui::MainWindow* ui;

	QMenu* menu;

	QAction* rc1;
};

const QString version = "v1.2.0";

const int head[1032] = {
	0x06, 0x01, 0x01, 0x02, 0x00, 0x01, 0xA7, 0x05, 0xA8, 0xD9, 0xC5, 0x05, 0x78, 0xD7, 0xC5, 0x05,
	0x58, 0xCA, 0xC5, 0x05, 0x28, 0xC8, 0xC5, 0x05, 0x90, 0xD8, 0xC5, 0x05, 0x60, 0xD6, 0xC5, 0x05,
	0x48, 0xD5, 0xC5, 0x05, 0x38, 0xE0, 0xC5, 0x05, 0x10, 0xC7, 0xC5, 0x05, 0x50, 0xE1, 0xC5, 0x05,
	0x30, 0xD4, 0xC5, 0x05, 0xA0, 0xCD, 0xC5, 0x05, 0x40, 0xC9, 0xC5, 0x05, 0x18, 0xD3, 0xC5, 0x05,
	0xB0, 0xC2, 0xC5, 0x05, 0xE8, 0xD0, 0xC5, 0x05, 0x08, 0xDE, 0xC5, 0x05, 0xD0, 0xCF, 0xC5, 0x05,
	0x00, 0xD2, 0xC5, 0x05, 0xB8, 0xCE, 0xC5, 0x05, 0x88, 0xCC, 0xC5, 0x05, 0xF8, 0xC5, 0xC5, 0x05,
	0xE0, 0x54, 0xC5, 0x05, 0xB0, 0x52, 0xC5, 0x05, 0x80, 0x50, 0xC5, 0x05, 0xC0, 0x47, 0xC5, 0x05,
	0x00, 0x3F, 0xC5, 0x05, 0x30, 0x41, 0xC5, 0x05, 0x98, 0x51, 0xC5, 0x05, 0xD8, 0x48, 0xC5, 0x05,
	0xC8, 0x53, 0xC5, 0x05, 0x50, 0x4E, 0xC5, 0x05, 0xE8, 0x3D, 0xC5, 0x05, 0x68, 0x4F, 0xC5, 0x05,
	0xA0, 0x3A, 0xC5, 0x05, 0x20, 0x4C, 0xC5, 0x05, 0x90, 0x45, 0xC5, 0x05, 0x08, 0x4B, 0xC5, 0x05,
	0x48, 0x42, 0xC5, 0x05, 0x78, 0x44, 0xC5, 0x05, 0x18, 0x40, 0xC5, 0x05, 0xB8, 0x3B, 0xC5, 0x05,
	0x38, 0x4D, 0xC5, 0x05, 0x70, 0x38, 0xC5, 0x05, 0xF0, 0x49, 0xC5, 0x05, 0x58, 0x37, 0xC5, 0x05,
	0xA8, 0x46, 0xC5, 0x05, 0x88, 0x39, 0xC5, 0x05, 0x40, 0x36, 0xC5, 0x05, 0xD0, 0x3C, 0xC5, 0x05,
	0x60, 0x43, 0xC5, 0x05, 0x60, 0x2F, 0xC5, 0x05, 0x48, 0x2E, 0xC5, 0x05, 0x30, 0x2D, 0xC5, 0x05,
	0x18, 0x2C, 0xC5, 0x05, 0x40, 0x22, 0xC5, 0x05, 0xC8, 0x1C, 0xC5, 0x05, 0x00, 0x2B, 0xC5, 0x05,
	0x80, 0x19, 0xC5, 0x05, 0x28, 0x21, 0xC5, 0x05, 0xE8, 0x29, 0xC5, 0x05, 0x68, 0x18, 0xC5, 0x05,
	0x10, 0x20, 0xC5, 0x05, 0xC0, 0x33, 0xC5, 0x05, 0xB8, 0x27, 0xC5, 0x05, 0xA8, 0x32, 0xC5, 0x05,
	0xF8, 0x1E, 0xC5, 0x05, 0xB0, 0x1B, 0xC5, 0x05, 0xD0, 0x28, 0xC5, 0x05, 0x90, 0x31, 0xC5, 0x05,
	0xA0, 0x26, 0xC5, 0x05, 0x70, 0x24, 0xC5, 0x05, 0x50, 0x17, 0xC5, 0x05, 0x88, 0x25, 0xC5, 0x05,
	0x38, 0x16, 0xC5, 0x05, 0xD8, 0x34, 0xC5, 0x05, 0xE0, 0x1D, 0xC5, 0x05, 0x78, 0x30, 0xC5, 0x05,
	0x58, 0x23, 0xC5, 0x05, 0x98, 0x1A, 0xC5, 0x05, 0x50, 0x03, 0xC5, 0x05, 0x20, 0x01, 0xC5, 0x05,
	0x08, 0x00, 0xC5, 0x05, 0x78, 0xF9, 0xC4, 0x05, 0xC8, 0x08, 0xC5, 0x05, 0xF0, 0xFE, 0xC4, 0x05,
	0x10, 0x0C, 0xC5, 0x05, 0xB0, 0x07, 0xC5, 0x05, 0x60, 0xF8, 0xC4, 0x05, 0xB8, 0x13, 0xC5, 0x05,
	0x88, 0x11, 0xC5, 0x05, 0x70, 0x10, 0xC5, 0x05, 0xD0, 0x14, 0xC5, 0x05, 0xC0, 0xFC, 0xC4, 0x05,
	0x30, 0xF6, 0xC4, 0x05, 0xF8, 0x0A, 0xC5, 0x05, 0xA8, 0xFB, 0xC4, 0x05, 0xE0, 0x09, 0xC5, 0x05,
	0x40, 0x0E, 0xC5, 0x05, 0x98, 0x06, 0xC5, 0x05, 0xA0, 0x12, 0xC5, 0x05, 0x80, 0x05, 0xC5, 0x05,
	0x48, 0xF7, 0xC4, 0x05, 0x58, 0x0F, 0xC5, 0x05, 0x28, 0x0D, 0xC5, 0x05, 0xD8, 0xFD, 0xC4, 0x05,
	0x38, 0x02, 0xC5, 0x05, 0x90, 0xFA, 0xC4, 0x05, 0x68, 0x04, 0xC5, 0x05, 0x00, 0xE0, 0xC4, 0x05,
	0xB8, 0xDC, 0xC4, 0x05, 0xA0, 0xDB, 0xC4, 0x05, 0x58, 0xD8, 0xC4, 0x05, 0x40, 0xD7, 0xC4, 0x05,
	0x88, 0xDA, 0xC4, 0x05, 0xB0, 0xF3, 0xC4, 0x05, 0xE8, 0xDE, 0xC4, 0x05, 0x80, 0xF1, 0xC4, 0x05,
	0x08, 0xEC, 0xC4, 0x05, 0x68, 0xF0, 0xC4, 0x05, 0xD0, 0xDD, 0xC4, 0x05, 0x70, 0xD9, 0xC4, 0x05,
	0xF0, 0xEA, 0xC4, 0x05, 0x50, 0xEF, 0xC4, 0x05, 0xD8, 0xE9, 0xC4, 0x05, 0xC0, 0xE8, 0xC4, 0x05,
	0xC8, 0xF4, 0xC4, 0x05, 0xA8, 0xE7, 0xC4, 0x05, 0x28, 0xD6, 0xC4, 0x05, 0x60, 0xE4, 0xC4, 0x05,
	0x38, 0xEE, 0xC4, 0x05, 0x30, 0xE2, 0xC4, 0x05, 0x90, 0xE6, 0xC4, 0x05, 0x78, 0xE5, 0xC4, 0x05,
	0x98, 0xF2, 0xC4, 0x05, 0x18, 0xE1, 0xC4, 0x05, 0x48, 0xE3, 0xC4, 0x05, 0x20, 0xED, 0xC4, 0x05,
	0xC0, 0xD4, 0xC4, 0x05, 0xA8, 0xD3, 0xC4, 0x05, 0xA0, 0xC7, 0xC4, 0x05, 0x58, 0xC4, 0xC4, 0x05,
	0x40, 0xC3, 0xC4, 0x05, 0xB8, 0xC8, 0xC4, 0x05, 0x28, 0xC2, 0xC4, 0x05, 0x10, 0xC1, 0xC4, 0x05,
	0x68, 0xB9, 0xC4, 0x05, 0xF8, 0xBF, 0xC4, 0x05, 0x20, 0xB6, 0xC4, 0x05, 0x60, 0xD0, 0xC4, 0x05,
	0xB0, 0xBC, 0xC4, 0x05, 0xD0, 0xC9, 0xC4, 0x05, 0x30, 0xCE, 0xC4, 0x05, 0x88, 0xC6, 0xC4, 0x05,
	0x90, 0xD2, 0xC4, 0x05, 0x70, 0xC5, 0xC4, 0x05, 0x38, 0xB7, 0xC4, 0x05, 0x48, 0xCF, 0xC4, 0x05,
	0x18, 0xCD, 0xC4, 0x05, 0xE0, 0xBE, 0xC4, 0x05, 0x50, 0xB8, 0xC4, 0x05, 0x78, 0xD1, 0xC4, 0x05,
	0x98, 0xBB, 0xC4, 0x05, 0x80, 0xBA, 0xC4, 0x05, 0xC8, 0xBD, 0xC4, 0x05, 0x00, 0xCC, 0xC4, 0x05,
	0xE8, 0xCA, 0xC4, 0x05, 0x80, 0xA6, 0xC4, 0x05, 0x50, 0xA4, 0xC4, 0x05, 0x38, 0xA3, 0xC4, 0x05,
	0x30, 0x97, 0xC4, 0x05, 0xD8, 0x9E, 0xC4, 0x05, 0x10, 0xAD, 0xC4, 0x05, 0x40, 0xAF, 0xC4, 0x05,
	0x08, 0xA1, 0xC4, 0x05, 0xC0, 0x9D, 0xC4, 0x05, 0x18, 0x96, 0xC4, 0x05, 0x20, 0xA2, 0xC4, 0x05,
	0xF8, 0xAB, 0xC4, 0x05, 0xC8, 0xA9, 0xC4, 0x05, 0x28, 0xAE, 0xC4, 0x05, 0x60, 0x99, 0xC4, 0x05,
	0x78, 0x9A, 0xC4, 0x05, 0xF0, 0x9F, 0xC4, 0x05, 0x88, 0xB2, 0xC4, 0x05, 0x70, 0xB1, 0xC4, 0x05,
	0x68, 0xA5, 0xC4, 0x05, 0x48, 0x98, 0xC4, 0x05, 0xA0, 0xB3, 0xC4, 0x05, 0x90, 0x9B, 0xC4, 0x05,
	0xB8, 0xB4, 0xC4, 0x05, 0x58, 0xB0, 0xC4, 0x05, 0x98, 0xA7, 0xC4, 0x05, 0xA8, 0x9C, 0xC4, 0x05,
	0xB0, 0xA8, 0xC4, 0x05, 0xE0, 0xAA, 0xC4, 0x05, 0x10, 0x76, 0xC4, 0x05, 0xB0, 0x94, 0xC4, 0x05,
	0xD8, 0x8A, 0xC4, 0x05, 0xC0, 0x89, 0xC4, 0x05, 0x28, 0x77, 0xC4, 0x05, 0x80, 0x92, 0xC4, 0x05,
	0x98, 0x93, 0xC4, 0x05, 0x50, 0x90, 0xC4, 0x05, 0x20, 0x8E, 0xC4, 0x05, 0x70, 0x7A, 0xC4, 0x05,
	0xA8, 0x88, 0xC4, 0x05, 0x18, 0x82, 0xC4, 0x05, 0x88, 0x7B, 0xC4, 0x05, 0x78, 0x86, 0xC4, 0x05,
	0xB8, 0x7D, 0xC4, 0x05, 0x30, 0x83, 0xC4, 0x05, 0x48, 0x84, 0xC4, 0x05, 0xE8, 0x7F, 0xC4, 0x05,
	0x58, 0x79, 0xC4, 0x05, 0x08, 0x8D, 0xC4, 0x05, 0xD0, 0x7E, 0xC4, 0x05, 0x00, 0x81, 0xC4, 0x05,
	0x68, 0x91, 0xC4, 0x05, 0xA0, 0x7C, 0xC4, 0x05, 0x90, 0x87, 0xC4, 0x05, 0x60, 0x85, 0xC4, 0x05,
	0x38, 0x8F, 0xC4, 0x05, 0x40, 0x78, 0xC4, 0x05, 0xF0, 0x8B, 0xC4, 0x05, 0x38, 0x68, 0xC4, 0x05,
	0x20, 0x67, 0xC4, 0x05, 0x40, 0x74, 0xC4, 0x05, 0x28, 0x73, 0xC4, 0x05, 0x10, 0x72, 0xC4, 0x05,
	0x98, 0x6C, 0xC4, 0x05, 0xF8, 0x70, 0xC4, 0x05, 0x80, 0x6B, 0xC4, 0x05, 0xE0, 0x6F, 0xC4, 0x05,
	0xC8, 0x6E, 0xC4, 0x05, 0x50, 0x69, 0xC4, 0x05, 0x08, 0x66, 0xC4, 0x05, 0xB0, 0x6D, 0xC4, 0x05,
	0x68, 0x6A, 0xC4, 0x05, 0xD0, 0x64, 0xC4, 0x05, 0xC0, 0x63, 0xC4, 0x05, 0xB0, 0x62, 0xC4, 0x05,
	0xA0, 0x61, 0xC4, 0x05, 0x90, 0x60, 0xC4, 0x05, 0x80, 0x5F, 0xC4, 0x05, 0x70, 0x5E, 0xC4, 0x05,
	0x60, 0x5D, 0xC4, 0x05, 0x50, 0x5C, 0xC4, 0x05, 0x40, 0x5B, 0xC4, 0x05, 0x30, 0x5A, 0xC4, 0x05,
	0x20, 0x59, 0xC4, 0x05, 0x10, 0x58, 0xC4, 0x05, 0x00, 0x57, 0xC4, 0x05, 0xF0, 0x55, 0xC4, 0x05,
	0xE0, 0x54, 0xC4, 0x05, 0x58, 0x4F, 0xC4, 0x05
};



#endif // MAINWINDOW_H
