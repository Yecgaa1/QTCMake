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


int heroNum[3] = {};

extern Player *playerList[2];//玩家对象表

void MainWindow::washCard() {
    int id = 0;
    //构建排序用链表
    HandTmpListNode *tmpHead = new HandTmpListNode();
    HandTmpListNode *last = tmpHead;
    for (auto &i : allCardLib) {
        for (int j = 0; j < i.num; j++) {
            HandTmpListNode *p = new HandTmpListNode(i.Species, i.name, id);
            last->next = p;
            last = p;
            id++;
        }
    }


    //此时完成了108张牌顺序链表的构建,开始抽排组成摸牌堆
    //构建摸牌堆链表

    for (int i = 107; i >= 0; i--) {
        HandTmpListNode *tmp = tmpHead;
        int getnum = rand() % (i + 1);
        for (int j = 0; j <= getnum; j++) {
            last = tmp;
            tmp = tmp->next;
        }
        HandHeap[107 - i].Species = tmp->Species;
        HandHeap[107 - i].name = tmp->name;
        HandHeap[107 - i].id = tmp->id;

        //抽取完成,删除链表元素
        last->next = tmp->next;
        free(tmp);

        //补全可选信息
        switch (HandHeap[107 - i].Species) {

            case allKind:
                break;
            case kill:
                HandHeap[107 - i].isUseInPlayingRound = true;
                HandHeap[107 - i].handFunction=&MainWindow::function_kill;
                break;
            case flash:
                break;
            case peach:
                HandHeap[107 - i].isUseInPlayingRound = true;
                break;
            case impeccable:
                break;
            case outOfNothing:
                HandHeap[107 - i].isUseInPlayingRound = true;
                break;
            case demolitionOfTheBridgeAcrossTheRiver:
                HandHeap[107 - i].isUseInPlayingRound = true;
                break;
            case goHandInHand:
                HandHeap[107 - i].isUseInPlayingRound = true;
                break;
            case southernBarbarianInvasion:
                HandHeap[107 - i].isUseInPlayingRound = true;
                break;
            case allArrows:
                HandHeap[107 - i].isUseInPlayingRound = true;
                break;
            case harvest:
                break;
            case taoyuanEnding:
                break;
            case duel:
                break;
            case murderWithAKnife:
                break;
            case reluctantToThinkOfIt:
                break;
            case lightning:
                break;
            case zhugeLiannu:
                break;
            case frostArrow:
                break;
            case zhangBaSnakeSpear:
                break;
            case stoneAxe:
                break;
            case fangTianPaintedHalberd:
                break;
            case unicornBow:
                break;
            case gossipArray:
                break;
            case niohShield:
                break;
            case minusOneHorse:
                break;
            case addAHorse:
                break;
        }
    }
}

void MainWindow::chooseHero()//武将选择
{
    ui->card4->hide();

    heroNum[1] = 47;
    QString str;
//    QPixmap icon2(tr("resource/hero/47.png"));
    ui->card2->setStyleSheet(QStringLiteral("border-image: url(./resource/hero/47.png);"));


    heroNum[0] = (rand() % (403));
    if (heroNum[0] == 47)heroNum[0] = (rand() % (403));
    //auto path = "resource/hero/" + to_string(heroNum[0]) + ".png";
//    QPixmap icon1(tr(path.data()));
    ui->card1->setStyleSheet(str.sprintf("border-image: url(./resource/hero/%d.png);", heroNum[0]));

    heroNum[2] = (rand() % (403));
    if (heroNum[2] == 47 || heroNum[0] == heroNum[2])heroNum[2] = (rand() % (403));
//    path = "resource/hero/" + to_string(heroNum[2]) + ".png";
//    QPixmap icon3(tr(path.data()));
    ui->card3->setStyleSheet(str.sprintf("border-image: url(./resource/hero/%d.png);", heroNum[2]));


    connect(ui->card1, &QPushButton::clicked, this, [=] {
        ui->card1->setEnabled(false);
        showSkill(heroNum[0], ui->card1);
        cardChooseAnime(true, ui->card1);

        ui->card1->setEnabled(true);
    }, Qt::UniqueConnection);
    connect(ui->card2, &QPushButton::clicked, this, [=] {
        ui->card2->setEnabled(false);
        showSkill(heroNum[1], ui->card2);
        cardChooseAnime(true, ui->card2);
        ui->card2->setEnabled(true);
    }, Qt::UniqueConnection);
    connect(ui->card3, &QPushButton::clicked, this, [=] {
        ui->card3->setEnabled(false);
        showSkill(heroNum[2], ui->card3);
        cardChooseAnime(true, ui->card3);

        ui->card3->setEnabled(true);
    }, Qt::UniqueConnection);
    mainState = choosingHero;
    connect(ui->Yes, SIGNAL(clicked()), this, SLOT(chooseFinish()), Qt::UniqueConnection);
    timerRun(choosingHeroTimer);

}

void MainWindow::chooseFinish(vector<int> a) {
    //遍历得到那张牌被举起
    ui->timeBar->hide();
    qtimer->stop();
    vector<int> upHand;//被选中的牌
    if (a.empty()) {
        int tmp = 0;
        for (auto &i : HandCardGroup) {
            if (i->geometry().y() == 0) {
                upHand.push_back(tmp);

            }
            tmp++;
        }
    } else {
        upHand = a;
    }

    switch (mainState) {
        case choosingHero: {
            HeroNum = heroNum[upHand[0]];
            //初始化英雄
            //playerList[0].getHandEvent(1);
            finishHeroChoose();
        }
        case playing:
        {
            switch (gameInfo.nowRoundState)
            {
                case playStage:
                    callHandFunction(OneP,upHand[0],playerList[0]->playerHandHeap[upHand[0]].handFunction);
                    break;
                case foldPhase:
                    break;
                case endOfRound:
                    break;
            }
        }
    }
}

