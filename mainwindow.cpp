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
        HandCardGroup[0]=ui->card1;
        HandCardGroup[1]=ui->card2;
        HandCardGroup[2]=ui->card3;
        HandCardGroup[3]=ui->card4;
        HandCardGroup[4]=ui->card5;

    }

    //this->setStyleSheet("QFrame#myframe{border-image:url(resource/wallpaper/background.png)}" );

    washCard();

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

