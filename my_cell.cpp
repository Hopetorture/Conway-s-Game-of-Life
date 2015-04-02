#include "my_cell.h"
#include <QMouseEvent>
#include <QPalette>
#include <QColor>

my_cell::my_cell(QWidget *parent) : QWidget(parent)
{

state=0;


}

my_cell::~my_cell()
{
delete this;
}

void my_cell::mousePressEvent(QMouseEvent *event)
{

    QColor green(9,227,89);
    QPalette green_p(green);
    QColor white(255,255,255);
    QPalette white_p(white);

    Qt::MouseButtons mButtons=event->buttons();
    if(mButtons==Qt::LeftButton)
    {

        if (this->state==0){
            this->state=1;
        this->setPalette(green_p);
          }

        else
           {
            if(this->state==1)
        this->setPalette(white_p);
            this->state=0;
        }
    }


}

