#ifndef CONFIG_H
#define CONFIG_H
#include "my_cell.h"



class config : public QObject
{
 Q_OBJECT
public:
    bool crutches;
    config();    
    ~config();
   my_cell *array[25][25];
   bool next[25][25];
public slots:
   void woohoo();
   void stop();
};

#endif // CONFIG_H