void MainWindow::finishHeroChoose() {
    int rivalID = 193;
    QString str;
    QLabel* blood1[5]={ui->one,ui->two,ui->three,ui->four,ui->five};
    QLabel* blood2[5]={ui->one_2,ui->two_2,ui->three_2,ui->four_2,ui->five_2};

    playerList[0] = new Player(47, OneP,blood1);//-1因为hero组只有从第二个按钮开始的三个
    playerList[1] = new Player(193, TwoP,blood2);

    //原本应该再写一个函数来处理初始化的血量问题的,这里就算了

    for (int i = 0; i < 2; i++) {
        switch (playerList[i]->P) {
            case OneP:
                //playerList[i]->
                ui->HeroHead->setStyleSheet(str.sprintf("border-image: url(resource/hero/%d.png);", HeroNum));
                ui->four->hide();
                ui->five->hide();
                break;
            case TwoP:
                ui->HeroHead_2->setStyleSheet(str.sprintf("border-image: url(resource/hero/%d.png);", rivalID));
                ui->five_2->hide();
                break;
        }
    }
    ui->HeroWeight1->show();
    ui->HeroWeight2->show();

    ui->card1->disconnect();
    ui->card2->disconnect();
    ui->card3->disconnect();

    width=200;
    height=290;

    mainState=playing;

    for (auto &i : HandCardGroup) {
        i->hide();
        i->setGeometry(QRect(0, 0, 200, 290));//重设大小
        i->setIconSize(QSize(200, 290));
        i->setStyleSheet("");
    }

    //绘制vs的动画,并趁机释放qt进度系统
    ui->VS->show();
    QGraphicsOpacityEffect *pButtonOpacity = new QGraphicsOpacityEffect(this);
    pButtonOpacity->setOpacity(1);
    ui->VS->setGraphicsEffect(pButtonOpacity);
    QPropertyAnimation *pOpacityAnimation1 = new QPropertyAnimation(pButtonOpacity, "opacity");
    pOpacityAnimation1->setDuration(100);
    pOpacityAnimation1->setStartValue(1);
    pOpacityAnimation1->setEndValue(0);
    animeGroup = new QParallelAnimationGroup(this);
    animeGroup->addAnimation(pOpacityAnimation1);
    animeGroup->start();
    connect(animeGroup, SIGNAL(finished()), this, SLOT(PrepareRoundOfGame()), Qt::UniqueConnection);
    return;
}

void MainWindow::PrepareRoundOfGame() {
    disconnect(animeGroup);
    ui->TestBox->show();
    connect(ui->testButton1, &QPushButton::clicked, this, [=] { playerList[1]->bloodChangeEvent(1); });
    playerList[0]->getHandEvent(4);
    playerList[1]->getHandEvent(4);

    //启动主状态机
    gameInfo.nowPlayerID = OneP;
    gameInfo.nowRoundState = startOfRound;
//    connect(MainStateTimer, &QTimer::timeout, this, [=]{
//        MainStateMachine();//多此亿举的lambda表达式,纯粹试试,不知道是否生效
//    });
    MainStateTimer->setSingleShot(true);//设置单次触发
    MainStateTimer->start(500);
    //isInit=false;//暂停状态机
    connect(MainStateTimer, SIGNAL(timeout()), this, SLOT(MainStateMachine()), Qt::UniqueConnection);
}

void MainWindow::MainStateMachine() {
    //灵感:写ACFly写多了
    //注意:阻塞性代码不可写在这里
    //由于此时定时器为单次触发,理论上进入该函数除非运行到最后不会重新绑定
    //MainStateTimer->stop();
    switch (gameInfo.nowPlayerID) {

        case OneP: {
            switch (gameInfo.nowRoundState) {

                case startOfRound:
                    if (isInit) {
                        isInit = false;
                        ui->info->setText("startOfRound");
                        playerList[0]->startOfRoundEvent(OneP);
                    }
                    break;
                case judgmentStage:
                    ui->info->setText("judgmentStage");
                    if (isInit) {
                        isInit = false;
                        playerList[0]->judgmentStageEvent(OneP);
                    }
                    break;
                case drawStage:
                    ui->info->setText("drawStage");
                    if (isInit) {
                        isInit = false;
                        playerList[0]->drawStageEvent(OneP);
                    }
                    break;
                case playStage:
                    ui->info->setText("playStage");
                    if (isInit) {
                        isInit = false;
                        ui->jump->show();
                        connect( ui->jump, &QPushButton::clicked, this, [=] {
                            isInit =true;
                            gameInfo.nowRoundState = foldPhase;
                            ui->jump->hide();
                        });
                        playerList[0]->playStageEvent(OneP);
                    }
                    break;
                case foldPhase:
                    ui->info->setText("foldPhase");
                    if (isInit) {
                        isInit = false;
                        playerList[0]->foldPhaseEvent(OneP);
                    }
                    break;
                case endOfRound:
                    ui->info->setText("endOfRound");
                    if (isInit) {
                        isInit = false;
                        playerList[0]->endOfRoundEvent(OneP);
                    }
                    break;
            }

            break;
        }
        case TwoP: {

            break;
        }
    }
    MainStateTimer->start();
}


