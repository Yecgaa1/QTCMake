// 手牌功能函数
// Created by xtx on 2021/8/26.
//

#include "mainwindow.h"
#include "value.h"
#include "iostream"
#include "Player.h"

using namespace std;
extern Player* playerList[2];//玩家对象表
int whichHandUsed;
PlayerID whoUse;//会被每次牌的使用而即时改变的变量
/// 手牌功能回调触发函数
/// \param PlayerID 使用手牌的玩家
/// \param HandsID 使用手牌在手牌堆的序号
/// \param handFunction 回调函数
void MainWindow::callHandFunction(PlayerID PlayerID,int HandsID,void (MainWindow::*handFunction)()) {
    whoUse=PlayerID;
    whichHandUsed=HandsID;
    (this->*handFunction)();
}
///杀的回调函数
void MainWindow::function_kill() {
    //原来应该有个选择的函数askChooseAnime,但是函数指针调用问题就弃了,git有记录
    ui->YesOrNo->hide();
    ui->tips->setText("选择要使用杀的对象");
    connect(ui->HeroBox_2, &QPushButton::clicked, this, [=] {
        ui->isHeroChoose_2->show();
        ui->YesOrNo->show();
        connect(ui->Yes, &QPushButton::clicked, this, [=] {
            ui->isHeroChoose_2->hide();
            playerList[TwoP]->bloodChangeEvent(1,player,whoUse);
            playerList[whoUse]->playerHandHeap.erase(playerList[whoUse]->playerHandHeap.begin()+whichHandUsed);
            playerList[whoUse]->useKillNum-=1;
            isInit=true;
            repaintHands();
            disconnectHands();
        });
    });
}
