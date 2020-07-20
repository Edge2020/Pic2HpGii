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
using namespace cv;
using std::ofstream;
using std::ifstream;
using std::ios;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_choose_in_clicked();

    void on_choose_out_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
