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
        ui->TestBox->hide();
        ui->YesOrNo->hide();

        ui->tips->setWordWrap(true);
        ui->tips->hide();

        ui->HeroWeight1->hide();
        ui->HeroWeight2->hide();
        ui->VS->hide();
        //手牌组初始化
        HandCardGroup.push_back(ui->card1);
        HandCardGroup.push_back(ui->card2);
        HandCardGroup.push_back(ui->card3);
        HandCardGroup.push_back(ui->card4);
        HandCardGroup.push_back(ui->card5);
        HandCardGroup.push_back(ui->card6);
        HandCardGroup.push_back(ui->card7);
        HandCardGroup.push_back(ui->card8);
        HandCardGroup.push_back(ui->card9);
        HandCardGroup.push_back(ui->card10);
        HandCardGroup.push_back(ui->card11);
        HandCardGroup.push_back(ui->card12);
        HandCardGroup.push_back(ui->card13);
        HandCardGroup.push_back(ui->card14);
        HandCardGroup.push_back(ui->card15);
        for(int i=0;i<15;i++)HandCardGroup[i]->setIconSize(QSize(250, 292));
        for(int i=4;i<15;i++)HandCardGroup[i]->hide();


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

