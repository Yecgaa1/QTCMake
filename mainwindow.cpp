#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <./interactive_buttons/interactivebuttonbase.h>
#include <./interactive_buttons/waterfloatbutton.h>


bool changeStyle = true;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
        {
            InteractiveButtonBase* btn = new InteractiveButtonBase("text", this);
            btn->setGeometry(300, 300, 100, 100);
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
