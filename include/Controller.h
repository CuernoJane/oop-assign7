
#pragma once

#include "Player.h"
#include "View.h"
#include "Map.h"

class Controller{
private:
    Player* player;
    View* view;
    Map* map;
    char direction;
    bool running;
    std::vector<GameObject*>& objects;
    char getInputIfAny();

public:

    Controller(Player* p, View* v, Map* m);
    void run();
};