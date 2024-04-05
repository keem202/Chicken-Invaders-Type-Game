#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "player.h" // Include the header file for Player class
#include "enemy.h" // Include the header file for Enemy class
#include "bullet.h" // Include the header file for Bullet class

int score = 0; // Global score variable
int health = 3; // Global health variable

// Function prototypes
void decrease(QGraphicsScene *scene, QGraphicsTextItem *healthText);
void increase(QGraphicsScene *scene, QGraphicsTextItem *scoreText);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Create the View
    QGraphicsView view;
    view.setFixedSize(800, 600);

    // Create the Scene
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);
    view.setScene(&scene);
    view.show();

    // Create and add Score Text Item
    QGraphicsTextItem *scoreText = new QGraphicsTextItem();
    scoreText->setFont(QFont("times", 16));
    scoreText->setDefaultTextColor(Qt::blue);
    scoreText->setPlainText("Score: " + QString::number(score));
    scoreText->setPos(700, 10);
    scene.addItem(scoreText);

    // Create and add Health Text Item
    QGraphicsTextItem *healthText = new QGraphicsTextItem();
    healthText->setFont(QFont("times", 16));
    healthText->setDefaultTextColor(Qt::red);
    healthText->setPlainText("Health: " + QString::number(health));
    healthText->setPos(10, 10);
    scene.addItem(healthText);

    // Create the Player
    Player *player = new Player();
    scene.addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos((view.width() - player->pixmap().width()) / 2,
                   view.height() - player->pixmap().height());

    // Create the Enemies automatically
    QTimer *enemyTimer = new QTimer();
    QObject::connect(enemyTimer, SIGNAL(timeout()), player, SLOT(createEnemy()));
    enemyTimer->start(2000);

    // Create the Bullets automatically
    QTimer *bulletTimer = new QTimer();
    QObject::connect(bulletTimer, SIGNAL(timeout()), player, SLOT(shoot()));
    bulletTimer->start(500);

    return a.exec();
}

void decrease(QGraphicsScene *scene, QGraphicsTextItem *healthText) {
    health--;
    healthText->setPlainText("Health: " + QString::number(health));
    if (health < 1) {
        // Game over
        QGraphicsTextItem *gameOverText = new QGraphicsTextItem();
        gameOverText->setFont(QFont("times", 24));
        gameOverText->setDefaultTextColor(Qt::red);
        gameOverText->setPlainText("Game Over! Score: " + QString::number(score));
        gameOverText->setPos(300, 300);
        scene->addItem(gameOverText);
    }
}

void increase(QGraphicsScene *scene, QGraphicsTextItem *scoreText) {
    score++;
    scoreText->setPlainText("Score: " + QString::number(score));
}

