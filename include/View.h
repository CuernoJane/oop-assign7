#pragma once
#include <vector>
#include "GameObject.h"
#include "Wall.h"
#include "Treasure.h"

using namespace std;

// constexpr int MAX_WIDTH = 60;
// constexpr int MAX_HEIGHT = 10;

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