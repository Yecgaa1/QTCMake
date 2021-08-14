//
// Created by xtx on 2021/8/12.
//

#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

void MainWindow::clear()
{

}

void MainWindow::ShowSkill(int i) {
    if(ui->YesOrNo->isHidden()) {    //未来可以改用文本库的形式
        if (i == 47)
            ui->tips->setText("郭嘉   魏   3血\n"
                              "天妒\t当你的判定牌生效后，你可以获得此牌。\n"
                              "遗计\t当你受到1点伤害后，你可以观看牌堆顶的两张牌，然后交给任意名角色。");
        else ui->tips->setText("");
        ui->YesOrNo->show();
        ui->tips->show();
    }
    else {
        ui->YesOrNo->hide();
        ui->tips->hide();
    }
}
