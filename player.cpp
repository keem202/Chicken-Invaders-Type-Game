#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QPixmap> // Include QPixmap to load images
#include "enemy.h"
#include <QMessageBox>
#include <QFont>


Player::Player() {

    // Set the pixmap of the player to the ship image
    setPixmap(QPixmap(":/new/prefix1/ship.png").scaled(100, 100)); // Adjust the size as needed
}

void Player::keyPressEvent(QKeyEvent *event) {
    // Event Handling for the Player
    if (event->key() == Qt::Key_Left) {
        if (x() > 0) {
            setPos(x() - 10, y());
        }
    } else if (event->key() == Qt::Key_Right) {
        if (x() + 100 < 800) {
            setPos(x() + 10, y());
        }
    } else if (event->key() == Qt::Key_Space) {
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + 30, y());
        scene()->addItem(bullet);


    }
}

void Player::createEnemy() {
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}

