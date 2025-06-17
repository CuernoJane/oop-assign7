#pragma once
#include <vector>
#include "GameObject.h"
#include "Wall.h"
#include "Treasure.h"

using namespace std;


class View{
private:
    vector<GameObject*>& objects;
    int width;
    int height;
    

public:
    View(vector<GameObject*>& objs, int w, int h);
    ~View();

    vector<GameObject*>& getObjects();

    void addObject(GameObject* obj);
    void render() const;
    void buildWall();
    void fillWithTreasure();
};