#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QPixmap>
#include <QDebug> // Include qDebug for debugging purposes

Enemy::Enemy() {
    QPixmap pixmap(":/new/prefix1/Daco_5027525.png");
    if (pixmap.isNull()) {
        qDebug() << "Failed to load enemy image.";
    } else {
        // Set the pixmap of the enemy to the loaded image
        setPixmap(pixmap.scaled(50, 50)); // Adjust the size as needed

        // Setting the initial position of the enemy within the view dimensions
        int random_number = rand() % 700; // Adjust the range according to your scene dimensions
        setPos(random_number, 0);

        // Moving the enemies downwards automatically every 50 milliseconds
        QTimer *timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(50); // Adjust the interval as needed
    }
}

void Enemy::move() {
    // Move the enemy downwards
    setPos(x(), y() + 5); // Adjust the speed of movement as needed

    if (scene()) {
        // If the enemy goes out of bounds, remove it from the scene
        if (y() + pixmap().height() > scene()->height()) {
            scene()->removeItem(this);
            delete this;
        }
    }
}


