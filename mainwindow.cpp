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
            this->setWindowTitle("Hello");

    if (changeStyle) {
        ui->timeBar->hide();
        ui->testButton->hide();
        ui->YesOrNo->hide();

        ui->tips->setWordWrap(true);
        ui->tips->hide();

        //手牌组初始化
        for(auto & i : HandCardGroup)i->setIconSize(QSize(250, 292));
    }

    //this->setStyleSheet("QFrame#myframe{border-image:url(resource/wallpaper/background.png)}" );
    qtimer = new QTimer(this);
    chooseHero();
    //connect(ui->testButton, SIGNAL(clicked()), this, SLOT(start()));
    //connect(qtimer, SIGNAL(timeout()), this, SLOT(timeout()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap("resource/wallpaper/background.png"));
}

void MainWindow::start() {
    qtimer->start(100);
    ui->timeBar->setValue(100);
}

void MainWindow::timeout() {
    temp--;
    ui->timeBar->setValue(temp);
    if (temp == 0) {
        qtimer->stop();
    }
}
