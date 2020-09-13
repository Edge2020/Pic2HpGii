/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *choose_in;
    QLineEdit *input;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *choose_out;
    QLineEdit *output;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QGraphicsView *img_in;
    QLabel *label_5;
    QGraphicsView *img_out;
    QTextEdit *outinfo;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLabel *label_4;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 1, 781, 541));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        choose_in = new QPushButton(layoutWidget);
        choose_in->setObjectName(QString::fromUtf8("choose_in"));

        horizontalLayout->addWidget(choose_in);

        input = new QLineEdit(layoutWidget);
        input->setObjectName(QString::fromUtf8("input"));
        QFont font;
        font.setUnderline(false);
        input->setFont(font);
        input->setReadOnly(true);

        horizontalLayout->addWidget(input);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        choose_out = new QPushButton(layoutWidget);
        choose_out->setObjectName(QString::fromUtf8("choose_out"));

        horizontalLayout_2->addWidget(choose_out);

        output = new QLineEdit(layoutWidget);
        output->setObjectName(QString::fromUtf8("output"));
        output->setReadOnly(true);

        horizontalLayout_2->addWidget(output);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        img_in = new QGraphicsView(layoutWidget);
        img_in->setObjectName(QString::fromUtf8("img_in"));

        horizontalLayout_6->addWidget(img_in);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(28);
        label_5->setFont(font1);

        horizontalLayout_6->addWidget(label_5);

        img_out = new QGraphicsView(layoutWidget);
        img_out->setObjectName(QString::fromUtf8("img_out"));

        horizontalLayout_6->addWidget(img_out);


        verticalLayout_2->addLayout(horizontalLayout_6);

        outinfo = new QTextEdit(layoutWidget);
        outinfo->setObjectName(QString::fromUtf8("outinfo"));
        outinfo->setAcceptDrops(true);
        outinfo->setReadOnly(true);

        verticalLayout_2->addWidget(outinfo);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3, 0, Qt::AlignLeft);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_7->addWidget(label_4, 0, Qt::AlignRight);


        verticalLayout_4->addLayout(horizontalLayout_7);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setAutoFillBackground(true);
        progressBar->setValue(24);

        verticalLayout_4->addWidget(progressBar);

        horizontalSpacer = new QSpacerItem(40, 29, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_4->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pic2HpGii", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\272\220\346\226\207\344\273\266  ", nullptr));
        choose_in->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\346\226\207\344\273\266", nullptr));
        choose_out->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\342\236\244", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "By Edge2020", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "[github.com/Edge2020/Pic2HpGii]", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
