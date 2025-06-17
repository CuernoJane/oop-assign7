#include "GameObject.h"

GameObject::GameObject(int _x, int _y) : x(_x), y(_y){}

int GameObject::getX() const{
    return x;
}

int GameObject::getY() const{
    return y;
}

void GameObject::setPosition(int _x, int _y){
    if(_x >= 0 && _y >= 0){
        x = _x;
        y = _y;
    }
}
