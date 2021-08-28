//
// Created by xtx on 2021/8/26.
//

#include "mainwindow.h"
#include "value.h"
#include "iostream"
#include "Player.h"

using namespace std;
extern Player* playerList[2];//玩家对象表
PlayerID whoUse;//会被每次牌的使用而即时改变的变量

void MainWindow::callHandFunction(PlayerID PlayerID,void (MainWindow::*handFunction)()) {
    whoUse=PlayerID;
    (this->*handFunction)();
}

void MainWindow::function_kill() {
    //原来应该有个选择的函数askChooseAnime,但是函数指针调用问题就弃了,git有记录
    ui->YesOrNo->hide();
    ui->tips->setText("选择要使用杀的对象");
    connect(ui->HeroBox_2, &QPushButton::clicked, this, [=] {
        ui->isHeroChoose_2->show();
        ui->YesOrNo->show();
        connect(ui->Yes, &QPushButton::clicked, this, [=] {
            playerList[TwoP]->bloodChangeEvent(1,player,)
        });
    });
}
