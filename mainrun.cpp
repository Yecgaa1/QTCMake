//
// Created by xtx on 2021/8/11.
//
#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;



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


void MainWindow::run() {

}

int MainWindow::chooseHero()//武将选择
{
    ui->card1->hide();
    ui->card5->hide();


    heronum[1].id=47;
    QPixmap icon2(tr("resource/hero/47.png"));
    ui->card3->setIcon(icon2);


    heronum[0].id = (rand() % (403));
    if (heronum[0].id == 47)heronum[0].id = (rand() % (403));
    auto path = "resource/hero/" + to_string(heronum[0].id) + ".png";
    QPixmap icon1(tr(path.data()));
    ui->card2->setIcon(icon1);

    heronum[2].id = (rand() % (403));
    if (heronum[2].id == 47 || heronum[0].id == heronum[2].id)heronum[2].id = (rand() % (403));
    path = "resource/hero/" + to_string(heronum[2].id) + ".png";
    QPixmap icon3(tr(path.data()));
    ui->card4->setIcon(icon3);

    for(int i=1;i<4;i++)HandCardGroup[i]->setIconSize(QSize(250, 292));

    connect(ui->card2,&QPushButton::clicked,this,[=]{
        ui->card2->setEnabled(false);
        showSkill(heronum[0].id,ui->card2);
        cardChooseAnime(true,ui->card2);

        ui->card2->setEnabled(true);
    });
    connect(ui->card3,&QPushButton::clicked,this,[=]{
        ui->card3->setEnabled(false);
        showSkill(heronum[1].id,ui->card3);
        cardChooseAnime(true,ui->card3);
        ui->card3->setEnabled(true);
    });
    connect(ui->card4,&QPushButton::clicked,this,[=]{
        ui->card4->setEnabled(false);
        showSkill(heronum[2].id,ui->card4);
        cardChooseAnime(true,ui->card4);

        ui->card4->setEnabled(true);
    });
    mainState=choosingHero;
    connect(ui->Yes,SIGNAL(clicked()), this, SLOT(chooseFinish()));
    return 0;
}

void MainWindow::chooseFinish() {
    //遍历得到那张牌被举起
    vector<QPushButton*> upHand;//被选中的牌
    for (auto &i : HandCardGroup) {
        if (i->geometry().y() == 0) {
            upHand.push_back(i);
        }
    }

    switch (mainState) {
        case choosingHero:
        {
            //初始化英雄
            playerList.push_back(new Player(upHand[0].));
        }
    }
}
