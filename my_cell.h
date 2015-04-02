#ifndef MY_CELL_H
#define MY_CELL_H

#include <QObject>
#include <QWidget>


class my_cell : public QWidget
{
    Q_OBJECT
public:
    bool state;
    explicit my_cell(QWidget *parent = 0);
    ~my_cell();

signals:

public slots:
protected:
     void mousePressEvent(QMouseEvent *event);
private:
     void update_color();
};

#endif // MY_CELL_H
