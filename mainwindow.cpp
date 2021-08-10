#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <interactivebuttonbase.h>
#include <waterfloatbutton.h>
#include <waterzoombutton.h>


bool changeStyle = true;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
        {

    ui->setupUi(this);
            WaterZoomButton* zoom_btn1 = new WaterZoomButton("tttttttttt", this);
            zoom_btn1->setGeometry(300, 200, 200, 50);
            zoom_btn1->setBgColor(QColor(240,128,128));
            zoom_btn1->setBgColor(Qt::transparent, QColor(0x88, 0x88, 0x88, 0x64));
            zoom_btn1->setRadius(10, 5);
            zoom_btn1->setChokingProp(1.18);


    if (changeStyle) {

    }

    qtimer = new QTimer(this);



    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(qtimer, SIGNAL(timeout()), this, SLOT(timeout()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::start() {
    qtimer->start(100);
    ui->progressBar->setValue(100);
}

void MainWindow::timeout() {
    temp--;
    ui->progressBar->setValue(temp);
    if (temp == 0) {
        qtimer->stop();
    }
}
