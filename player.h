#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem> // Include QGraphicsPixmapItem
#include <QObject>
#include <QKeyEvent>

class Player: public QObject, public QGraphicsPixmapItem // Inherit from QObject and QGraphicsPixmapItem
{
    Q_OBJECT

signals:


public:
    Player();
    void keyPressEvent(QKeyEvent * event);


signals:



public slots:
    void createEnemy();


private:
};

#endif // PLAYER_H
