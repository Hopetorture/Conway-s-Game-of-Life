#include "config.h"
#include <QtTest/QTest>
#include <QTime>
#include <QDebug>

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}


config::config()
{
for(int i=0;i<25;i++)

{
    for(int j=0;j<25;j++)
    {
        next[i][j]=0;
    }
}
}

config::~config()
{
delete [] &array;
}

void config::woohoo()
{
    crutches=1;
    int count=0;
while(crutches==1)
{
    //crutches=0;
    QColor clr2(9,227,89);
    QPalette green(clr2);
    QColor wht(255,255,255);
    QPalette white(wht);
    QColor dbg(0,68,255);
    QPalette debug(dbg);
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
//            array[i][j]->setPalette(debug);
//            delay(200);
            for(int n=0;n<8;n++)
            {
                if(i==0 || i==24 || j==24 || j==0) //I messed with it
                  {
                      if(i==0&&j==0)
                      {
                          if(array[i+1][j]->state==1)
                             {count++;
                             }
                          if(array[i][j+1]->state==1)
                              count++;
                          if(array[i+1][j+1]->state==1)
                              count++;
                      }//top left
                      if(i==0&&j==24)
                      {
                          if(array[i+1][j]->state==1)
                              count++;
                          if(array[i+1][j-1]->state==1)
                              count++;
                          if(array[i][j-1]->state==1)
                              count++;
                      }//top right
                      if(i==0&&j>0&&j<24)
                      {
                          if(array[i][j-1]->state==1)
                              count++;
                          if(array[i][j+1]->state==1)
                              count++;
                          if(array[i+1][j-1]->state==1)
                              count++;
                          if(array[i+1][j]->state==1)
                              count++;
                          if(array[i+1][j+1]->state==1)
                              count++;


                      }//top row logic

                  if(i==24&&j==0)
                  {
                      if(array[i][j+1]->state==1)
                          count++;
                      if(array[i-1][j]->state==1)
                          count++;
                      if(array[i-1][j+1]->state==1)
                          count++;
                  }//bottom left
                  if(i==24&&j==24)
                  {
                      if(array[i][j-1]->state==1)
                          count++;
                      if(array[i-1][j]->state==1)
                          count++;
                      if(array[i-1][j-1]->state==1)
                          count++;
                  }//bottom right
                  if(i>0&&i<24&&j==0)
                  {
                      if(array[i][j+1]->state==1)
                          count++;
                      if(array[i-1][j+1]->state==1)
                          count++;
                      if(array[i-1][j]->state==1)
                          count++;
                      if(array[i+1][j]->state==1)
                          count++;
                      if(array[i+1][j+1]->state==1)
                          count++;
                  }//left row

                  if(j==24&&i!=0&&i!=24)
                  {
                      if(array[i][j-1]->state==1)
                          count++;
                      if(array[i-1][j-1]->state==1)
                          count++;
                      if(array[i-1][j]->state==1)
                          count++;
                      if(array[i+1][j]->state==1)
                          count++;
                      if(array[i+1][j-1]->state==1)
                          count++;
                  }//right row

                  if(i==24&&j!=0&&j!=24)
                  {
                      if(array[i][j-1]->state==1)
                          count++;
                      if(array[i][j+1]->state==1)
                          count++;
                      if(array[i-1][j-1]->state==1)
                          count++;
                      if(array[i-1][j]->state==1)
                          count++;
                      if(array[i-1][j+1]->state==1)
                          count++;



                  }//bottom row logic



            }
                 else{



                if(array[i-1][j-1]->state==true)
                    count++;
                if(array[i-1][j]->state==true)
                    count++;
                if(array[i-1][j+1]->state==true)
                    count++;
                if(array[i][j-1]->state==true)
                    count++;
                if(array[i][j+1]->state==true)
                    count++;
                if(array[i+1][j-1]->state==true)
                    count++;
                if(array[i+1][j]->state==true)
                    count++;
                if(array[i+1][j+1]->state==true)
                    count++;

                }//end else
                if(array[i][j]->state==1)
                   { if(count<2||count>3)
                        next[i][j]=0;
                    else
                        next[i][j]=1;
                   }//if state==1
                if(array[i][j]->state==0)
                   {
                    if(count==3)
                        next[i][j]=1;
                    else
                        next[i][j]=0;
                   }
//qDebug()<<count;


              count=0;
            }//end neighborhood cycle





        }//END J
    }// end for i
    //QTest::qWait(5000);
  // delay(800);
  for(int i=0;i<25;i++)
  {
      for(int j=0;j<25;j++)
      {
         if (next[i][j]==1)
         {
             //invisible borders logic
             if(j==24)
             {
                 array[i][j]->state=0;
                 array[i][1]->state=1;                 
                 array[i][1]->setPalette(green);
                 //qDebug()<<"123";
             }
            // if(j==56)
                 //qDebug()<<"control is fool";
             if(j==0)
             {
                 // THIS IS NOT WORKING AS INTENDED, DEBUGGING/FIXING REQUIRED.
                 //qDebug()<<"control passed here";
                 array[i][j]->state=0;
                 array[i][22]->state=1;
                 //array[13][13]->setPalette(green);
                 array[i][22]->setPalette(green);
             }
             if(i==24)
             {
                 array[i][j]->state=0;
                 array[1][j]->state=1;
                 array[1][j]->setPalette(green);
             }//bottom row tor
             if(i==0)
             {
              array[i][j]->state=0;
              array[23][j]->state=1;
              array[23][j]->setPalette(green);
             }//top row tor

             // invisible border logic end.

             array[i][j]->state=1;
             array[i][j]->setPalette(green);

         }
         else
         {
             array[i][j]->state=0;
             array[i][j]->setPalette(white);
         }
      }

  }//end for ( repaint cycle)
delay(800);
}//end while
}


void config::stop()
{
    crutches=0;
}

