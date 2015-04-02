/*
#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QWidget>
#include <Qcolor>
#include <QVector>
class cell : public QWidget
{
    bool state;
    QColor AliveColor;
    QVector<cell> near;
    Q_OBJECT
public:
    void set_green();
    void set_black();
    void set_state(bool new_state);
    void add_near(QVector<cell> neigbours);
    void add_near(cell q);
    explicit cell(QWidget *parent = 0);
    ~cell();

signals:

public slots:
};

#endif // CELL_H

*/
