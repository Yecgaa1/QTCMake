#include "mainwindow.h"


#include <QApplication>
#include "main.h"
//#include "Player.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

using namespace std;

extern Player* playerList[2];

int argc;
char *argv[]={};
QApplication a(argc, argv);
MainWindow w;

int main(int argc, char *argv[])
{

    w.show();
    return a.exec();
}

void run()
{
    //playerList.push_back(new Player(w.HeroId));

}




#pragma clang diagnostic pop