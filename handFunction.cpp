//
// Created by xtx on 2021/8/26.
//

#include "mainwindow.h"
#include "value.h"
#include "iostream"

using namespace std;

void MainWindow::callHandFunction(void (MainWindow::*handFunction)()) {
    (this->*handFunction)();
}

void MainWindow::function_kill() {
    cout<<123;
}
