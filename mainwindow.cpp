#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->reset();
    ui->img_in->setSceneRect(0,0,357,183);
    ui->img_out->setSceneRect(0,0,357,183);

    QGraphicsScene* sp = new QGraphicsScene;
    QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem;
    text->setText("等待转换");
    text->setFont(QFont("等线",16));
    sp->addItem(text);
    ui->img_out->setScene(sp);

    QGraphicsScene* sp2 = new QGraphicsScene;
    QGraphicsSimpleTextItem* text2 = new QGraphicsSimpleTextItem;
    text2->setText("等待选择");
    text2->setFont(QFont("等线",16));
    sp2->addItem(text2);
    ui->img_in->setScene(sp2);

    ui->img_out->setContextMenuPolicy(Qt::CustomContextMenu);
    rc1 = new QAction("Save",this);
    menu = new QMenu(this);
    menu->addAction(rc1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    clock_t start,finish;
    start = clock();
    QString inpath,outpath;
    QString temppath = QCoreApplication::applicationDirPath();
    inpath = ui->input->text();
    outpath = ui->output->text();

    if(inpath.size()!=0 && outpath.size()!=0){

    ifstream test(inpath.toStdString());
    if(test.good()){

    ofstream file((temppath + "/temp.dat").toStdString(), ios::out | ios::binary);

    addinfo("源文件["+inpath+"]\n输出文件["+outpath+"]\n缓存目录["+temppath+"]");

    Mat oimage, image;

    oimage = cv::imread(inpath.toStdString(), CV_8SC3);

   if(oimage.cols != 256 || oimage.rows != 128){
        cv::resize(oimage,image,Size(256,128),0,0,cv::INTER_LINEAR);

        addinfo("\n\n转换图片大小...Done");
        if((oimage.cols/oimage.rows)!=2){
            addinfo("\n[图片被拉伸]");
        }
    }
    else{
        image = oimage;
    }


    Mat out(image.rows, image.cols, CV_8UC1);


    int R, G, B, Gray;
    int x, y;
    x = y = 0;
    addinfo("\n\n转换灰度...");
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum((image.rows-1)*image.cols);
    for (x = 0; x < image.cols; x++) {
        file.write("", 2);
        for (y = image.rows - 1; y >= 0; y--) {
            ui->progressBar->setValue(x*image.cols+image.rows-y);
            file.write("", 1);
            R = image.at<Vec3b>(y, x)[0];
            G = image.at<Vec3b>(y, x)[1];
            B = image.at<Vec3b>(y, x)[2];
            Gray = (R*30 + G*59 + B*11 + 50)/100;
            if (Gray >= 0 && Gray < 64) {
                file.write("0", 1);
                out.at<uchar>(y, x) = 0;
            }
            else if (Gray >= 64 && Gray < 128) {
                file.write("1", 1);
                out.at<uchar>(y, x) = 64;
            }
            else if (Gray >= 128 && Gray < 192) {
                file.write("2", 1);
                out.at<uchar>(y, x) = 128;
            }
            else if (Gray >= 192 && Gray < 256) {
                file.write("3", 1);
                out.at<uchar>(y, x) = 192;
            }

            //			cout << endl << R << " " << G << " " << B << " => " << Gray;
        }
        file << char(0x00) << char(0x80) << char(0x00) << char(0x01) << char(0x01) << char(0x02);
    }
    imwrite((temppath + "/temp.jpg").toStdString(),out);

    connect(ui->img_out,&QGraphicsView::customContextMenuRequested,[=]{menu->exec(QCursor::pos());});
    connect(rc1,&QAction::triggered,[=](){
        QString temp = QFileDialog::getExistingDirectory(this,"");
        imwrite((temp + "/out.jpg").toStdString(),out);
    });

    file.close();
    addinfo("Done");

    addinfo("\n处理数据...");
    ifstream change;
    change.open((temppath + "/temp.dat").toStdString(), ios::in | ios::binary);
    int size = (image.rows * 2 + 8) * image.cols;
    char* temp = new char[static_cast<unsigned long>(size)];
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

    addinfo("Done");

    QGraphicsScene* img_out = new QGraphicsScene();
    img_out->addPixmap(QPixmap(temppath + "/temp.jpg").scaled(357,183));
    ui->img_out->setScene(img_out);

    addinfo("\n\n完成!");
    finish = clock();
    addinfo("\n用时:" + QString::fromStdString(std::to_string(int(finish - start))) + "ms\n\n");
    }
    else
    {
        addinfo("\n文件打开失败,请检查路径是否有中文\n");
    }
  }
    else{
        addinfo("\n输入不能为空\n");
    }

}

void MainWindow::on_choose_in_clicked()
{
    ui->img_out->disconnect();
    rc1->disconnect();
    QGraphicsScene* sp = new QGraphicsScene;
    QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem;
    text->setText("等待转换");
    sp->addItem(text);
    text->setFont(QFont("等线",16));
    ui->img_out->setScene(sp);

    ui->input->setText(QFileDialog::getOpenFileName(this, "", "","*.*"));
    QGraphicsScene* img_in = new QGraphicsScene();
    img_in->addPixmap(QPixmap(ui->input->text()).scaled(357,183));
    ui->img_in->setScene(img_in);

    if(ui->input->text() == ""){
        QGraphicsScene* sp2 = new QGraphicsScene;
        QGraphicsSimpleTextItem* text2 = new QGraphicsSimpleTextItem;
        text2->setText("等待选择");
        text2->setFont(QFont("等线",16));
        sp2->addItem(text2);
        ui->img_in->setScene(sp2);
    }
}



void MainWindow::on_choose_out_clicked()
{
    ui->img_out->disconnect();
    rc1->disconnect();
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

inline void MainWindow::addinfo(QString s){
    ui->outinfo->setText(ui->outinfo->toPlainText() + s);
}

void MainWindow::on_outinfo_textChanged()
{
    ui->outinfo->moveCursor(QTextCursor::End);
}
