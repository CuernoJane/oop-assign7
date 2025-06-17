#include "Treasure.h"

Treasure::Treasure(int _x, int _y) : GameObject(_x, _y){}

char Treasure::getSymbol() const{ 
    return '.'; 
}

string Treasure::getType() const{ 
    return "Treasure"; 
}

bool Treasure::canMove() const{ 
    return false; 
}

bool Treasure::canEat() const{ 
    return false; 
}

bool Treasure::canBeEaten() const{ 
    return true; 
}