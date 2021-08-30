#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Player.h"
#include <QTimer>
#include <iostream>
#include <QPainter>


bool changeStyle = true;
int FirstSetUp=1;
Hands HandHeap[108];
int nextHandHeap=0;
info gameInfo;
mainStateEnum mainState;
bool isInit=true;//主状态机用
Player* playerList[2];//玩家对象表

/// 构造函数,ui构造与初始化
/// \param parent
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
        this->setWindowTitle("三国杀 ver 0.0.1alpha(请勿用于生产环境())");
        cout << "Hello?";
        if (changeStyle) {
            ui->timeBar->hide();
            ui->TestBox->hide();
            ui->YesOrNo->hide();

            ui->tips->setWordWrap(true);
            ui->tips->hide();

            ui->HeroWeight1->hide();
            ui->HeroWeight2->hide();
            ui->VS->hide();
            ui->isHeroChoose->hide();
            ui->isHeroChoose_2->hide();
            ui->jump->hide();
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
            for (int i = 0; i < 3; i++)HandCardGroup[i]->setIconSize(QSize(250, 292));
            for (int i = 4; i < 15; i++)HandCardGroup[i]->hide();


        }

        //this->setStyleSheet("QFrame#myframe{border-image:url(resource/wallpaper/background.png)}" );
        //this->setAttribute(Qt::WA_StyledBackground, true);
        washCard();
        chooseHero();
        //connect(ui->testButton, SIGNAL(clicked()), this, SLOT(start()));
        //connect(qtimer, SIGNAL(timeout()), this, SLOT(timeout()));}
    }
/// 析构函数
MainWindow::~MainWindow() {
    delete ui;
}
/// 背景重绘函数paintEvent重写
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap("resource/wallpaper/background.png"));
}
