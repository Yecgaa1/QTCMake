//
// Created by xtx on 2021/8/12.
//

#include <iostream>
#include <QPropertyAnimation>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

extern vector<Player*> playerList;//玩家对象表

void MainWindow::cardAllDown() {
    for (auto &i : HandCardGroup) {
        if (i->geometry().y() == 0) {
            auto *pScaleAnimation1 = new QPropertyAnimation(i, "geometry");
            pScaleAnimation1->setStartValue(QRect(i->geometry().x(), 0, 250, 292));//初状态
            pScaleAnimation1->setEndValue(QRect(i->geometry().x(), 50, 250, 292));//末状态
            animeGroup->addAnimation(pScaleAnimation1);
        }
    }

}
void MainWindow::cardChooseAnime(bool single, QPushButton *a, ...) {
    //cout<<a->geometry().y();
    //此时如果是50就是下方,0就是上方
    animeGroup = new QParallelAnimationGroup(this);
    if (single)cardAllDown();
//    va_list ap;
//    va_start(ap, a);
//    QPushButton* i;//遍历

//    while(true) {
//        i=va_arg( ap, QPushButton*);
//        cout<<i;
//        if(i==ui->testButton)break;
    cardUpDown(single,a);


//   }
    animeGroup->start();
}

void MainWindow::cardUpDown(bool single, QPushButton *a) {
    int y = a->geometry().y();
    bool isTop = y != 50;
    auto *pScaleAnimation1 = new QPropertyAnimation(a,"geometry");//geometry大小位置，pos角度，透明度后面说，见https://blog.csdn.net/weixin_42347660/article/details/113314656
    pScaleAnimation1->setDuration(100);//时间
    if (isTop&&!single) {

        pScaleAnimation1->setStartValue(QRect(a->geometry().x(), 0, 250, 292));//初状态
        pScaleAnimation1->setEndValue(QRect(a->geometry().x(), 50, 250, 292));//末状态
    } else {
        pScaleAnimation1->setStartValue(QRect(a->geometry().x(), 50, 250, 292));//初状态
        pScaleAnimation1->setEndValue(QRect(a->geometry().x(), 0, 250, 292));//末状态
    }
    animeGroup->addAnimation(pScaleAnimation1);
}

void MainWindow::askChoose(int num,tipsType tipsType,cardSpecies cardSpecies) {
    QString str;
    if(tipsType==giveUp)
        ui->tips->setText(str.sprintf("请弃置%d张牌",num));
}

void MainWindow::timerRun(timerType type,int sec) {
    timeRound=sec*10;
    this->timerNowType=type;
    timerWork();
    ui->timeBar->show();
    connect(qtimer, SIGNAL(timeout()), this, SLOT(timeout()));
}

void MainWindow::timerWork() {
    qtimer->start(timeRound);
    ui->timeBar->setValue(100);
    timerTemp=100;
}

void MainWindow::timeout() {
    timerTemp--;
    ui->timeBar->setValue(timerTemp);
    if (timerTemp == 0) {
        qtimer->stop();
        //到这一步证明用户没有选择,超时处理代码
        switch(this->timerNowType)
        {
            case choosingHeroTimer: {
                vector<int> a = {1};
                chooseFinish(a);
                break;
            }
            case choosingHandTimer:
                break;
        }


    }
}

void MainWindow::repaintHands() {
    for(int i=0;i<playerList[0]->playerHandHeap->size;i++)
    {
        playerList[0]->playerHandHeap
    }
}
