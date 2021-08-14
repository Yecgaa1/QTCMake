//
// Created by xtx on 2021/8/12.
//

#include <iostream>
#include <QPropertyAnimation>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

void MainWindow::cardChooseAnime(bool single,QPushButton* a,...) {
    //cout<<a->geometry().y();
    //此时如果是50就是下方,0就是上方
    int y=a->geometry().y();
    bool isTop= y != 50;

//    va_list ap;
//    va_start(ap, a);
//    QPushButton* i;//遍历
    animeGroup=new QParallelAnimationGroup(this);
//    while(true) {
//        i=va_arg( ap, QPushButton*);
//        cout<<i;
//        if(i==ui->testButton)break;

        auto *pScaleAnimation1 = new QPropertyAnimation(a, "geometry");//geometry大小位置，pos角度，透明度后面说，见https://blog.csdn.net/weixin_42347660/article/details/113314656
        pScaleAnimation1->setDuration(100);//时间
        if(isTop)
        {

            pScaleAnimation1->setStartValue(QRect(a->geometry().x(), 0, 250, 292));//初状态
            pScaleAnimation1->setEndValue(QRect(a->geometry().x(), 50, 250, 292));//末状态
        }
        else
        {
            pScaleAnimation1->setStartValue(QRect(a->geometry().x(), 50, 250, 292));//初状态
            pScaleAnimation1->setEndValue(QRect(a->geometry().x(), 0, 250, 292));//末状态
        }
        animeGroup->addAnimation(pScaleAnimation1);

//   }
    animeGroup->start();
}