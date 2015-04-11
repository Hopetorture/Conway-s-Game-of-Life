#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"
#include<QGridLayout>
#include <QPalette>
#include <QColor>
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include <stdlib.h>     //for using the function sleep
#include "my_cell.h"
#include "config.h"



#include <QVector>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    //ui->setupUi(this);
    QGridLayout* gamefield = new QGridLayout();
    config *current=new config();

    QColor clr(255,255,255);
    QPalette qw(clr);
    QColor clr2(9,227,89);
    QPalette qw2(clr2);

    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {

            my_cell *mWidget= new my_cell(this);
            current->array[i][j]=mWidget;

            mWidget->setAutoFillBackground(1);
            if(i==0 || i==24 || j==24 || j==0)
            {
                mWidget->setVisible(false);

            gamefield->addWidget(mWidget,i,j);
            }
            else
            {

            mWidget->setPalette(qw);
            gamefield->addWidget(mWidget,i,j);

            }
        }
    }

    this->setWindowTitle("Life");

    QWidget* w = new QWidget(this);

    QPushButton *btn1=new QPushButton("GO");
    QPushButton *stahp=new QPushButton("STOP");
     QPushButton *clearz=new QPushButton("CLEAR");
    gamefield->addWidget(btn1,1,26);
   gamefield->addWidget(stahp,2,26);
   gamefield->addWidget(clearz,3,26);

    connect(btn1,SIGNAL(clicked()),current,SLOT(woohoo()));
    connect(stahp,SIGNAL(clicked()),current,SLOT(stop()));
      connect(clearz,SIGNAL(clicked()),current,SLOT(clear()));




    gamefield->setHorizontalSpacing(1);
     gamefield->setVerticalSpacing(1);
    w->setLayout(gamefield);
    this->setCentralWidget(w);
    w->setFixedHeight(600);
    w->setFixedWidth(600);
    w->setMaximumHeight(601);
     w->setMaximumWidth(601);
     this->setMaximumHeight(600);
     this->setMaximumHeight(600);







}

MainWindow::~MainWindow()
{
    delete ui;
}
