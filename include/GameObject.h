#pragma once
#include <string>
using namespace std;

class GameObject{
protected:
    int x, y;
public:
    GameObject(int _x, int _y);
    virtual ~GameObject() = default;

    virtual char getSymbol() const = 0;
    virtual string getType() const = 0;

    virtual bool canMove() const = 0;
    virtual bool canEat() const = 0;
    virtual bool canBeEaten() const = 0;

    int getX() const;
    int getY() const;

    void setPosition(int _x, int _y);
};
