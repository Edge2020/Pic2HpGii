#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString inpath,outpath;
    QString temppath = QCoreApplication::applicationDirPath();
    temppath += "/temp.dat";
    inpath = ui->input->text();
    outpath = ui->output->text();

    if(inpath.size()!=0 && outpath.size()!=0){

    ifstream test(inpath.toStdString());
    if(test.good()){

    ofstream file(temppath.toStdString(), ios::out | ios::binary);

    ui->outinfo->setText("源文件["+inpath+"]\n输出文件["+outpath+"]\n缓存文件["+temppath+"]");

    Mat _image,image;

    _image = cv::imread(inpath.toStdString(), CV_16F);

    if(_image.cols != 256 || _image.rows != 128){
        cv::resize(_image,image,Size(256,128),0,0,INTER_LINEAR);
        ui->outinfo->setText("源文件["+inpath+"]\n输出文件["+outpath+"]\n缓存文件["+temppath+"]\n(图片大小自动转换)");
    }
    else{
        image = _image;
    }

    Mat out(image.rows, image.cols, CV_8U);

    int R, G, B, Gray;
    int x, y;
    x = y = 0;

    for (x = 0; x < image.cols; x++) {
        file.write("", 2);
        for (y = image.rows - 1; y >= 0; y--) {
            ui->progressBar->setValue((x*image.cols+y)/(image.cols*(image.rows-1))*100);
            file.write("", 1);
            R = image.at<Vec3b>(y, x)[2];
            G = image.at<Vec3b>(y, x)[1];
            B = image.at<Vec3b>(y, x)[0];
            Gray = pow((pow(R, 2.2) * 0.2126 + pow(G, 2.2) * 0.7152 + pow(B, 2.2) * 0.0722), (1 / 2.2));
            if (Gray >= 0 && Gray < 64) {
                file.write("0", 1);
                out.at<uchar>(y, x) = 256;
            }
            if (Gray >= 64 && Gray < 128) {
                file.write("3", 1);
                out.at<uchar>(y, x) = 192;
            }
            if (Gray >= 128 && Gray < 192) {
                file.write("2", 1);
                out.at<uchar>(y, x) = 128;
            }
            if (Gray >= 192 && Gray < 256) {
                file.write("1", 1);
                out.at<uchar>(y, x) = 64;
            }
            //			cout << endl << R << " " << G << " " << B << " => " << Gray;
        }
        file << char(0x00) << char(0x80) << char(0x00) << char(0x01) << char(0x01) << char(0x02);
    }
    file.close();

    ifstream change;
    change.open(temppath.toStdString(), ios::in | ios::binary);
    long size = (image.rows * 2 + 8) * image.cols;
    char* temp = new char[size];
    for (int i = 0; i < size; i++) {
        change.read(temp, size);
        ui->progressBar->setValue(i/size*100);
    }
    ofstream final;
    final.open(outpath.toStdString(), ios::out | ios::binary);
    for (int i = 1; i < size + 1; i++) {
        final << char(temp[size - i]);
        ui->progressBar->setValue(i/size*100);
    }
    final.close();

    delete[] temp;

    namedWindow("PREVIEW", WINDOW_AUTOSIZE);
    imshow("PREVIEW", out);
    }
    else
    {
        ui->outinfo->setText("文件打开失败");
    }
  }
}
