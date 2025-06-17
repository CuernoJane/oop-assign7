#include "Player.h"

Player::Player(int _x, int _y) : GameObject(_x, _y){}

char Player::getSymbol() const{
    return '@';
}

string Player::getType() const{
    return "Player";
}

bool Player::canMove() const{
    return true;
}

bool Player::canEat() const{
    return true;
}

bool Player::canBeEaten() const{
    return true;
}

void Player::move(int dx, int dy){
    setPosition(getX() + dx, getY() + dy);
}
