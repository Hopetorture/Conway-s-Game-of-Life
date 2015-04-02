#include "mainwindow.h"
#include <QApplication>
#include "cell.h"
#include <QPainter>
#include <QPalette>
#include <QGridLayout>
#include"config.h"


#include <stdlib.h>     //for using the function sleep




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;



    w.show();


    return a.exec();
}
