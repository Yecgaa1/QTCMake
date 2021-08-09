#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
void MainWindow::Quit()
{
    m_group->start();
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(true);
    connect(ui->pushButton,SIGNAL(clicked()), this,SLOT(Quit()));
    QPropertyAnimation *pScaleAnimation1 = new QPropertyAnimation(ui->pushButton, "geometry");
    pScaleAnimation1->setDuration(1000);
    pScaleAnimation1->setStartValue(QRect(190, 230, 0, 0));
    pScaleAnimation1->setEndValue(QRect(120, 160, 140, 140));
    m_group=new QParallelAnimationGroup(this);
    m_group->addAnimation(pScaleAnimation1);



}

MainWindow::~MainWindow()
{
    delete ui;
}

