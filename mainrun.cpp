//
// Created by xtx on 2021/8/11.
//
#include <iostream>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Player.h"

using namespace std;


int heroNum[3]={};

extern vector<Player*> playerList;//玩家对象表

void MainWindow::washCard() {
    int id=0;
    //构建排序用链表
    HandTmpListNode *tmpHead=new HandTmpListNode();
    HandTmpListNode *last=tmpHead;
    for(auto & i : allCardLib)
    {
        for(int j=0;j<i.num;j++)
        {
            HandTmpListNode *p=new HandTmpListNode(i.Species,i.name,id);
            last->next=p;
            last=p;
            id++;
        }
    }


    //此时完成了108张牌顺序链表的构建,开始抽排组成摸牌堆
    //构建摸牌堆链表

    for(int i=107;i>=0;i--)
    {
        HandTmpListNode *tmp=tmpHead;
        int getnum=rand()%(i+1);
        for(int j=0;j<=getnum;j++)
        {
            last=tmp;
            tmp=tmp->next;
        }
        HandHeap[107-i].Species=tmp->Species;
        HandHeap[107-i].name=tmp->name;
        HandHeap[107-i].id=tmp->id;

        //抽取完成,删除链表元素
        last->next=tmp->next;
        free(tmp);
    }
}

int MainWindow::chooseHero()//武将选择
{
    ui->card4->hide();

    heroNum[1]=47;
    QPixmap icon2(tr("resource/hero/47.png"));
    ui->card2->setIcon(icon2);


    heroNum[0] = (rand() % (403));
    if (heroNum[0] == 47)heroNum[0] = (rand() % (403));
    auto path = "resource/hero/" + to_string(heroNum[0]) + ".png";
    QPixmap icon1(tr(path.data()));
    ui->card1->setIcon(icon1);

    heroNum[2] = (rand() % (403));
    if (heroNum[2] == 47 || heroNum[0] == heroNum[2])heroNum[2] = (rand() % (403));
    path = "resource/hero/" + to_string(heroNum[2]) + ".png";
    QPixmap icon3(tr(path.data()));
    ui->card3->setIcon(icon3);



    connect(ui->card1,&QPushButton::clicked,this,[=]{
        ui->card1->setEnabled(false);
        showSkill(heroNum[0],ui->card1);
        cardChooseAnime(true,ui->card1);

        ui->card1->setEnabled(true);
    });
    connect(ui->card2,&QPushButton::clicked,this,[=]{
        ui->card2->setEnabled(false);
        showSkill(heroNum[1],ui->card2);
        cardChooseAnime(true,ui->card2);
        ui->card2->setEnabled(true);
    });
    connect(ui->card3,&QPushButton::clicked,this,[=]{
        ui->card3->setEnabled(false);
        showSkill(heroNum[2],ui->card3);
        cardChooseAnime(true,ui->card3);

        ui->card3->setEnabled(true);
    });
    mainState=choosingHero;
    connect(ui->Yes,SIGNAL(clicked()), this, SLOT(chooseFinish()));
    timerRun(choosingHeroTimer);
    return 0;
}

void MainWindow::chooseFinish(vector<int> a) {
    //遍历得到那张牌被举起
    ui->timeBar->hide();
    qtimer->stop();
    vector<int> upHand;//被选中的牌
    if(a.empty())
    {
        int tmp = 0;
        for (auto &i : HandCardGroup) {
            if (i->geometry().y() == 0) {
                upHand.push_back(tmp);

            }
            tmp++;
        }
    }
    else
    {
        upHand=a;
    }

    switch (mainState) {
        case choosingHero:
        {
            HeroNum=heroNum[upHand[0]];
            //初始化英雄
            //playerList[0].getHandEvent(1);
            finishHeroChoose();
        }
    }
}

void MainWindow::finishHeroChoose() {
    int rivalID=193;


    playerList.push_back(new Player(HeroNum,OneP));//-1因为hero组只有从第二个按钮开始的三个
    playerList.push_back(new Player(rivalID,TwoP));
    QString str;

    //原本应该再写一个函数来处理初始化的血量问题的,这里就算了

    for(int i=0;i<2;i++)
    {
        switch(playerList[i]->P) {
            case OneP:
                //playerList[i]->
                ui->HeroHead->setStyleSheet(str.sprintf("border-image: url(resource/hero/%d.png);",HeroNum));
                ui->four->hide();
                ui->five->hide();
                break;
            caseTwoP:
                ui->HeroHead_2->setStyleSheet(str.sprintf("border-image: url(resource/hero/%d.png);",rivalID));
                ui->five_2->hide();
                break;
        }
    }
    ui->HeroWeight1->show();
    ui->HeroWeight2->show();

    ui->card1->disconnect();
    ui->card2->disconnect();
    ui->card3->disconnect();

    //绘制vs的动画,并趁机释放qt进度系统
    ui->VS->show();
    QGraphicsOpacityEffect *pButtonOpacity = new QGraphicsOpacityEffect(this);
    pButtonOpacity->setOpacity(1);
    ui->VS->setGraphicsEffect(pButtonOpacity);
    QPropertyAnimation *pOpacityAnimation1 = new QPropertyAnimation(pButtonOpacity, "opacity");
    pOpacityAnimation1->setDuration(4000);
    pOpacityAnimation1->setStartValue(1);
    pOpacityAnimation1->setEndValue(0);
    animeGroup = new QParallelAnimationGroup(this);
    animeGroup->addAnimation(pOpacityAnimation1);
    connect(animeGroup, SIGNAL(finished()),this, SLOT(PrepareRoundOfGame()));
    animeGroup->start();

}

void MainWindow::PrepareRoundOfGame() {

}
