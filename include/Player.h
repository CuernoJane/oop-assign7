#pragma once
#include "GameObject.h"

class Player : public GameObject{
public:
    Player(int _x, int _y);

    char getSymbol() const override;
    string getType() const override;

    bool canMove() const override;
    bool canEat() const override;
    bool canBeEaten() const override;

    void move(int dx, int dy);
};
