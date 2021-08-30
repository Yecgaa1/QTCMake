//
// Created by xtx on 2021/8/30.
//


#include "GuoJia.h"
extern bool GameOver;

/// 重写扣血函数,实现郭嘉技能 遗计
/// \param num 血量
/// \param sourceOfDamage 伤害来源
/// \param PlayerID 伤害来源玩家
void GuoJia::bloodChangeEvent(int num, sourceOfDamage sourceOfDamage, PlayerID PlayerID) {

    Player::bloodChangeEvent(num, sourceOfDamage, PlayerID);
    if(!GameOver&&num>0)
    {
        w.ui->tips->setText("是否发动技能 遗计 ?");
        w.ui->tips->show();
        w.ui->Yes->disconnect();
        MainWindow::connect(w.ui->Yes, &QPushButton::clicked, this, [=] {
            getHandEvent(2);
            MainWindow::connect(w.ui->Yes, &QPushButton::clicked, this, [=] {w.chooseFinish();});
            isInit=true;
        });
    }

}

