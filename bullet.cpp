#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QPixmap> // Include QPixmap to load images
#include "enemy.h" // Include the Enemy header file

Bullet::Bullet(QObject *parent) : QObject(parent), QGraphicsPixmapItem() {
    // Set the pixmap of the bullet to the red laser image
    setPixmap(QPixmap(":/new/prefix1/red_laser.png").scaled(10, 50)); // Adjust the size as needed

    // Generate the bullets automatically
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50); // Adjust the interval as needed
}

void Bullet::move() {
    // Get the colliding items with the bullet from the scene
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);

    // Iterate through the list of colliding items
    for (int i = 0; i < collidingItems.size(); ++i) {
        // Check if the current colliding item is an enemy
        if (typeid(*(collidingItems[i])) == typeid(Enemy)) {

            // Remove both the enemy and the bullet from the scene
            scene()->removeItem(collidingItems[i]);
            scene()->removeItem(this);

            // Delete the bullet object later in a safe context
            QTimer::singleShot(0, this, &QObject::deleteLater);
            return;
        }
    }

    // Move the bullet upwards
    setPos(x(), y() - 10);

    // Remove the bullet from the scene if it goes out of bounds
    if (pos().y() + pixmap().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
