#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <interactivebuttonbase.h>
#include <waterfloatbutton.h>


bool changeStyle = true;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
        {
    InteractiveButtonBase* float_btn = new WaterFloatButton("text", this);
            float_btn->setGeometry(164, 50, 100, 32);
            float_btn->setBgColor(QColor(102,51,204,192), QColor(102,51,204,255));
    ui->setupUi(this);


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
