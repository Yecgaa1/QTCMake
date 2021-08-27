//
// Created by xtx on 2021/8/26.
//

#include "mainwindow.h"
#include "value.h"
#include "iostream"

using namespace std;

void MainWindow::callHandFunction(void (MainWindow::*handFunction)(int),int i) {
    (this->*handFunction)(i);
}

void MainWindow::function_kill(int i) {
    static int state=0;
    state++;
    switch(state)
    {
        case 1:
        {
            void (MainWindow::*f)(int);
            f=&MainWindow::function_kill;
            askChooseAnime((PlayerID)i,(*f)(i));
        }
        case 2:
        {

        }
    }
}
