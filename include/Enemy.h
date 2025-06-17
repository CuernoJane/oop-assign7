#pragma once
#include "GameObject.h"
#include "Map.h"

class Enemy :public GameObject{
public:
    Enemy(int _x, int _y);
    
    char getSymbol() const override;
    std::string getType() const override;

    bool canMove() const override;
    bool canEat() const override;
    bool canBeEaten() const override;

    void moveTowardPlayer(int targetX, int targetY, const Map* map);
};