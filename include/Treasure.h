#pragma once
#include "GameObject.h"

class Treasure : public GameObject{
public:
    Treasure(int _x, int _y);

    char getSymbol() const override;
    string getType() const override;

    bool canMove() const override;
    bool canEat() const override;
    bool canBeEaten() const override;
};