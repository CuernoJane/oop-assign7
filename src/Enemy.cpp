#include "Enemy.h"

Enemy::Enemy(int _x, int _y) : GameObject(_x, _y){}

char Enemy::getSymbol() const{
    return 'E';
}

std::string Enemy::getType() const{
    return "Enemy";
}

bool Enemy::canMove() const{
    return true;
}

bool Enemy::canEat() const{
    return true;
}

bool Enemy::canBeEaten() const {
    return false;
}

void Enemy::moveTowardPlayer(int targetX, int targetY, const Map* map) {
    int dx = 0, dy = 0;

    if (targetX != getX()) {
        dx = (targetX > getX()) ? 1 : -1;
        int newX = getX() + dx;
        int newY = getY();

        if (!map->isBlocked(newX, newY)) {
            setPosition(newX, newY);
            return;
        }
    }

    // 垂直移動
    if (targetY != getY()) {
        dy = (targetY > getY()) ? 1 : -1;
        int newX = getX();
        int newY = getY() + dy;

        if (!map->isBlocked(newX, newY)) {
            setPosition(newX, newY);
        }
    }
    // 如果兩邊都擋住，就不移動
}
