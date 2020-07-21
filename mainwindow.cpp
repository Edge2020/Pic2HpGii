#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;


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
    ui->outinfo->setText("");
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

    Mat oimage,image;

    oimage = cv::imread(inpath.toStdString(), CV_64F);

   if(oimage.cols != 256 || oimage.rows != 128){
        cv::resize(oimage,image,Size(256,128),0,0,cv::INTER_LINEAR);

        ui->outinfo->setText(ui->outinfo->toPlainText() + "\n\n转换图片大小...Done");
        if((oimage.cols/oimage.rows)!=2){
           ui->outinfo->setText(ui->outinfo->toPlainText() + "\n[图片被拉伸]");
        }
    }
    else{
        image = oimage;
    }


    Mat out(image.rows, image.cols, CV_8U);



    int R, G, B, Gray;
    int x, y;
    x = y = 0;
    ui->outinfo->setText(ui->outinfo->toPlainText() + "\n\n转换灰度...");
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(image.rows*image.cols);
    for (x = 0; x < image.cols; x++) {
        file.write("", 2);
        for (y = image.rows - 1; y >= 0; y--) {
            ui->progressBar->setValue(x*image.cols+image.rows-y);
            file.write("", 1);
            R = image.at<Vec3b>(y, x)[2];
            G = image.at<Vec3b>(y, x)[1];
            B = image.at<Vec3b>(y, x)[0];
            Gray = int(pow((pow(R, 2.2) * 0.2126 + pow(G, 2.2) * 0.7152 + pow(B, 2.2) * 0.0722), (1 / 2.2)));
            if (Gray >= 0 && Gray < 63) {
                file.write("0", 1);
                out.at<uchar>(y, x) = 255;
            }
            if (Gray >= 63 && Gray < 127) {
                file.write("3", 1);
                out.at<uchar>(y, x) = 191;
            }
            if (Gray >= 127 && Gray < 191) {
                file.write("2", 1);
                out.at<uchar>(y, x) = 127;
            }
            if (Gray >= 191 && Gray < 255) {
                file.write("1", 1);
                out.at<uchar>(y, x) = 64;
            }
            //			cout << endl << R << " " << G << " " << B << " => " << Gray;
        }
        file << char(0x00) << char(0x80) << char(0x00) << char(0x01) << char(0x01) << char(0x02);
    }
    file.close();
    ui->outinfo->setText(ui->outinfo->toPlainText() + "Done");

    ui->outinfo->setText(ui->outinfo->toPlainText() + "\n处理数据...");
    ifstream change;
    change.open(temppath.toStdString(), ios::in | ios::binary);
    int size = (image.rows * 2 + 8) * image.cols;
    char* temp = new char[size];
    for (int i = 0; i < size; i++) {
        change.read(temp, size);
        ui->progressBar->setValue(i/size*100);
    }
    ofstream final;
    final.open(outpath.toStdString(), ios::out | ios::binary);
    for(int i = 0;i < 1032;i++){
        final << char(head[i]);
    }
    for (int i = 1; i < size + 1; i++) {
        final << char(temp[size - i]);
        ui->progressBar->setValue(i);
    }
    final.close();
    change.close();

    delete[] temp;
    ui->outinfo->setText(ui->outinfo->toPlainText() + "Done");

    namedWindow("PREVIEW", WINDOW_AUTOSIZE);
    imshow("PREVIEW", out);
    ui->outinfo->setText(ui->outinfo->toPlainText() + "\n\n完成!");


    }
    else
    {
        ui->outinfo->setText("文件打开失败");
    }
  }
    else{
        ui->outinfo->setText("输入不能为空");
    }
}

void MainWindow::on_choose_in_clicked()
{
     ui->input->setText(QFileDialog::getOpenFileName(this, "", "","*.*"));
}




void MainWindow::on_choose_out_clicked()
{
    QString temp = QFileDialog::getExistingDirectory(this,"");
    if(temp.length() != 0){
    if(temp.length() == 3){
        ui->output->setText(temp + "L1.hplist");
    }
    else{
        ui->output->setText(temp + "/L1.hplist");
    }
    }
}
