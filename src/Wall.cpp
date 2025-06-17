#include "Wall.h"

Wall::Wall(int _x, int _y) : GameObject(_x, _y){}

char Wall::getSymbol() const{
    return '#';
}

string Wall::getType() const{
    return "Wall";
}

bool Wall::canMove() const{
    return false;
}

bool Wall::canEat() const{
    return false;
}

bool Wall::canBeEaten() const{
    return false;
}
